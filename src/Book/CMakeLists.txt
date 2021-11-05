add_library(Book
    src/Book.hpp
    src/Book.cpp
)

target_link_libraries(Book PRIVATE Person)

target_include_directories(Book PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
