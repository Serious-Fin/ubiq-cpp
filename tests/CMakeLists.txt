find_package(Catch2 3 REQUIRED)
add_executable(Lexer_tests_run LexerTest.cpp
        LexerTest.cpp)

target_link_libraries(Lexer_tests_run PRIVATE Catch2::Catch2WithMain)

include(Catch)
catch_discover_tests(Lexer_tests_run)