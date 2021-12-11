add_library(Book
    src/Book.hpp
    src/Book.cpp
    src/Novel.hpp
    src/Novel.cpp
    src/Encyclopedia.hpp
    src/Encyclopedia.cpp
)

target_link_libraries(Book PRIVATE Person)

target_include_directories(Book PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
