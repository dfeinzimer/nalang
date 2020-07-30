#include <iostream>
#include <vector>

#include "pos.h"
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
        for(int i = 0; i < statements.size(); i++) { 
            vector<string> tokens = tokenize(statements.at(i));
            for(int i = 0; i < tokens.size(); i++) {
                cout << tokens.at(i) << ": " << getPos(tokens.at(i)) << endl;
            }
        }
    }
    return 0;
}