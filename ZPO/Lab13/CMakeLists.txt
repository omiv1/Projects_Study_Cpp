cmake_minimum_required(VERSION 3.23)
project(Lab13)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab13 main.cpp)

# 'lib' is the folder with Google Test sources
add_subdirectory(googletest-main)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

# 'Google_Tests_run' is the target name
# 'test1.cpp test2.cpp' are source files with tests
add_executable(Google_Tests_run test1.cpp test2.cpp test_liczba_pierwsza.cpp test_pierwiastek.cpp test_dzielenie.cpp functions.cpp functions.h number.cpp number.h liczba_pierwsza.cpp liczba_pierwsza.h pierwiastek.cpp pierwiastek.h dzielenie.cpp dzielenie.h)
target_link_libraries(Google_Tests_run gtest gmock gtest_main)