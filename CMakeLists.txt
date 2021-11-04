cmake_minimum_required(VERSION 3.0)

set(myproject "Proiect-IEP")

project(${myproject})

add_subdirectory(src/Person)

add_executable("${PROJECT_NAME}" main.cpp)

target_link_libraries("${PROJECT_NAME}" PRIVATE Person)