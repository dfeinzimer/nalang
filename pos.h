#ifndef pos_h
#define pos_h

#include <string>
#include <vector>

using namespace std;

const vector<string>adjectives    = {"antique", "beautiful", "big", "happy", "hot", "fragrant", "mad", "new", "sad", "sparkling" };
const vector<string>adverbs       = {"carefully", "extremely","gently", "poorly", "well"};
const vector<string>amounts       = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
const vector<string>conjunctions  = {"and", "because", "but", "or", "while"};
const vector<string>interjections = {"oh", "oops", "wow"};
const vector<string>nouns         = {"list", "object", "thing", "variable"};
const vector<string>prepositions  = {"a", "about", "by", "until", "with"};
const vector<string>pronoun       = {"he", "i", "it", "she", "they", "this", "who", "we"};
const vector<string>verbs         = {"add", "am", "called", "create", "delete", "fill", "is", "make", "named", "show", "sum", "summarize"};

enum partOfSpeech { 
    ADJECTIVE,      ADVERB,         AMOUNT,
    CONJUNCTION,    ERROR,          INTERJECTION,   
    NOUN,           PREPOSITION,    PRONOUN,        
    VERB
};

using definedStatement = vector<tuple<string,partOfSpeech>>;

bool contains(vector<string> arr, string target);
bool isNumber(string input);
definedStatement packageTokens(vector<string>tokens,vector<partOfSpeech>pos);
partOfSpeech getPartOfSpeech(string token);
string lowercased(string input);
vector<partOfSpeech> getPartsOfSpeech(vector<string>tokens);
void showDefinedStatement(definedStatement statement);
void showPartOfSpeech(partOfSpeech pos);

#endif