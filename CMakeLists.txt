cmake_minimum_required(VERSION 3.0)

set(myproject "Proiect-IEP")

set(CMAKE_CXX_FLAGS "-pthread")

project(${myproject})

add_subdirectory(src)

add_executable("${PROJECT_NAME}" main.cpp)

target_link_libraries("${PROJECT_NAME}" PRIVATE Person Book Library Lock)