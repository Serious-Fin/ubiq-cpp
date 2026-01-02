#pragma once

#include <string>

class Error {
public:
    static void Log(int line, int column, const std::string& message);
    static bool ErrorHappened();

private:
    static bool hasErrorHappened;
    static void printToConsole(const std::string &msg);
};
