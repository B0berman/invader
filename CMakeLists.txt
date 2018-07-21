cmake_minimum_required(VERSION 3.10)
project(invader)

set(CMAKE_CXX_STANDARD 11)

#find_package (external-lib/SFML-2.5.0/lib/cmake/SFML/)
include_directories(external-lib/SFML-2.5.0/include)

add_executable(invader main.cpp)