#include <iostream>
#include <string>
#include <map>

class Base {
protected:
    std::map<std::string, size_t> base;

public:
    void addProduct (const std::string& article, size_t quantity) {
        base[article] += quantity;
    }

    void showProduct () const {
        for (const auto& [article, quantity] : base)
            std::cout << "Article: " << article << " - quantity: " << quantity << std::endl;
    }
};

class BaseStore : public Base {
public:
    void checkArticleAndQuantity (const std::string& article, size_t quantity) {
        if (!base.count(article) || base[article] < quantity)
            throw "std::invalid_argument";
    }

    void getNumProducts (const std::string& article, size_t num) {
        if (!base.count(article) || base[article] < num)
            return;
        base[article] -= num;
    }
};

class ChoppingBasket : public Base {
public:
    void remove (const std::string& article, size_t num) {
        if (!base.count(article) || base[article] < num)
            throw "std::runtime_error";
        else
            base[article] -= num;
    }
};

const std::string& promptingAndReceivingInput(const std::string& phrase1, const std::string& conjun, const std::string& phrase2)
{
    std::cout << "Enter " << phrase1 << " " << conjun << " " << phrase2 << " (\"q\" for exit)" << std::endl;
    static std::string cmd;
    std::cin >> cmd;
    return cmd;
}

int main ()
{
    BaseStore baseStore;
    size_t quantity;
    std::cout << "Fill in the store's product database" << std::endl;
    std::string articleOrCmd = promptingAndReceivingInput("article", "and", "quantity");
    while (articleOrCmd != "q") {
        std::cin >> quantity;
        baseStore.addProduct(articleOrCmd, quantity);
        articleOrCmd = promptingAndReceivingInput("article", "and", "quantity");
    }
    std::cout << "The store database is full" << std::endl;
    baseStore.showProduct();
    std::cout << std::endl;

    ChoppingBasket choppingBasket;
    std::string cmd, article;
    std::cout << "Fill shopping cart with products" << std::endl;
    do {
        cmd = promptingAndReceivingInput("\"add\"", "or", "\"remove\"");
        if (cmd == "add" || cmd == "remove") {
            std::cout << "Enter article and quantity " << std::endl;
            std::cin >> article >> quantity;
            if (cmd == "add") {
                try {
                    baseStore.checkArticleAndQuantity(article, quantity);
                }
                catch (const std::exception& x) {
                    std::cerr << "Error: " << x.what() << std::endl;
                }
                baseStore.getNumProducts(article, quantity);
                choppingBasket.addProduct(article, quantity);
            } else if (cmd == "remove") {
                try {
                    choppingBasket.remove(article, quantity);
                }
                catch (const std::exception& x) {
                    std::cerr << "Error: " << x.what() << std::endl;
                }
            }
        }
    } while (cmd != "q");

    return 0;
}
