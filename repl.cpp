#include <iostream>
#include <string>
#include <vector>
#include "repl.h"

using namespace std;

void analyze(string input) {
    const char per = '.';
    int count = 0;
    for(int x = 0; x < input.length(); x++) {
        if(input.at(x) ==  per) {
            count ++;
        }
    }
    print("Statements Expected: " + to_string(count));
    vector<string> statements = extractStatements(input);
    print("Statements Found: " + to_string(statements.size()));
}

vector<string> extractStatements(string inputString) {
    vector<string> result;
    int start = 0;
    for(int i = 0; i < inputString.length(); i++) {
        if(inputString[i] == '.') {
            string newStatement = inputString.substr(start, i);
            result.push_back(newStatement);
            start = i++;

        }
    }
    return result;
}

void print(string out) {
    if (out == "") {
        return;
    }
    cout << out << endl;
}

void prompt() {
    cout << "nalang> ";
}

string read() {
    string input_buffer;
    getline(cin, input_buffer);
    return input_buffer;
}