#include <iostream>

#include "recommender.h"

using namespace std;

void describeAction(action anAction) {
    switch (anAction) {
    case DEFINE_VALUE:
        cout << "Create a new value." << endl;
        break;
    case DELETE_VALUE:
        cout << "Delete an existing value." << endl;
        break;
    case NO_OP:
        cout << "No action recommended." << endl;
        break;
    case SHOW_VALUE:
        cout << "Display an existing value." << endl;
        break;
    }
}

action recommendAction(definedStatement statement) {
    describeAction(NO_OP);
    return NO_OP;
}