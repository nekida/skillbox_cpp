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

class Order {
    std::string nameOfDish;

    int num = 0;

public:
    Order(std::string name, int num) : nameOfDish(name), num(num) { }

    std::string& getName() { return nameOfDish; }

    size_t getNum() { return num; }

    bool isOrdering = false;

    bool isCooking = false;

    bool isDelivering = false;
};

int getRandomInRange (const int min, const int max)
{
    srand(time(NULL));
    return min + (rand() % (max - min + 1));
}

void deliveryOrder (Order& order)
{
    while (!order.isCooking)
        ;
    deliveringMtx.lock();
    std::this_thread::sleep_for(std::chrono::seconds(30));
    std::cout << "Заказ номер " << order.getNum() << " " << order.getName() << " доставлен" << std::endl;
    deliveringMtx.unlock();
}

void cookingOrder (Order& order)
{
    while (!order.isOrdering)
        ;
    std::this_thread::sleep_for(std::chrono::seconds(getRandomInRange(5, 15)));
    std::cout << "Заказ номер " << order.getNum() << " " << order.getName() << " приготовлен" << std::endl;
    cookingMtx.lock();
    order.isCooking = true;
    cookingMtx.unlock();
}

void onlineOrder (Order& order)
{
    std::this_thread::sleep_for(std::chrono::seconds(getRandomInRange(5, 10)));
    std::cout << "Заказ номер " << order.getNum() << " " << order.getName() << " оформлен" << std::endl;
    orderingMtx.lock();
    order.isOrdering = true;
    orderingMtx.unlock();
}

int main ()
{
    setlocale(LC_ALL, "Russian");
    const std::string dish[] = {"пицца", "суп", "стейк", "салат", "суши"};
    int numOrders = 1;
    while (numOrders < 11) {
        Order order(dish[getRandomInRange(0, 4)], numOrders);
        std::thread online(onlineOrder, std::ref(order));
        std::thread cooking(cookingOrder, std::ref(order));
        std::thread delivering(deliveryOrder, std::ref(order));
        online.join();
        cooking.detach();
        delivering.join();
        numOrders++;
    }

    return 0;
}
