cmake_minimum_required(VERSION 3.16)
project(RoomReservationSys)

set(CMAKE_CXX_STANDARD 14)

add_executable(RoomReservationSys main.cpp Identity.cpp Identity.h Student.cpp Student.h Teacher.cpp Teacher.h Manager.cpp Manager.h)