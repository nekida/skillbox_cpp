cmake_minimum_required(VERSION 3.16)
project("default" VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)

find_package(Qt5Widgets COMPONENTS
    Core
    Gui
    Widgets
    REQUIRED)

add_executable(default main.cpp)
target_link_libraries(default
    Qt5::Widgets
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets)
