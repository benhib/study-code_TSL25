#include <iostream>
#include <string>
#include <iomanip>


class Article {
private:
    std::string name;
    double price;
    int stock;
    std::string category;
    int id; 

public:
    Article(std::string name, double price, int stock, std::string category, int id) : name(name), price(price), stock(stock), category(category), id(id) {};

    void setPrice(double price);

    void sell(int amount);

    void restock(int amount);

    void applyDiscount(double percent) { 
        if (percent < 0 || percent > 100) {        
            this->price = this->price - this->price * percent / 100;
        }
    }

    double const getPrice() { 
        return this->price; 
    }

    bool const isAvailable() { 
        return stock > 0;
    }

    void const printInfo();
};

void Article::setPrice(double price) {
    if (price < 0) {
        std::cout << "Price can't be negative\n";
    } else { 
    this->price = price;
    std::cout << "Set price of " << this->name << "to " << this->price << "€\n";
    }
}
void Article::sell(int amount) {
    if (amount < 0) {
        std::cout << "You can't sell a negative amount\n";
    } else if (amount > this->stock) {
        std::cout << "You can't sell more than you own\n";
    } else {
        this->stock -= amount;
        std::cout << "Sold " << amount << " " << this->name << "\n";
    }
}

void Article::restock(int amount) {
    if (amount < 0) {
        std::cout << "You can't restoc a negative amount\n";
    } else {
        this->stock +=amount;
        std::cout << "Restocked " << amount << " " << this->name << "\n";
    }
}

void const Article::printInfo() { 
    using namespace std;
    cout << "Article: " << name << std::endl;
    cout << "Category: " << category << std::endl;
    cout << "Price: " << price << std::endl;
    cout << "Stock: " << stock << std::endl;
    cout << "ID: " << id << std::endl;
}



int main() {
    Article article1("Laptop", 999.99, 10, "Electronics", 101);

    article1.sell(15); 
    article1.restock(-5); 
    article1.setPrice(-100); 
    article1.applyDiscount(150); 

    article1.sell(9); 
    article1.restock(5); 
    article1.setPrice(500); 
    article1.applyDiscount(90.02);

    if (article1.isAvailable()) {
        std::cout << "Article available" << std::endl; 
    }
    article1.printInfo();
}