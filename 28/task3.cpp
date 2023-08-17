#include <iostream>
#include <string>
#include <thread>
#include <ctime>
#include <vector>
#include <mutex>

std::mutex isCookingCompleted;

class Kitchen {
public:
};

class Order {
    std::string name;

public:
    Order(std::string name, int num) : name(name), num(num) { }

    std::string& getName() { return name; }

    int num = 0;

    bool isCookingCompleted = false;
};

int getRandomInRange (const int min, const int max)
{
    return min + (rand() % (max - min + 1));
}

void delivery (Order& order)
{
    while(!isCookingCompleted)
        ;
    std::cout << "Order number " << order.num << " " << order.getName() << " in delivery being processed" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(30));
}

void cooking (Order& order)
{
    std::cout << "Cooking order number " << order.num << " " << order.getName() << " has begun" << std::endl;
    isCookingCompleted.lock();
    std::this_thread::sleep_for(std::chrono::seconds(getRandomInRange(5, 15)));
    std::cout << "Cooking order number " << order.num << " " << order.getName() << " finished" << std::endl;
    order.isCookingCompleted = true;
    isCookingCompleted.unlock();
}

void onlineOrder (Order& order)
{
    std::cout << "Order number " << order.num << " " << order.getName() << " being processed" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(getRandomInRange(5, 10)));
    std::cout << "Order number " << order.num << " " << order.getName() << " is accepted" << std::endl;
}

int main ()
{
    const std::string menu[] = {"pizza", "soup", "steak", "salad", "sushi"};
    int numOrders = 1;
    while (numOrders != 10) {
        Order order(menu[getRandomInRange(0, 4)], numOrders);
        std::thread online(onlineOrder, std::ref(order));
        online.join();
        std::thread cook(cooking, std::ref(order));
        cook.detach();
        std::thread deliv(delivery, std::ref(order));
        deliv.join();
        numOrders++;
    }

    return 0;
}
