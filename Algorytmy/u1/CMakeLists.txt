cmake_minimum_required(VERSION 3.23)
project(u1)

set(CMAKE_CXX_STANDARD 17)

add_executable(u1 main.cpp Animal.cpp Animal.h Dog.cpp Dog.h Cat.cpp Cat.h)
