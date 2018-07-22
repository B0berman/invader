cmake_minimum_required(VERSION 3.10)
project(invader)

set(CMAKE_CXX_STANDARD 11)


include_directories(external-lib/SFML-2.5.0/include/SFML)
include_directories(external-lib/SFML-2.5.0/include)
include_directories(external-lib/SFML-2.5.0/include/SFML/System)
include_directories(external-lib/SFML-2.5.0/include/SFML/Window)
include_directories(external-lib/SFML-2.5.0/include/SFML/Audio)
include_directories(external-lib/SFML-2.5.0/include/SFML/Graphics)
include_directories(external-lib/SFML-2.5.0/include/SFML/Network)

add_executable(invader main.cpp)

