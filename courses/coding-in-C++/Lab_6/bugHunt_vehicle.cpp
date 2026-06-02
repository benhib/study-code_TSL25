#include "bugHunt_vehicle.hpp"
//indirect includes

Vehicle::Vehicle(const std::string &vehicle_model, double max_speed)
    : model(vehicle_model),
      speed_kmh(0.0),
      max_speed_kmh(max_speed),
      steering_angle(0.0),
      lane_offset_m(0.0),
      brake_light_on(false)
{}

void Vehicle::accelerate(double amount_kmh){
    if(amount_kmh <= 0.0)
    {
        std::cout << "Acceleration amount must be positive.\n";
        return;
    }

    if(speed_kmh + amount_kmh > max_speed_kmh)
    {
        std::cout << "Cannot accelerate beyond max speed of " << max_speed_kmh << " km/h.\n";
        speed_kmh = max_speed_kmh;
        return;
    }
       

    speed_kmh += amount_kmh;

    brake_light_on = false;
}

void Vehicle::brake(double amount_kmh)
{
    if (amount_kmh <= 0.0)
    {
        std::cout << "Braking amount must be positive.\n";
        return;
    }

    speed_kmh -= amount_kmh;
    brake_light_on = true;

    if (speed_kmh < 0.0)
    {
        speed_kmh = 0.0;
    }
}

void Vehicle::steer(double angle) {
    steering_angle += angle;
}

void Vehicle::update_lane_offset(double offset) {
    lane_offset_m = offset;
}

double Vehicle::get_speed() const
{
    return speed_kmh;
}

double Vehicle::get_steering_angle() const
{
    return steering_angle;
}

double Vehicle::get_lane_offset() const
{
    return lane_offset_m;
}

const std::string &Vehicle::get_model() const
{
    return model;
}

bool Vehicle::is_brake_light_on() const
{
    return brake_light_on;
}

void Vehicle::print_status() const
{
    std::cout << "Vehicle: " << model << '\n';
    std::cout << "Speed: " << speed_kmh << " km/h\n";
    std::cout << "Max Speed: " << max_speed_kmh << " km/h\n";
    std::cout << "Steering angle: " << steering_angle << " degrees\n";
    std::cout << "Lane offset: " << lane_offset_m << " m\n";
    std::cout << "Brake light: " << std::boolalpha << brake_light_on << "\n\n";
}