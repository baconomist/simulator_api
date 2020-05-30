//
// Created by Lucas on 2020-05-29.
//

#include "shared_robot_api.hpp"

namespace shared_api::adi
{
    ADISensor::ADISensor(ADI_PORT port, ADI_MODE adiMode)
    {
        this->port = port;
        this->adiMode = adiMode;
    }

    AnalogSensor::AnalogSensor(ADI_PORT port) : ADISensor(port, ADI_MODE::ANALOG_IN)
    {

    }

    std::int32_t AnalogSensor::get_value() const {
        std::string str((const char *) this->port);
        shared_api::logging::info("AAAAAAAAAA" + str);
        shared_api::logging::info("BBBBBBB");
        return 50;
    }

}