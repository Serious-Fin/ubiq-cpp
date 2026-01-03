cmake_minimum_required(VERSION 4.1)
project(ubiq_cpp)

set(CMAKE_CXX_STANDARD 20)

add_library(ubiq_logic STATIC 
    src/Lexer.cpp src/Lexer.h
    src/Token.cpp src/Token.h 
    src/Error.cpp src/Error.h
)

add_executable(ubiq_cpp main.cpp)
target_link_libraries(ubiq_cpp PRIVATE ubiq_logic)
target_include_directories(ubiq_logic PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
add_subdirectory(tests)