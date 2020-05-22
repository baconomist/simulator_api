#include "unity_api.h"
#include "unity_method_definitions.h"
#include <stdexcept>

namespace unity_api
{
    SIM_ROBOT_API SimRobotUnityAPI *GetSharedRobotAPI()
    {
        return SimRobotUnityAPI::GetInstance();
    }

    SIM_ROBOT_API void DeleteSharedRobotAPI(SimRobotUnityAPI *api)
    {
        delete api;
    }

    SIM_ROBOT_API int GetVoltage(SimRobotUnityAPI *api, int port)
    {
        return api->GetMotor(port)->voltage;
    }

    SIM_ROBOT_API int Test()
    {
        return 69;
    }

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
        motors[added_motor_index] = motor;
        if(added_motor_index >= MAX_MOTORS - 1)
            throw std::runtime_error("Cannot add more than MAX_MOTORS defined in unity_api.cpp");
        added_motor_index++;
    }

    shared_api::Motor* SimRobotUnityAPI::GetMotor(int port)
    {
        if(port >= MAX_MOTORS + 1)
            throw std::runtime_error("Cannot get more than MAX_MOTORS defined in unity_api.cpp");
        for(int i = 0; i < MAX_MOTORS; i++)
        {
            if(motors[i]->port == port)
                return motors[i];
        }
        return nullptr;
    }
}
