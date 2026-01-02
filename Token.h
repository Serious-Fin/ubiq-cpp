#pragma once

#include <format>
#include <string>
#include <utility>

enum class TokenType {
    // Single character tokens
    LEFT_PAREN,
    RIGHT_PAREN,
    LEFT_BRACE,
    RIGHT_BRACE,
    SEMICOLON,
    GREATER,
    MINUS,
    SLASH,
    EQUAL,
    COMMA,
    STAR,
    PLUS,
    BANG,
    LESS,
    DOT,

    // Two character tokens
    GREATER_EQUAL,
    EQUAL_EQUAL,
    BANG_EQUAL,
    LESS_EQUAL,
    AND,
    OR,

    // Literals
    IDENTIFIER,
    STRING,
    NUMBER,

    // Keywords
    RETURN,
    WHILE,
    FALSE,
    CLASS,
    SUPER,
    PRINT,
    ELSE,
    FUNC,
    THIS,
    TRUE,
    NIL,
    FOR,
    LET,
    IF,
};

class Token {
public:
    explicit Token(const TokenType type, std::string symbols, const int line, const int column) :
    type(type), symbols(std::move(symbols)), line(line), column(column) {}

    [[nodiscard]] std::string ToString() const noexcept;
private:
    const TokenType type;
    const std::string symbols;
    const std::size_t line;
    const std::size_t column;
};