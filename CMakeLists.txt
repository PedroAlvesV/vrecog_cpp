cmake_minimum_required (VERSION 3.5)

project (vrecog)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++11 -lpaho-mqttpp3 -lpaho-mqtt3as -pthread")
set (source_dir "${PROJECT_SOURCE_DIR}/src/")

file (GLOB source_files "${source_dir}/*.cpp")

add_executable (vrecog ${source_files})
