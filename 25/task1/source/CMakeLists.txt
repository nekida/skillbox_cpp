cmake_minimum_required(VERSION 3.16)

add_executable(OperationsSimulator main.cpp ${MY_INCLUDE_DIR}/surgical_instruments.h surgical_instruments.cpp)
target_include_directories(OperationsSimulator PUBLIC ${MY_INCLUDE_DIR})
