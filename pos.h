#ifndef pos_h
#define pos_h

#include <string>
#include <vector>

using namespace std;

const vector<string>adjectives   = {"happy", "mad", "sad"};
const vector<string>conjunctions = {"and"};
const vector<string>verbs        = {"add", "create", "delete", "fill", "show", "sum", "summarize"};
const vector<string>nouns        = {"list", "object", "thing", "variable"};
const vector<string>participles  = {"called", "filled", "named"};
const vector<string>prepositions = {"a"};
const vector<string>pronoun      = {"it", "this"};
const vector<string>amounts      = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};

bool contains(vector<string> arr, string target);
string getPos(string token);
string lowercased(string input);

#endif