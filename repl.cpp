#include <iostream>
#include <string>
#include "repl.h"

using namespace std;

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