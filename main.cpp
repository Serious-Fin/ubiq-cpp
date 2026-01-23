#include <iostream>
#include <fstream>
#include <sstream>
#include "Lexer.h"
#include "Token.h"
#include "Error.h"

void runPrompt();
void runFile(std::string& filename);
void run(std::string& source);

int main(int argc, char* argv[]) {
    if (argc == 1) {
        runPrompt();
    } else if (argc == 2) {
        std::string filename(argv[1]);
        runFile(filename);
    } else {
        Error::Log("Usage: ubiq-cpp.exe [script]");
    }

    return 0;
}

void runFile(std::string& filename) {
    std::ifstream file(filename);
    std::stringstream buffer;
    buffer << file.rdbuf();

    std::string source = buffer.str();
    run(source);
}

void runPrompt() {
    std::cout << "Running interpreter (Ctrl + c to exit):" << '\n';
    while (true) {
        std::cout << "> ";
        std::string input;
        if(!std::getline(std::cin, input)) {
            std::cout << "exiting...\n";
            break;
        }
        run(input);
    }
}

void run(std::string& source) {
    auto lexer = Lexer(source);
    auto tokens = lexer.ParseTokens();

    for(const auto& token : tokens) {
        std::cout << token.ToString() << '\n';
    }
}