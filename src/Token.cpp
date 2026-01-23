#include "Token.h"

#include <unordered_map>

const std::unordered_map<TokenType, std::string> TokenTypeNames = {
    {TokenType::LEFT_PAREN, "LEFT_PAREN"},
    {TokenType::RIGHT_PAREN, "RIGHT_PAREN"},
    {TokenType::LEFT_BRACE, "LEFT_BRACE"},
    {TokenType::RIGHT_BRACE, "RIGHT_BRACE"},
    {TokenType::SEMICOLON, "SEMICOLON"},
    {TokenType::GREATER, "GREATER"},
    {TokenType::MINUS, "MINUS"},
    {TokenType::SLASH, "SLASH"},
    {TokenType::EQUAL, "EQUAL"},
    {TokenType::COMMA, "COMMA"},
    {TokenType::STAR, "STAR"},
    {TokenType::PLUS, "PLUS"},
    {TokenType::BANG, "BANG"},
    {TokenType::LESS, "LESS"},
    {TokenType::DOT, "DOT"},
    {TokenType::GREATER_EQUAL, "GREATER_EQUAL"},
    {TokenType::EQUAL_EQUAL, "EQUAL_EQUAL"},
    {TokenType::BANG_EQUAL, "BANG_EQUAL"},
    {TokenType::LESS_EQUAL, "LESS_EQUAL"},
    {TokenType::AND, "AND"},
    {TokenType::OR, "OR"},
    {TokenType::IDENTIFIER, "IDENTIFIER"},
    {TokenType::STRING, "STRING"},
    {TokenType::NUMBER, "NUMBER"},
    {TokenType::RETURN, "RETURN"},
    {TokenType::WHILE, "WHILE"},
    {TokenType::FALSE, "FALSE"},
    {TokenType::CLASS, "CLASS"},
    {TokenType::SUPER, "SUPER"},
    {TokenType::PRINT, "PRINT"},
    {TokenType::ELSE, "ELSE"},
    {TokenType::FUNC, "FUNC"},
    {TokenType::THIS, "THIS"},
    {TokenType::TRUE, "TRUE"},
    {TokenType::NIL, "NIL"},
    {TokenType::FOR, "FOR"},
    {TokenType::LET, "LET"},
    {TokenType::IF, "IF"},
    {TokenType::END, "END"},
};

std::string getTokenName(const TokenType type) noexcept {
    const auto iter = TokenTypeNames.find(type);
    if (iter != TokenTypeNames.end()) {
        return iter->second;
    } else {
        return "UNKNOWN";
    }
}

std::string Token::ToString() const noexcept {
    return std::format("[{}] \"{}\" line:{} col:{}", getTokenName(type), symbols, line, column);
}


