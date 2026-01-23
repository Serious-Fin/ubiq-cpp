#include <catch2/catch_test_macros.hpp>
#include "Lexer.h"

TEST_CASE("OneSymbolTokens", "[LexerTests]") {
    auto lexer = Lexer("(){},.-+;*! < = >");
    auto tokens = lexer.ParseTokens();

    std::vector<Token> expectedTokens = {
        Token(TokenType::LEFT_PAREN, "(", 1, 1),
        Token(TokenType::RIGHT_PAREN, ")", 1, 2),
        Token(TokenType::LEFT_BRACE, "{", 1, 3),
        Token(TokenType::RIGHT_BRACE, "}", 1, 4),
        Token(TokenType::COMMA, ",", 1, 5),
        Token(TokenType::DOT, ".", 1, 6),
        Token(TokenType::MINUS, "-", 1, 7),
        Token(TokenType::PLUS, "+", 1, 8),
        Token(TokenType::SEMICOLON, ";", 1, 9),
        Token(TokenType::STAR, "*", 1, 10),
        Token(TokenType::BANG, "!", 1, 11),
        Token(TokenType::LESS, "<", 1, 13),
        Token(TokenType::EQUAL, "=", 1, 15),
        Token(TokenType::GREATER, ">", 1, 17),
        Token(TokenType::END, "", 1, 18),
    };

    for (size_t i = 0; i < expectedTokens.size(); ++i) {
        if (i >= tokens.size()) {
            FAIL("Expected: " + expectedTokens[i].ToString() + "\nGot: <null>");
        }

        if (tokens[i] != expectedTokens[i]) {
            FAIL("Expected: " + expectedTokens[i].ToString() + "\nGot: " + tokens[i].ToString());
        }
    }

    if (tokens.size() > expectedTokens.size()) {
        FAIL("Expected: <null>\nGot: " + tokens[expectedTokens.size()].ToString());
    }

    SUCCEED();
}

TEST_CASE("TwoSymbolTokens", "[LexerTests]") {
    auto lexer = Lexer("!= == <= >=");
    auto tokens = lexer.ParseTokens();

    std::vector<Token> expectedTokens = {
        Token(TokenType::BANG_EQUAL, "!=", 1, 1),
        Token(TokenType::EQUAL_EQUAL, "==", 1, 4),
        Token(TokenType::LESS_EQUAL, "<=", 1, 7),
        Token(TokenType::GREATER_EQUAL, ">=", 1, 10),
        Token(TokenType::END, "", 1, 12),
    };

    for (size_t i = 0; i < expectedTokens.size(); ++i) {
        if (i >= tokens.size()) {
            FAIL("Expected: " + expectedTokens[i].ToString() + "\nGot: <null>");
        }

        if (tokens[i] != expectedTokens[i]) {
            FAIL("Expected: " + expectedTokens[i].ToString() + "\nGot: " + tokens[i].ToString());
        }
    }

    if (tokens.size() > expectedTokens.size()) {
        FAIL("Expected: <null>\nGot: " + tokens[expectedTokens.size()].ToString());
    }

    SUCCEED();
}

TEST_CASE("IgnoreComments", "[LexerTests]") {
    auto lexer = Lexer("*// this is a comment\n+");
    auto tokens = lexer.ParseTokens();

    std::vector<Token> expectedTokens = {
        Token(TokenType::STAR, "*", 1, 1),
        Token(TokenType::PLUS, "+", 2, 1),
        Token(TokenType::END, "", 2, 2),
    };

    for (size_t i = 0; i < expectedTokens.size(); ++i) {
        if (i >= tokens.size()) {
            FAIL("Expected: " + expectedTokens[i].ToString() + "\nGot: <null>");
        }

        if (tokens[i] != expectedTokens[i]) {
            FAIL("Expected: " + expectedTokens[i].ToString() + "\nGot: " + tokens[i].ToString());
        }
    }

    if (tokens.size() > expectedTokens.size()) {
        FAIL("Expected: <null>\nGot: " + tokens[expectedTokens.size()].ToString());
    }

    SUCCEED();
}