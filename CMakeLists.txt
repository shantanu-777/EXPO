cmake_minimum_required(VERSION 3.10)
project(CPPInterpreter)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(CPPInterpreter
    src/main.cpp
    src/lexer.cpp
    src/parser.cpp
    src/interpreter.cpp
)
