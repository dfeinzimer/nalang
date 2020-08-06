#include <iostream>
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
partOfSpeech getPartOfSpeech(string token) {
    if (contains(adjectives, token))    { return ADJECTIVE; }
    if (contains(conjunctions, token))  { return CONJUNCTION; }
    if (contains(adverbs, token))       { return ADVERB; }
    if (contains(verbs, token))         { return VERB; }
    if (contains(nouns, token))         { return NOUN; }
    if (contains(prepositions, token))  { return PREPOSITION; }
    if (contains(pronoun, token))       { return PRONOUN; }
    if (contains(interjections, token)) { return INTERJECTION; }
    if (contains(amounts, token))       { return AMOUNT; }
    if (isNumber(token))                { return AMOUNT; }
    return ERROR;
}

/**
 * Returns the parts of speech a vector of tokens belong to.
 *
 * @param tokens A vector of english language words.
 * @return A vector of parts of speech.
 */
vector<partOfSpeech> getPartsOfSpeech(vector<string> tokens) {
    vector<partOfSpeech> partsOfSpeech;
    for (int i = 0; i < tokens.size(); i++) {
        partsOfSpeech.push_back(getPartOfSpeech(tokens.at(i)));
    }
    return partsOfSpeech;
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

void showDefinedStatement(definedStatement statement) {
    for (int i = 0; i < statement.size(); i++) {
        string token = get<0>(statement.at(i));
        partOfSpeech pos = get<1>(statement.at(i));
        cout << "Token/POS: " << token << "/";
        showPartOfSpeech(pos);
        cout << endl;
    }
}

void showPartOfSpeech(partOfSpeech pos) {
    switch (pos) {
        case ADJECTIVE:     cout << "ADJECTIVE";    break;
        case ADVERB:        cout << "ADVERB";       break;
        case AMOUNT:        cout << "AMOUNT";       break;
        case CONJUNCTION:   cout << "CONJUNCTION";  break;
        case ERROR:         cout << "ERROR";        break;
        case INTERJECTION:  cout << "INTERJECTION"; break;
        case NOUN:          cout << "NOUN";         break;
        case PREPOSITION:   cout << "PREPOSITION";  break;
        case PRONOUN:       cout << "PRONOUN";      break;
        case VERB:          cout << "VERB";         break;
    }
}

definedStatement packageTokens(vector<string>tokens,vector<partOfSpeech>pos) {
    vector<tuple<string,partOfSpeech>> result;
    if (tokens.size() != pos.size()) { return result; }
    for (int i  = 0; i < tokens.size(); i++) {
        result.push_back(tie(tokens.at(i), pos.at(i)));
    }
    return result;
}