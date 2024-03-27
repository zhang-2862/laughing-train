cmake_minimum_required(VERSION 3.27)
project(Polymorphism_based_workforce_management_system)

set(CMAKE_CXX_STANDARD 17)

add_executable(Polymorphism_based_workforce_management_system main.cpp
        inc/worker.h
        inc/employee.h
        src/employee.cpp
        src/workerManager.cpp
        inc/workerManager.h
        inc/manager.h
        src/manager.cpp
        inc/boss.h
        src/boss.cpp)


