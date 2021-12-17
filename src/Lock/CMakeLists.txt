add_library(Lock
    src/Lock.hpp
    src/Lock.cpp
)

target_include_directories(Lock PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
