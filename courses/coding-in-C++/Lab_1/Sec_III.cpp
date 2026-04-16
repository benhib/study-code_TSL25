#include <string>
#include <iostream>
#include <cstdint>
#include <limits>

namespace validation {

    bool isAdult(uint8_t age) {
        return age >= 18;
    }

    bool isSenior(uint8_t age) {
        return age >= 65;
    }
}

int main() {

    bool is_entered = false;
    uint16_t age = 0;

    while(!is_entered) {
        std::cout << "Please enter your age: \n";
        if (!(std::cin >> age)) {
            std::cout << "You did not enter a vakid number. Please try again.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
            continue;
        }
        is_entered = true;
    }

    std::cout << "You are " << age << " years old.\n";

    if (validation::isSenior(static_cast<uint8_t> (age))) {
        std::cout << "That means you are a senior citizen.\n";
    } else if (validation::isAdult(static_cast<uint8_t> (age))) {
        std::cout << "That means you are an adult.\n";
    } else {
        std::cout << "That means that you are still a kid or a teenager.\n";
    }

}

/*
When using uint8_t with cin, it only gets the first character of the input and stores the ASCII value.

It would make more sense to use a uint16_t or larger in order to get every character out of the input and not just the first one.
*/