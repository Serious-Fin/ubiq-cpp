#pragma once

#include <vector>
#include <string>
#include "Token.h"

class Lexer {
public:
    explicit Lexer(std::string input) : source(std::move(input)) {
        tokens = {};
    }
    std::vector<Token> ParseTokens();

private:
    std::string source;
    std::vector<Token> tokens;
    int start = 0;
    int current = 0;
    int line = 1;
    int column = 0;

    [[nodiscard]] bool isAtEnd() const;
    void scanNextToken();
    void addToken(TokenType type);
    char consumeNextChar();
    bool match(char expected);
};
