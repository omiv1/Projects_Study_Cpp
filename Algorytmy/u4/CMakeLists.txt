cmake_minimum_required(VERSION 3.23)
project(u4)

set(CMAKE_CXX_STANDARD 17)

add_executable(u4 main.cpp Citizen.h City.cpp City.h)
