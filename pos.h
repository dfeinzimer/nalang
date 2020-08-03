#ifndef pos_h
#define pos_h

#include <string>
#include <vector>

using namespace std;

const vector<string>adjectives    = {"antique", "beautiful", "big", "happy", "hot", "fragrant", "mad", "sad", "sparkling" };
const vector<string>adverbs       = {"carefully", "extremely","gently", "poorly", "well"};
const vector<string>amounts       = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
const vector<string>conjunctions  = {"and", "because", "but", "or", "while"};
const vector<string>interjections = {"oh", "oops", "wow"};
const vector<string>nouns         = {"list", "object", "thing", "variable"};
const vector<string>prepositions  = {"a", "about", "by", "until", "with"};
const vector<string>pronoun       = {"he", "I", "it", "she", "they", "this", "who", "we"};
const vector<string>verbs         = {"add", "create", "delete", "fill", "is", "show", "sum", "summarize"};

bool contains(vector<string> arr, string target);
string getPos(string token);
bool isNumber(string input);
string lowercased(string input);

#endif