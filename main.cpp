#include <iostream>
#include "Token.h"

int main() {
    auto token = Token(TokenType::GREATER_EQUAL, ">=", 5, 2);
    std::cout << "received: " << token.ToString();
    return 0;
}