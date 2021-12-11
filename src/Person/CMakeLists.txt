add_library(Person
    src/Person.hpp
    src/Person.cpp
    src/Author.hpp
    src/Author.cpp
    src/Reader.hpp
    src/Reader.cpp
)

target_link_libraries(Person PRIVATE Book)


target_include_directories(Person PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
