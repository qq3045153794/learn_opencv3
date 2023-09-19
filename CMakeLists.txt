cmake_minimum_required(VERSION 3.10)
project(ch2)

find_package(OpenCV REQUIRED)

set(CMAKE_CXX_STANDARD 11)

link_libraries(${OpenCV_LIBRARIES})

add_executable(ex2-1 ex_2-1.cpp)

add_executable(ex2-2 ex_2-2.cpp)

add_executable(ex2-4 ex_2-4.cpp)

add_executable(ex2-5 ex_2-5.cpp)

add_executable(ex2-6 ex_2-6.cpp)

add_executable(ex2-7 ex_2-7.cpp)

add_executable(ex2-8 ex_2-8.cpp)

add_executable(ex2-11 ex_2-11.cpp)

add_executable(ex9-2 ex_9_2.cpp)

add_executable(ex9-3 ex_9_3.cpp)

add_executable(ex10-1 ex_10_1.cpp)

add_executable(ex10-3 ex_10_3.cpp)

add_executable(ex10-4 ex_10_4.cpp)

add_executable(ex11-1 ex_11_1.cpp)
