cmake_minimum_required(VERSION 3.0)
project(feature_tracking)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

find_package(OpenCV REQUIRED)

add_definitions(-DPROJ_TEST_IMAGES_DIR="${CMAKE_SOURCE_DIR}/images/")
add_definitions(-DPROJ_CALIBRATION_DIR="${CMAKE_SOURCE_DIR}/calib/")

add_subdirectory(src)
