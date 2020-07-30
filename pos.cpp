#include <string>
#include <vector>

#include "pos.h"

using namespace std;

bool contains(vector<string> arr, string target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr.at(i) == lowercased(target)) {
            return true;
        }
    }
    return false;
}

string getPos(string token) {
    if (contains(adjectives, token))    { return  "ADJECTIVE"; }
    if (contains(conjunctions, token))  { return  "CONJUNCTION"; }
    if (contains(verbs, token))         { return  "VERB"; }
    if (contains(nouns, token))         { return  "NOUN"; }
    if (contains(participles, token))   { return  "PARTICIPLE"; }
    if (contains(prepositions, token))  { return  "PREPOSITION"; }
    if (contains(pronoun, token))       { return  "PRONOUN"; }
    if (contains(amounts, token))       { return  "AMOUNT"; }
    return "N/A";
}

string lowercased(string input) {
    for(int i = 0; i < input.length(); i++) {
        input[i] = tolower(input[i]);
    }
    return input;
}