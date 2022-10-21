cmake_minimum_required(VERSION 3.23)
project(src)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(src
        Banque.cpp
        Banque.h
        Compte.cpp
        Compte.h
        main.cpp)
