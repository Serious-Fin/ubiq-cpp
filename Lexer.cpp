#include <vector>
#include "Lexer.h"
#include "Token.h"

std::vector<Token> Lexer::GetAllTokens() {
    while (!isAtEnd()) {
        start = current;
        scanNextToken();
    }

    tokens.emplace_back(TokenType::END, "", line, column);
    return tokens;
}

void scanNextToken() {

}

bool Lexer::isAtEnd() const {
    return current >= source.length();
}
