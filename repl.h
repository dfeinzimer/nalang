#ifndef repl_h
#define repl_h

#include <string>

void analyze(std::string input);

std::vector<std::string> extractStatements(std::string input);

void interpret(std::string input);

void print(std::string out);

void prompt();

std::string read();

#endif