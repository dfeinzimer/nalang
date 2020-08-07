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

action recommendAction(definedStatement pairs);
void describeAction(action anAction);

#endif