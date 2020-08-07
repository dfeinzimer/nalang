#include <iostream>
#include <vector>

#include "objectdef.h"
#include "operate.h"
#include "pos.h"
#include "recommender.h"
#include "repl.h"
#include "test.h"
#include "utils.h"

using namespace std;

using objectName = string;
using state = vector<tuple<objectName,objectdef>>;

bool DEBUG = false;
bool TEST = false;
state STATE;

int main(int argc, char** argv) {
    usage();
    enableDebug(argc,argv, DEBUG);
    enableTests(argc,argv, TEST);
    if (TEST) {
        runTests();
        return 0;
    }
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
            if(DEBUG) { describeAction(recommendation); }
            routeOperation(recommendation, STATE);
        }
    }
    return 0;
}