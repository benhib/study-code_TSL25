#include <string>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include "Sensor.hpp"

Sensor::Sensor(std::string name, double min_value, double max_value) : name(name), value(min_value), min_value(min_value), max_value(max_value) {
    if(min_value >= max_value) {
        throw std::invalid_argument("min_value is larger than max_value");
    }
};
void Sensor::updateValue(double value) {
    if(value > this->max_value || value < this->min_value) {
        throw std::out_of_range("Sensor value is out of range");
    }
    this->value = value;
};

void Sensor::printInfo() const {
    std::setfill("-");
    std::cout << std::setw(20) << std::endl;
    std::cout << "Name: " << this->name << std::endl;
    std::cout << "Value: " << this->value << std::endl;
    std::cout << "Min: " << this->min_value << std::endl;
    std::cout << "Max: " << this->max_value << std::endl;
    std::cout << std::setw(20) << std::endl;
}
