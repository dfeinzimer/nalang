#include <iostream>

#include "utils.h"

void enableDebug(int count, char** args, bool& DEBUG) {
    if (count < 2) { return; } 
    if (!strcmp(args[1], "-d")) { DEBUG = true; }
}

void enableTests(int count, char** args, bool& TEST) {
    if (count < 2) { return; } 
    if (!strcmp(args[1], "-t")) { TEST = true; }
}

void usage() {
    std::cout << "Normal mode: ./nalang" << std::endl;
    std::cout << "Debug mode:  ./nalang -d" << std::endl;
    std::cout << "Run tests:   ./nalang -t" << std::endl;
}