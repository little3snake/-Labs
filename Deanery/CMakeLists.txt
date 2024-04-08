cmake_minimum_required(VERSION 3.27)
project(DeaneryDemo)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(DeaneryDemo
        include/Deanery.h
        include/Group.h
        include/Student.h
        src/Deanery.cpp
        src/Group.cpp
        src/main.cpp
        src/Student.cpp)
