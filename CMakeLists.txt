# !!!!!!!!!! IMPORTANT !!!!!!!!!!
# MAKE SURE YOU HAVE CLION > 2019.3
# https://blog.jetbrains.com/clion/2019/10/clion-2019-3-eap-ninja-cmake-generators/
# FOR COMPILING .DLL ON FOR WINDOWS
# Set cmake options in clion->settings->build,execution,deployment->cmake "-G "Visual Studio 15 2017 Win64""
# This way cmake will use the visual studio generator to build the project
# ON WINDOWS, I ALSO DOWNLOADED CMAKE FROM cmake.com, I'm not sure if its required, but...
message("Generator is set to ${CMAKE_GENERATOR}")

set(VERSION "2.8.4") # Create var "VERSION"

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall")

# Disable sh.exe mingw error
set(DCMAKE_SH="CMAKE_SH-NOTFOUND")

cmake_minimum_required(VERSION ${VERSION})
project(SimulatorAPI CXX)

file(GLOB SOURCES "src/*.c" "src/*.h" "src/*.cpp" "src/*.hpp")

# Enable DLL build w/ option() and SHARED flag in add_library()
option(MyLib_SHARED_LIBS "" ON)
include_directories(SimulatorAPI "${CMAKE_CURRENT_SOURCE_DIR}/../shared_api/include")
add_library(SimulatorAPI STATIC ${SOURCES} ${INCLUDES} ${CMAKE_CURRENT_SOURCE_DIR})
# Include SharedAPI
target_link_libraries(SimulatorAPI SharedAPI)
# Expose include/ to any cmake project that imports RobotAPI
target_include_directories(SimulatorAPI PUBLIC include/)

# HOW TO RUN A CONSOLE COMMAND IN CMAKE :)
# https://stackoverflow.com/questions/40696990/cmake-post-build-event-copy-compiled-libraries
# https://stackoverflow.com/questions/25687890/running-a-bash-command-via-cmake
# THIS CAUSES A BUILD LOOP SINCE THIS SCRIPT EFFECTIVELY CALLS THIS FILE
#add_custom_command(
#        TARGET SimulatorAPI
#        POST_BUILD
#        COMMAND bash -c "echo 'Current Bash Dir:'; PWD"
#        COMMAND bash -c "sh ${CMAKE_CURRENT_SOURCE_DIR}/build.sh ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}"
#)

#PRE_BUILD