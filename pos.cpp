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

/**
 * Returns the part of speech a token belongs to.
 *
 * @param token One english language word.
 * @return The part of speech the given token belongs to.
 */
string getPos(string token) {
    if (contains(adjectives, token))    { return "ADJECTIVE"; }
    if (contains(conjunctions, token))  { return "CONJUNCTION"; }
    if (contains(adverbs, token))       { return "ADVERB"; }
    if (contains(verbs, token))         { return "VERB"; }
    if (contains(nouns, token))         { return "NOUN"; }
    if (contains(prepositions, token))  { return "PREPOSITION"; }
    if (contains(pronoun, token))       { return "PRONOUN"; }
    if (contains(interjections, token)) { return "INTERJECTION"; }
    if (contains(amounts, token))       { return "AMOUNT"; }
    if (isNumber(token))                { return "NUMBER"; }
    return "N/A";
}

bool isNumber(string input) {
    for (int i = 0; i < input.length(); i++) {
        if (isdigit(input[i]) == false) {
            return false;
        }
    }
    return true;
}

string lowercased(string input) {
    for(int i = 0; i < input.length(); i++) {
        input[i] = tolower(input[i]);
    }
    return input;
}