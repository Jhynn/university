#include <string>
#include <iostream>

typedef std::string String;

class Product {
private:
    String name;
    double price;
    int    quantity;
public:
    Product() {
        name     = "";
        price    = 0.;
        quantity = 0;
    }

    Product(String name, double price, int quantity) {
        this->name     = name;
        this->price    = price;
        this->quantity = quantity;
    }

    void
    setName(String name) {
        this->name = name;
    }

    void
    setPrice(double price) {
        this->price = price;
    }

    void
    setQuantity(int quantity) {
        this->quantity = quantity;
    }

    String
    getName() {
        return name;
    }

    double
    getPrice() {
        return price;
    }

    int
    getQuantity() {
        return quantity;
    }

    double
    toPay() {
        if (0 < quantity && quantity < 10)
            return price * quantity;
        else if (11 < quantity && quantity < 21)
            return price * quantity / 10 / 100;
        else if (21 < quantity && quantity < 50)
            return price * quantity / 20 / 100;
        else 
            return price * quantity / 25 / 100;
    }

    void
    show() {
        std::cout << "Nome........: " <<   name   << std::endl;
        std::cout << "Preço.......: " <<   price  << std::endl;
        std::cout << "Quantity....: " << quantity << std::endl;
        std::cout << "Com desconto: " << toPay()  << std::endl;
    }
};
