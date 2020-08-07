#include <iostream>

#include "utils.h"

void enableDebug(int count, char** args, bool& DEBUG) {
    if (count < 2) { return; } 
    if (!strcmp(args[1], "-d")) { DEBUG = true; }
}

void usage() {
    std::cout << "Normal mode: ./nalang" << std::endl;
    std::cout << "Debug mode:  ./nalang -d" << std::endl;
}