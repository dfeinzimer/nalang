#ifndef recommender_h
#define recommender_h

#include <string>
#include <vector>

#include "pos.h"

using namespace std;

enum action { 
    DEFINE_VALUE,
    DELETE_VALUE,
    NO_OP,
    SHOW_VALUE
};

void describeAction(action anAction);
action recommendAction(vector<tuple<string,partOfSpeech>>pairs);

#endif