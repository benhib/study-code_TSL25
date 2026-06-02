#include <iostream>

constexpr float ALARM_TEMP = 30.0f;

class Display
{
public:
    void show_temperature(float value)
    {
        std::cout << "Display: " << value << " C\n";
    }
};

class Logger
{
public:
    void log_temperature(float value)
    {
        std::cout << "Logger: " << value << " C\n";
    }
};

class Alarm {
    public:
    void alarm_for_temp(float value) {
        if(value > ALARM_TEMP) {
            std::cout << "Alarm! Temp is larger than 30°C\n";
        }
    }
};

class TemperatureSensor
{
private:
    float temperature = 0.0f;

    Display display;
    Logger logger;
    Alarm alarm;

public:
    void set_temperature(float value)
    {
        temperature = value;

        // directly coupled to other classes
        display.show_temperature(temperature);
        logger.log_temperature(temperature);
        alarm.alarm_for_temp(temperature);

        //not possible to add cloud without changing Sensor code
    }
};

int main()
{
    TemperatureSensor sensor;

    sensor.set_temperature(23.5f);

    return 0;
}