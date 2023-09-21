#include <iostream>
#include <vector>
#include <string>
#include <map>

class BaseStore {
    std::map<std::string, size_t> base;

public:
    bool checkArticleAndQuantity (const std::string& article, size_t quantity) {
        if (base.count(article) && base[article] >= quantity)
            return true;
        return false;
    }

    void getNumProducts (const std::string& article, size_t num) {
        if (!base.count(article) || base[article] < num)
            return;
        base[article] -= num;
    }

    void addProduct (const std::string& article, size_t quantity) {
        base[article] += quantity;
    }

    void showProduct () const {
        for (const auto& [article, quantity] : base)
            std::cout << "Article: " << article << " - quantity: " << quantity << std::endl;
    }
};

class ChoppingBasket {
    std::map<std::string, size_t> basket;

public:
    void add (const std::string& article, size_t quantity) {
        basket[article] += quantity;
    }

    void remove (const std::string& article, size_t num) {
        if (!basket.count(article) || basket[article] < num)
            return;
        basket[article] -= num;
    }
};

int main ()
{
    BaseStore baseStore;
    std::string cmd = "w";
    std::cout << "Enter article and quantity (\"q\" for exit)" << std::endl;
    std::cin >> cmd;
    while (cmd != "q") {
        size_t quantity;
        std::cin >> quantity;
        baseStore.addProduct(cmd, quantity);
        std::cout << "Enter article and quantity (\"q\" for exit)" << std::endl;
        std::cin >> cmd;
    }
    std::cout << "The store database is full" << std::endl;
    baseStore.showProduct();
    std::cout << std::endl;

    return 0;
}
