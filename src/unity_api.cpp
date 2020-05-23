#include <stdexcept>
#include "unity_api.h"
#include "unity_method_definitions.h"

namespace unity_api
{
    SimRobotUnityAPI *SimRobotUnityAPI::instance = nullptr;

    SimRobotUnityAPI::SimRobotUnityAPI() = default;

    SimRobotUnityAPI *SimRobotUnityAPI::GetInstance()
    {
        if (instance == nullptr)
            instance = new SimRobotUnityAPI();
        return instance;
    }

    SimRobotUnityAPI::~SimRobotUnityAPI()
    {
    }

    void SimRobotUnityAPI::RegisterMotor(shared_api::Motor *motor)
    {
        if (added_motor_index >= MAX_MOTORS - 1)
            throw std::runtime_error("Cannot add more than MAX_MOTORS defined in unity_api.cpp");
        motors[added_motor_index] = motor;
        added_motor_index++;
    }

    shared_api::Motor *SimRobotUnityAPI::GetMotor(int port)
    {
        if (port >= MAX_MOTORS + 1)
            throw std::runtime_error("Cannot get more than MAX_MOTORS defined in unity_api.cpp");
        for (int i = 0; i < MAX_MOTORS; i++)
        {
            if (motors[i]->port == port)
                return motors[i];
        }
        return nullptr;
    }
}



