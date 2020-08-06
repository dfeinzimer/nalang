#include <iostream>
#include <vector>

#include "pos.h"
#include "recommender.h"
#include "repl.h"

using namespace std;

bool DEBUG = false;

void enableDiagnostics(int count, char** args) {
    if (count < 2) { return; } 
    if (!strcmp(args[1], "d")) { DEBUG = true; }
}

int main(int argc, char** argv) {
    enableDiagnostics(argc,argv);
    while(true) {
        prompt();
        string input = read();
        analyze(input, DEBUG);
        vector<string> statements = extractStatements(input, DEBUG);
        for(int i = 0; i < statements.size(); i++) { 
            vector<string> tokens = tokenize(statements.at(i), DEBUG);
            vector<partOfSpeech> partsOfSpeech = getPartsOfSpeech(tokens);
            definedStatement packagedStatement = packageTokens(tokens,partsOfSpeech);
            if(DEBUG) { showDefinedStatement(packagedStatement); }
            action recommendation = recommendAction(packagedStatement);
            describeAction(recommendation);
            cout << "Action not implemented" << endl;
        }
    }
    return 0;
}