cmake_minimum_required(VERSION 4.1)
project(ubiq_cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(ubiq_cpp main.cpp
        Lexer.cpp
        Lexer.h
        Token.cpp
        Token.h
        Error.cpp
        Error.h)
