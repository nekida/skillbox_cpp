cmake_minimum_required(VERSION 3.16)

set(SOURCE cpu.cpp ram.cpp disk.cpp gpu.cpp kbd.cpp)
set(HEADER ${MY_INCLUDE_DIR}/cpu.h  ${MY_INCLUDE_DIR}/ram.h ${MY_INCLUDE_DIR}/disk.h ${MY_INCLUDE_DIR}/gpu.h ${MY_INCLUDE_DIR}/kbd.h)

add_executable(ComputerSimulator main.cpp ${SOURCE} ${HEADER})
target_include_directories(ComputerSimulator PUBLIC ${MY_INCLUDE_DIR})
