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
    action recommendation = NO_OP;
    if (get<1>(statement.at(0)) == VERB) {
        string token = get<0>(statement.at(0));
        if (token == "build" || token == "create" || token == "found" || token == "generate" || token == "make" || token == "start") {
            recommendation = DEFINE_VALUE;
        } else if (token == "delete" || token == "destroy" || token == "remove") {
            recommendation = DELETE_VALUE;
        } else if (token == "print" || token == "show") {
            recommendation = SHOW_VALUE;
        }
    } else {
        recommendation = NO_OP;
    }
    return recommendation;
}