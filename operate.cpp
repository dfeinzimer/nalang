#include <iostream>
#include <string>
#include <vector>

#include "objectdef.h"
#include "operate.h"
#include "recommender.h"

using objectName = string;
using state = vector<tuple<objectName,objectdef>>;

void definitionOp(state& currentState) {
    int currentObjsCount = currentState.size();
    objectName newObjName = "obj" + to_string(currentObjsCount);
    objectdef newObjDef;
    newObjDef.intVal = 0;
    newObjDef.stringVal = "null";
    newObjDef.listVal = vector<objectdef>();
    currentState.push_back({newObjName,newObjDef});
    std::cout << "Done!" << endl;
}

void deletionOp(state& currentState) {
    currentState.clear();
    std::cout << "Memory cleared!" << endl;
}

void exhibitionOp(state& currentState) {
    for (int i = 0; i < currentState.size(); i++) {
        objectName objName = std::get<0>(currentState.at(i));
        objectdef objDef = std::get<1>(currentState.at(i));
        int iVal =  objDef.intVal;
        string strVal = objDef.stringVal;
        vector<objectdef> liVal = objDef.listVal;
        std::cout << objName << endl;
        std::cout << iVal << "\t" << strVal << "\t";
        printListVal(liVal);
        std::cout << endl;
    }
    std::cout << "That is all!" << endl;
}

void noOp() {
    std::cout << "Okay!" << std::endl;
}

void printListVal(vector<objectdef> listVal) {
    for (int i = 0; i < listVal.size(); i++) {
        cout << listVal.at(i).intVal << endl;
        cout << listVal.at(i).stringVal << endl;
        if (listVal.at(i).listVal.size() > 0) {
            printListVal(listVal.at(i).listVal);
        }
    }
}

void routeOperation(action act, state& currentState) {
    switch (act) {
        case DEFINE_VALUE:
            definitionOp(currentState);
            break;
        case DELETE_VALUE:
            deletionOp(currentState);
            break;
        case NO_OP:
            noOp();
            break;
        case SHOW_VALUE:
            exhibitionOp(currentState);
            break;
    }
}