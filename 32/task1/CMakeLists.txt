cmake_minimum_required(VERSION 3.16)
project("cpp_jason" VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)

add_executable(cpp_jason main.cpp)

include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_MakeAvailable(json)

target_link_libraries(cpp_jason PRIVATE nlohmann_json::nlohmann_json)
