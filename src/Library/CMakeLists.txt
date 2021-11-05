add_library(Library
    src/Library.hpp
    src/Library.cpp
)

target_link_libraries(Library PRIVATE Book)

target_include_directories(Book PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
