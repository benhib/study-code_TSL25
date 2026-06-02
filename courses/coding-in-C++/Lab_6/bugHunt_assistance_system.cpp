#include "bugHunt_assistance_system.hpp"
#include <iostream>
#include <string>
#include <vector>



void DistanceSensor::set_distance(double distance_m) {
    measured_distance_m = distance_m;
}

void DistanceSensor::activate() {
    active = true;
}

void DistanceSensor::deactivate() {
    active = false;
}

double DistanceSensor::get_distance() const {
    return measured_distance_m;
}

bool DistanceSensor::is_active() const {
    return active;
}

std::string DistanceSensor::get_position() const {
    return position;
}

void DistanceSensor::print_info() const {
    std::cout << "Sensor position: " << position << '\n';
    std::cout << "Distance: " << measured_distance_m << " m\n";
    std::cout << "Active: " << std::boolalpha << active << "\n\n";
}


void EmergencyBrakeSystem::evaluate(Vehicle &vehicle) override {
    if (!sensor->is_active()) {
        std::cout << "[WARNING] Front Sensor is defektive. EmergencyBrakeSystem compromised\n";
        return;
    }

    if (sensor->get_distance() < critical_distance_m) {
        std::cout << "[EmergencyBrakeSystem] Emergency braking triggered.\n";
        vehicle.brake(30.0); // only breaks 30 kmh not until stop
    }
}

void EmergencyBrakeSystem::print_name() override {
    std::cout << "EmergencyBrakeSystem" << std::endl; 
}


void LaneKeepingAssist::evaluate(Vehicle &vehicle) override {
    double offset = vehicle.get_lane_offset();

    if (offset > max_allowed_offset_m) {
        std::cout << "[LaneKeepingAssist] Correcting to the left.\n";
        vehicle.steer(-correction_angle);
    }
    else if (offset < -max_allowed_offset_m) {
        std::cout << "[LaneKeepingAssist] Correcting to the right.\n";
        vehicle.steer(correction_angle);
    }
}

void LaneKeepingAssist::print_name() override {
    std::cout << "LaneKeepingAssist" << std::endl;
}


void AdaptiveCruiseControl::evaluate(Vehicle &vehicle) override {
    if (!sensor->is_active()){
        std::cout << "[WARNING] Front Sensor is defektive. AdaptiveCruiseControl compromised\n";
        return;
    }
    
    if (sensor->get_distance() < minimum_distance_m) {
        std::cout << "[AdaptiveCruiseControl] Vehicle ahead is close. Braking.\n";
        vehicle.brake(5.0);
    }
    else if (vehicle.get_speed() < target_speed_kmh) {
        std::cout << "[AdaptiveCruiseControl] Increasing speed.\n";
        vehicle.accelerate(5.0);
    }
    else if (vehicle.get_speed() > target_speed_kmh) {
        std::cout << "[AdaptiveCruiseControl] Reducing speed.\n";
        vehicle.brake(5.0);
    }
}



void ParkingAssistant::add_sensor(std::unique_ptr<DistanceSensor> sensor) {
    other_sensors.push_back(std::move(sensor));
}

void ParkingAssistant::add_front_sensor(std::shared_ptr<DistanceSensor> front_sensor){
    front = front_sensor;
}

void ParkingAssistant::print_name() override {
    std::cout << "ParkingAssistant" << std::endl;
}

void ParkingAssistant::print_warnings() const
{
    for (const auto &sensor : other_sensors)
    {
        // no error handling! at least a warning
        if (sensor != nullptr && sensor->is_active()) {
            if (sensor->get_distance() < warning_distance_m) {
            std::cout << "[ParkingAssistant] Warning at "
                      << sensor->get_position()
                      << ": obstacle detected.\n";
            }
        } else {
            std::cout << "[WARNING] " << sensor->get_position() << " Sensor is defektive. ParkingAssistant compromised\n";
        }
    }

    if (front != nullptr && front->is_active()) {
        if (front->get_distance() < warning_distance_m) {
            std::cout << "[ParkingAssistant] Warning at front: obstacle detected.\n";
        }
    } else {
        std::cout << "[WARNING] Front Sensor is defektive. ParkingAssistant compromised\n";
    }
}