#include <iostream>
#include <vector>
#include "repl.h"

using namespace std;

bool DIAGNOSTICS = true;

int main() {
    while(true) {
        prompt();
        string input = read();
        if(DIAGNOSTICS) {
            analyze(input);
            extractStatements(input);
        }
        print(input);
    }
    return 0;
}