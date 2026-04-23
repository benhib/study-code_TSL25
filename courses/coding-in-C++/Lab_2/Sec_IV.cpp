#include <string>
#include <iostream>



class DrinkBuilder {
    private:
        std::string name;
        int sugar;
        int temperature;
        bool withMilk;
        static constexpr int MAX_SUGAR = 10;
        static constexpr int MINIMUM_SUGAR = 0;
        static constexpr int MINIMUM_TEMP = 0;
        static constexpr int MAXIMUM_TEMP = 60;

    public:
        DrinkBuilder& setName (const std::string& name) {
            this->name = name;
            return *this;
        }

        DrinkBuilder& setSugar (const int& sugar);

        DrinkBuilder& setTemperature (const int& temperature);
        DrinkBuilder& setWithMilk (const bool& withMilk) {
            this->withMilk = withMilk;
            return *this;
        }

        void const print();

        bool constexpr isValid() {return true;}

        DrinkBuilder() : name(""), sugar(MAX_SUGAR), temperature(MINIMUM_TEMP), withMilk(false) {}
};

DrinkBuilder& DrinkBuilder::setSugar (const int& sugar) {
    if (sugar > this->sugar) {
        std::cout << "Too mouch sugar! Way to sweet!\n";
    } else if (sugar < MINIMUM_SUGAR) {
        std::cout << "There is no anit sugar!\n";
        this->sugar = MINIMUM_SUGAR;
    } else {
        this->sugar = sugar;
    }
    return *this;
}

DrinkBuilder& DrinkBuilder::setTemperature (const int& temperature) {
    if (temperature < this->temperature) {
        std::cout << "Too cold, you'll get frostbite!\n";
    } else if (temperature > MAXIMUM_TEMP) {
        std::cout << "Too hot, you'll burn yourself!\n";
        this->temperature = MAXIMUM_TEMP;
    } else {
        this->temperature = temperature;
    }
    return *this;
}

void const DrinkBuilder::print() {
    using namespace std;

    cout << "Drink: " << this->name << endl;
    cout << "Sugar: " << this->sugar << endl;
    cout << "Temperature: " << this->temperature << endl;
    cout << "With milk: " << this->withMilk << endl;
}

int main() {
    DrinkBuilder builder;
    builder.setName("Kaffee").setSugar(12).setTemperature(70).setWithMilk(true).print(); 
}

