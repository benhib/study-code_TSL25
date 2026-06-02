#ifndef ASSISTANCE_SYSTEM_HPP
#define ASSISTANCE_SYSTEM_HPP


#include <string>
#include <vector>
#include <memory>

#include "bugHunt_vehicle.hpp"

class AssistanceFeature {
    

    public:
        virtual void evaluate(Vehicle &Vehicle) = 0;
        virtual void print_name() = 0;
        virtual ~AssistanceFeature() = default;
};

class DistanceSensor
{
private:
    std::string position;
    bool active;
    double measured_distance_m;
public:

    DistanceSensor(const std::string &sensor_position, double initial_distance_m) : 
      position(sensor_position),
      active(true), 
      measured_distance_m(initial_distance_m) {}

    void set_distance(double distance_m);
    void activate();
    void deactivate();

    double get_distance() const;
    bool is_active() const;
    std::string get_position() const;

    void print_info() const;
};

class EmergencyBrakeSystem : public AssistanceFeature
{
private:
    double critical_distance_m;
    std::shared_ptr<DistanceSensor> sensor;

public:
    EmergencyBrakeSystem(double critical_distance, std::shared_ptr<DistanceSensor> front_sensor)
        : critical_distance_m(critical_distance), sensor(front_sensor), AssistanceFeature() {}

    void evaluate(Vehicle &vehicle) override;
    void print_name() override;
};

class LaneKeepingAssist : public AssistanceFeature
{
private:
    double max_allowed_offset_m;
    double correction_angle;

public:
    LaneKeepingAssist(double max_offset,
                                     double correction)
    : max_allowed_offset_m(max_offset),
      correction_angle(correction), AssistanceFeature()
{
}

    void evaluate(Vehicle &vehicle) override;
    void print_name() override;
};

class AdaptiveCruiseControl : public AssistanceFeature
{
private:
    double target_speed_kmh;
    double minimum_distance_m;
    std::shared_ptr<DistanceSensor> sensor;


public:
    AdaptiveCruiseControl(double target_speed, double minimum_distance, std::shared_ptr<DistanceSensor> front_sensor)
    : target_speed_kmh(target_speed),
      minimum_distance_m(minimum_distance), sensor(front_sensor), AssistanceFeature() {}

    void evaluate(Vehicle &vehicle) override;
    void print_name() override;
};

class ParkingAssistant : public AssistanceFeature {
private:
    std::vector<std::unique_ptr<DistanceSensor>> other_sensors;
    std::shared_ptr<DistanceSensor> front;
    double warning_distance_m;

public:

    ParkingAssistant(double warning_distance)
    : warning_distance_m(warning_distance), AssistanceFeature() {}

    void add_sensor(std::unique_ptr<DistanceSensor> sensor);
    void add_front_sensor(std::shared_ptr<DistanceSensor> front_sensor);
    void print_warnings() const;

    void evaluate(Vehicle &vehicle) override;
    void print_name() override;
};

#endif