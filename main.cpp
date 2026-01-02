#include <iostream>

#include "Lexer.h"
#include "Token.h"

int main() {
    auto lexer = Lexer("(){},.-+;*");
    auto tokens = lexer.ParseTokens();

    for (const auto& token: tokens) {
        std::cout << token.ToString() << '\n';
    }

    return 0;
}