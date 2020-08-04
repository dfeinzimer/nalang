#include <iostream>
#include <vector>

#include "pos.h"
#include "recommender.h"
#include "repl.h"

using namespace std;

bool DIAGNOSTICS = false;

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
            vector<string> partsOfSpeech = getPartsOfSpeech(tokens);
            if(DIAGNOSTICS) {
                for (int i = 0; i < tokens.size(); i++) {
                    cout << "Token/POS: " << tokens.at(i) << "/" << partsOfSpeech.at(i) << endl;
                }
            }
            recommendAction(partsOfSpeech);
        }
    }
    return 0;
}