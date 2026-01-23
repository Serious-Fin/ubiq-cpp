#include <vector>
#include "Lexer.h"
#include "Token.h"
#include "Error.h"

std::vector<Token> Lexer::ParseTokens() {
    while (!isAtEnd()) {
        start = current;
        scanNextToken();
    }
    tokens.emplace_back(TokenType::END, "", line, column + 1);
    return tokens;
}

void Lexer::scanNextToken() {
    switch (auto currentChar = consumeNextChar()) {
        case '(':
            addToken(TokenType::LEFT_PAREN);
            break;
        case ')':
            addToken(TokenType::RIGHT_PAREN);
            break;
        case '{':
            addToken(TokenType::LEFT_BRACE);
            break;
        case '}':
            addToken(TokenType::RIGHT_BRACE);
            break;
        case ',':
            addToken(TokenType::COMMA);
            break;
        case '.':
            addToken(TokenType::DOT);
            break;
        case '-':
            addToken(TokenType::MINUS);
            break;
        case '+':
            addToken(TokenType::PLUS);
            break;
        case ';':
            addToken(TokenType::SEMICOLON);
            break;
        case '*':
            addToken(TokenType::STAR);
            break;
        default:
            Error::LogSyntaxError(line, column, std::format("Unexpected character {}", currentChar));
            break;
    }
}

void Lexer::addToken(TokenType type) {
    auto tokenText = source.substr(start, current - start);
    tokens.emplace_back(type, tokenText, line, column);
}

char Lexer::consumeNextChar() {
    column++;
    return source.at(current++);
}

bool Lexer::isAtEnd() const {
    return current >= source.length();
}
