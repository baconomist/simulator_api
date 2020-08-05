//
// Created by Lucas on 2020-05-22.
//


#include <simulator/device_registry.h>
#include <simulator/devices/devices.h>
#include <pros/motors.hpp>

#include "simulator_globals.h"
#include "unity_api/param_handler.h"

using namespace simulator;

namespace pros
{
    pros::Motor::Motor(std::uint8_t port) : _port(port)
    {
        // Allocate to HEAP via a pointer, this way it will stay "in-scope" and not be auto-destroyed via stack allocation
        SimMotor* simMotor = new SimMotor(_port);
        register_device(simMotor);
    }

    pros::Motor::Motor(std::uint8_t port, const motor_gearset_e_t gearset, const bool reverse,
                       const motor_encoder_units_e_t encoder_units) : _port(port)
    {

    }

    pros::Motor::Motor(std::uint8_t port, const motor_gearset_e_t gearset, const bool reverse) : _port(port)
    {

    }

    pros::Motor::Motor(std::uint8_t port, const motor_gearset_e_t gearset) : _port(port)
    {

    }

    pros::Motor::Motor(std::uint8_t port, const bool reverse) : _port(port)
    {

    }

    std::int32_t pros::Motor::get_voltage() const
    {
        return get_device<SimMotor>(_port)->voltage;
    }


    std::int32_t pros::Motor::operator=(std::int32_t voltage) const
    {
        return 0;
    }

    std::int32_t pros::Motor::move(std::int32_t voltage) const
    {
        return 0;
    }

    std::int32_t pros::Motor::move_absolute(const double position, std::int32_t velocity) const
    {
        return 0;
    }

    std::int32_t pros::Motor::move_relative(const double position, std::int32_t velocity) const
    {
        return 0;
    }

    std::int32_t pros::Motor::move_velocity(std::int32_t velocity) const
    {
        return 0;
    }

    std::int32_t pros::Motor::move_voltage(std::int32_t voltage) const
    {
        SimMotor* simMotor = get_device<SimMotor>(_port);
        simMotor->voltage = voltage;
        return 0;
    }

    std::int32_t pros::Motor::modify_profiled_velocity(std::int32_t velocity) const
    {
        return 0;
    }

    double pros::Motor::get_target_position(void) const
    {
        return 0;
    }

    std::int32_t pros::Motor::get_target_velocity(void) const
    {
        return 0;
    }

    double pros::Motor::get_actual_velocity(void) const
    {
        return 0;
    }

    std::int32_t pros::Motor::get_current_draw(void) const
    {
        return 0;
    }

    std::int32_t pros::Motor::get_direction(void) const
    {
        return 0;
    }

    double pros::Motor::get_efficiency(void) const
    {
        return 0;
    }

    std::int32_t pros::Motor::is_over_current(void) const
    {
        return 0;
    }

    std::int32_t pros::Motor::is_stopped(void) const
    {
        return 0;
    }

    std::int32_t pros::Motor::get_zero_position_flag(void) const
    {
        return 0;
    }

    std::uint32_t pros::Motor::get_faults(void) const
    {
        return 0;
    }

    std::uint32_t pros::Motor::get_flags(void) const
    {
        return 0;
    }

    std::int32_t pros::Motor::get_raw_position(std::uint32_t *const timestamp) const
    {
        return 0;
    }

    std::int32_t pros::Motor::is_over_temp(void) const
    {
        return 0;
    }

    double pros::Motor::get_position(void) const
    {
        return 0;
    }

    double pros::Motor::get_power(void) const
    {
        return 0;
    }

    double pros::Motor::get_temperature(void) const
    {
        return 0;
    }

    double pros::Motor::get_torque(void) const
    {
        return 0;
    }

    std::int32_t pros::Motor::set_zero_position(const double position) const
    {
        return 0;
    }

    std::int32_t pros::Motor::tare_position(void) const
    {
        return 0;
    }

    std::int32_t pros::Motor::set_brake_mode(const motor_brake_mode_e_t mode) const
    {
        return 0;
    }

    std::int32_t pros::Motor::set_current_limit(std::int32_t limit) const
    {
        return 0;
    }

    std::int32_t pros::Motor::set_encoder_units(const motor_encoder_units_e_t units) const
    {
        return 0;
    }

    std::int32_t pros::Motor::set_gearing(const motor_gearset_e_t gearset) const
    {
        return 0;
    }

    motor_pid_s_t pros::Motor::convert_pid(double kf, double kp, double ki, double kd)
    {
        return motor_pid_s_t{(uint8_t) kf, (uint8_t) kp, (uint8_t) ki, (uint8_t) kd};
    }

    motor_pid_full_s_t
    pros::Motor::convert_pid_full(double kf, double kp, double ki, double kd, double filter, double limit,
                                  double threshold, double loopspeed)
    {
        return motor_pid_full_s_t{(uint8_t) kf, (uint8_t) kp, (uint8_t) ki, (uint8_t) kd, (uint8_t) filter,
                                  (uint8_t) limit, (uint8_t) threshold, (uint8_t) loopspeed};
    }

    std::int32_t pros::Motor::set_pos_pid(const motor_pid_s_t pid) const
    {
        return 0;
    }

    std::int32_t pros::Motor::set_pos_pid_full(const motor_pid_full_s_t pid) const
    {
        return 0;
    }

    std::int32_t pros::Motor::set_vel_pid(const motor_pid_s_t pid) const
    {
        return 0;
    }

    std::int32_t pros::Motor::set_vel_pid_full(const motor_pid_full_s_t pid) const
    {
        return 0;
    }

    std::int32_t pros::Motor::set_reversed(const bool reverse) const
    {
        return 0;
    }

    std::int32_t pros::Motor::set_voltage_limit(std::int32_t limit) const
    {
        return 0;
    }

    motor_brake_mode_e_t pros::Motor::get_brake_mode(void) const
    {
        return motor_brake_mode_e_t{};
    }

    std::int32_t pros::Motor::get_current_limit(void) const
    {
        return 0;
    }

    motor_encoder_units_e_t pros::Motor::get_encoder_units(void) const
    {
        return motor_encoder_units_e_t{};
    }

    motor_gearset_e_t pros::Motor::get_gearing(void) const
    {
        return motor_gearset_e_t{};
    }

    motor_pid_full_s_t pros::Motor::get_pos_pid(void) const
    {
        return motor_pid_full_s_t{};
    }

    motor_pid_full_s_t pros::Motor::get_vel_pid(void) const
    {
        return motor_pid_full_s_t{};
    }

    std::int32_t pros::Motor::is_reversed(void) const
    {
        return 0;
    }

    std::int32_t pros::Motor::get_voltage_limit(void) const
    {
        return 0;
    }

    std::uint8_t pros::Motor::get_port(void) const
    {
        return 0;
    }
}

