#include <iostream>
#include "Sensor.hpp"

int main() {

    Sensor hum_sensor = Sensor("Humidity", 0, 1); //Percentage
    Sensor temp_sensor = Sensor("Temperature", -273.15, 1.417e32); //Degree Celcius, Absolute Zero, Plank Temp


    try {
        
        Sensor inv_sensor = Sensor("Invalid", -1.5, 0.0);

        /*
        hum_sensor.updateValue(1.2);
        hum_sensor.updateValue(-0.1);
        temp_sensor.updateValue(-300);
        temp_sensor.updateValue(1.5e32);
        */
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}