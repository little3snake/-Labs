cmake_minimum_required(VERSION 3.27)
project(StaffDemo)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(StaffDemo
        include/Employee.h
        include/Engineer.h
        include/Factory.h
        include/Interfaces.h
        include/Manager.h
        include/Personal.h
        info/projects_info.txt
        info/staff_info.txt
        src/Employee.cpp
        src/Engineer.cpp
        src/Factory.cpp
        src/main.cpp
        src/Manager.cpp
        src/Personal.cpp)
