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
        }
        vector<string> statements = extractStatements(input);
        for(int i = 0; i < statements.size(); i++) { tokenize(statements.at(i)); }
    }
    return 0;
}