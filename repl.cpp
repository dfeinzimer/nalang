#include <iostream>
#include <iterator>
#include <sstream>
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
}

vector<string> extractStatements(string input) {
    vector<string> result;
    int start = 0;
    for(int i = 0; i < input.length(); i++) {
        if(input[i] == '.') {
            string newStatement = input.substr(start, i);
            result.push_back(newStatement);
            start = i++;
        }
    }
    print("Statements Extracted: " + to_string(result.size()));
    return result;
}

vector<string> tokenize(std::string input) {
    istringstream buf(input);
    istream_iterator<string> beg(buf), end;
    vector<string> tokens (beg, end);
    for (auto& s: tokens) {
        cout << "Token: " << s << endl;
    }
    return tokens;
}

void print(string out) {
    if(out == "") {
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