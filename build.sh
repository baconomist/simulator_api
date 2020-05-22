#!/usr/bin/env bash
echo ""
echo "Starting build script..."
echo "Please make sure you provide args \$1=source_dir and \$2=build_dir"
echo ""
#Link to where you can find this: https://stackoverflow.com/questions/28350214/how-to-build-x86-and-or-x64-on-windows-from-command-line-with-cmake
#THIS ONLY BUILDS x64

CMAKE_SOURCE_DIR=$1;
CMAKE_BUILD_DIR=$2;
cd ${CMAKE_BUILD_DIR}

# Create build dir
rm -rf build64/
mkdir build64/
cd build64

# Build project
cmake -G "Visual Studio 15 2017 Win64" ${CMAKE_SOURCE_DIR}
cd ../
cmake --build build64 --config Release

exit