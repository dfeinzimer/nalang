#ifndef recommender_h
#define recommender_h

#include <string>
#include <vector>

using namespace std;

enum action { 
    DEFINE_VALUE,
    DELETE_VALUE,
    NO_OP,
    SHOW_VALUE
};

void describeAction(action anAction);
action recommendAction(vector<string>partsOfSpeech);

#endif