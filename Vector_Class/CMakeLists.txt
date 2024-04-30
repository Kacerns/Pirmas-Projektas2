# CMakeLists.txt

cmake_minimum_required(VERSION 3.0)

project(MyProgram)

# Add source files
set(SOURCES
    DataManip.cpp
    DataManip.h
    ErrorHandling.cpp
    ErrorHandling.h
    IOmanip.cpp
    IOmanip.h
    lib.h
    student.hpp
    student.cpp
    vector.cpp
)

# Add executable
add_executable(my_program ${SOURCES})