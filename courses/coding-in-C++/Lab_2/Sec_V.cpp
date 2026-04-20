#include <iostream>
#include <string>
#include <iomanip>
using namespace std; //never use using

class Article { //deconstructor missing
public:
    // public 
    string name;
    double price;
    int stock;
    string* category; //why pointer
    int id; //missing check

    Article(string name, double price, int stock, string category, int id) {
        name = name; // name conflict -> initialize with Article (): name(name), ... {}
        price = price; // same here
        stock = stock; // same here
        this->id = id;
        this->category = new string; 
        *this->category = category; //dereferencing the wrong object (needs to be this->category* = category;)
    }

    void setPrice(double price) { //parameter check missing
        price = price; // name error use tihs->price = price;
    }

    void sell(int amount) { //parameter check missing
        stock = stock - amount; //incosistent with restock, also use this for more safety
        }

    void restock(int amount) { //parameter check missing
        this->stock += amount;
    }

    double applyDiscount(double percent) { //this edits the price of the object but should just return the value (use const and just return) also parameter check
        price = price - price * percent / 100;
        return price; 
    }

    double getPrice() { //const missing
        return price; //use this->
    }

    bool isAvailable() { //no braces in if + const missing
        if (stock > 0) //use this
            return true; // just use return stock > 0
        else
            return false;
    }

    void printInfo() { //define out of class
        cout << "Article: " << name << endl;
        cout << "Category: " << *category << endl;
        cout << "Price: " << price << endl;
        cout << "Stock: " << stock << endl;
        cout << "ID: " << id << endl;
    }
};

int main() {
    Article a("Laptop", 999.99, 10, "Electronics", 101);

    a.sell(15); //invalid with parameter check
    a.restock(-5); // with parameter check invalid
    a.price = -100; // never change directly
    a.applyDiscount(150); //invalid with parameter check

    if (a.isAvailable()) cout << "Article available" << endl; //braces

    a.printInfo();
}