cmake_minimum_required(VERSION 3.10)
project(ch2)

find_package(OpenCV REQUIRED)

set(CMAKE_CXX_STANDARD 11)

link_libraries(${OpenCV_LIBRARIES})

add_executable(ex2-1 ex_2-1.cpp)

add_executable(ex2-2 ex_2-2.cpp)

add_executable(ex2-4 ex_2-4.cpp)

add_executable(ex2-5 ex_2-5.cpp)
