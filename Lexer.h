#pragma once

#include <vector>
#include <string>
#include "Token.h"

class Lexer {
public:
    explicit Lexer(std::string input) : source(std::move(input)) {
        tokens = {};
    }
    std::vector<Token> GetAllTokens();

private:
    std::string source;
    std::vector<Token> tokens;
    int start = 0;
    int current = 0;
    int line = 1;
    int column = 1;

    [[nodiscard]] bool isAtEnd() const;
    void scanNextToken();
};
