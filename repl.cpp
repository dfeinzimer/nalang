#include <iostream>
#include <string>
#include <vector>
#include "repl.h"

using namespace std;

void analyze(string input) {
    const char per = '.';
    int count = 0;
    for (int x = 0; x < input.length(); x++) {
        if (input.at(x) ==  per) {
            count ++;
        }
    }
    print("Statements Expected: " + to_string(count));
    extractStatements(input);
}

vector<string> extractStatements(string inputString) {
    vector<string> result;
    // print(inputString);
    // int first = inputString.find('.');
    // cout << first;
    // // return result;
    // while (first != -1) {
    //     string newStatement = inputString.substr(0,first-1);
    //     cout << newStatement;
    //     result.push_back(newStatement);
    //     inputString = inputString.substr(first, inputString.length());
    //     first = inputString.find('.');
    // }
    // print("Statements Extracted: " + to_string(result.size()));
    // for (int i = 0; i < result.size(); i++) {
    //     cout << result[i] << endl;
    // }
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