#include <locale.h>
#include <iostream>
#include <string>
#include <thread>
#include <ctime>
#include <vector>
#include <mutex>

std::mutex cookingMtx;
std::mutex orderingMtx;
std::mutex deliveringMtx;

struct Order {
    size_t num;
    std::string name;
    bool isOrdering;
    bool isCooking;
};

std::vector<Order> orders;

std::string dish[] = {"пицца", "суп", "стейк", "салат", "суши"};

int orderDelivedNum = 0;

int getRandomInRange (const int min, const int max)
{
    srand(time(NULL));
    return min + (rand() % (max - min + 1));
}

void deliveryOrder ()
{
    deliveringMtx.lock();
    std::this_thread::sleep_for(std::chrono::seconds(30));
    while (orders.empty() || !orders.front().isCooking)
        ;
    std::cout << "Заказ номер " << orders.front().num << " " << orders.front().name << " доставлен" << std::endl;
    orders.erase(orders.begin());
    orderDelivedNum++;
    deliveringMtx.unlock();
}

void cookingOrder ()
{
    cookingMtx.lock();
    std::this_thread::sleep_for(std::chrono::seconds(getRandomInRange(5, 15)));
    while (orders.empty() || !orders.front().isOrdering || orders.front().isCooking)
        ;
    std::cout << "Заказ номер " << orders.front().num << " " << orders.front().name << " приготовлен" << std::endl;
    orders.front().isCooking = true;
    cookingMtx.unlock();
}

void onlineOrder (size_t numOrder)
{
    orderingMtx.lock();
    std::this_thread::sleep_for(std::chrono::seconds(getRandomInRange(5, 10)));
    orders.push_back({numOrder, dish[getRandomInRange(0, 4)], true, false});
    std::cout << "Заказ номер " << orders.back().num << " " << orders.back().name << " оформлен" << std::endl;
    orderingMtx.unlock();
}

int main ()
{
    setlocale(LC_ALL, "Russian");
        
    for (int numOrders = 1; numOrders < 11; ++numOrders) {
        std::thread online(onlineOrder, numOrders);
        online.join();
        std::thread cooking(cookingOrder);
        cooking.detach();
        std::thread delivering(deliveryOrder);
        delivering.detach();
    }

    while (orderDelivedNum != 10)
        ;

    return 0;
}
