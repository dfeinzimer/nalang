#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void print(string out);

string read() {
    string input_buffer;
    getline(cin, input_buffer);
    return input_buffer;
}

vector<string> extractStatements(string input, bool debug) {
    vector<string> result;
    int start = 0;
    for(int i = 0; i < input.length(); i++) {
        if(input[i] == '.') {
            string newStatement = input.substr(start, i);
            result.push_back(newStatement);
            start = i++;
        }
    }
    int statementCount = result.size();
    if (debug) { print("Statements Extracted: " + to_string(statementCount)); }
    if (input.length() > 0 && statementCount == 0) { cout << "Tip: Make sure to use periods!" << endl; }
    return result;
}

vector<string> tokenize(std::string input, bool debug) {
    istringstream buf(input);
    istream_iterator<string> beg(buf), end;
    vector<string> foundtokens (beg, end);
    vector<string> processedTokens;
    for (int i = 0; i < foundtokens.size(); i++) {
        string newToken;
        for (int j = 0; j < foundtokens.at(i).length(); j++) {
            newToken.push_back(tolower(foundtokens.at(i)[j]));
        }
        if (newToken != ".") {
            processedTokens.push_back(newToken);
        }
    }
    return processedTokens;
}

void analyze(string input, bool debug) {
    const char per = '.';
    int count = 0;
    for(int x = 0; x < input.length(); x++) {
        if(input.at(x) ==  per) {
            count ++;
        }
    }
    if (debug) { print("Statements Expected: " + to_string(count)); }
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