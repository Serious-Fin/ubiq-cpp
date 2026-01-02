#include <string>
#include <iostream>
#include <format>
#include "Error.h"

bool Error::hasErrorHappened = false;

void Error::Log(int line, int column, const std::string &message) {
    hasErrorHappened = true;
    const auto formattedMsg = std::format("[line {} col {}] Error: {}", line, column, message);
    printToConsole(formattedMsg);
}

bool Error::ErrorHappened() {
    return hasErrorHappened;
}

void Error::printToConsole(const std::string &msg) {
    std::cout << msg;
}
