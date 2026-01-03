include(../cmake/CPM.cmake)
CPMAddPackage("gh:catchorg/Catch2@3.12.0")

add_executable(Lexer_tests LexerTest.cpp)

# Link to both Catch2 AND your logic library
target_link_libraries(Lexer_tests PRIVATE 
    Catch2::Catch2WithMain 
    ubiq_logic
)