add_library(Person
    src/Person.hpp
    src/Person.cpp
    src/Author.cpp
    src/Author.cpp

)

target_include_directories(Person PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
