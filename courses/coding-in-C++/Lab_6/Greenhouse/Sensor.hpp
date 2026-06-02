#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <string>

class Sensor {
    private:
        std::string name;
        double value;
        const double min_value;
        const double max_value;

    public:
        Sensor(std::string name, double min_value, double max_value);

        void updateValue(double value);

        double getValue() {
            return this->value;
        }

        void printInfo() const;

};

#endif