cmake_minimum_required(VERSION 3.23)
project(u2)

set(CMAKE_CXX_STANDARD 17)

add_executable(u2 main.cpp Bufor.cpp Bufor.h MeanBufor.cpp MeanBufor.h MaxBufor.cpp MaxBufor.h)
