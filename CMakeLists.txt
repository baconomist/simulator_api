# !!!!!!!!!! IMPORTANT !!!!!!!!!!
# MAKE SURE YOU HAVE CLION > 2019.3
# https://blog.jetbrains.com/clion/2019/10/clion-2019-3-eap-ninja-cmake-generators/
# FOR COMPILING .DLL ON FOR WINDOWS
# Set cmake options in clion->settings->build,execution,deployment->cmake "-G "Visual Studio 15 2017 Win64""
# This way cmake will use the visual studio generator to build the project
# ON WINDOWS, I ALSO DOWNLOADED CMAKE FROM cmake.com, I'm not sure if its required, but...
message("Generator is set to ${CMAKE_GENERATOR}")

set(VERSION "2.8.4") # Create var "VERSION"

# Disable sh.exe mingw error
set(DCMAKE_SH="CMAKE_SH-NOTFOUND")

# Export all methods?
# set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

cmake_minimum_required(VERSION ${VERSION})
project(SimulatorAPI CXX)

include_directories("src")
file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c" "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

# Enable DLL build w/ option() and SHARED flag in add_library()
include_directories(SimulatorAPI "${CMAKE_CURRENT_SOURCE_DIR}/../shared_api/include")
add_library(SimulatorAPI SHARED ${SOURCES} ${CMAKE_CURRENT_SOURCE_DIR})
# Include SharedAPI and Robot
target_link_libraries(SimulatorAPI SharedAPI)
target_link_libraries(SimulatorAPI Robot)

# Remove prefix
set_target_properties(SimulatorAPI PROPERTIES PREFIX "")
# Change DLL filename
set_target_properties(SimulatorAPI PROPERTIES OUTPUT_NAME "__CPPSimulatorAPI")