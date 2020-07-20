#include <iostream>
#include <string>
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