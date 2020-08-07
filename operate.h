#ifndef operate_h
#define operate_h

#include "objectdef.h"
#include "operate.h"
#include "recommender.h"

using objectName = string;
using state = vector<tuple<objectName,objectdef>>;

void definitionOp(state& currentState);
void deletionOp(state& currentState);
void exhibitionOp(state& currentState);
void noOp();
void printListVal(vector<objectdef> listVal);
void routeOperation(action act, vector<tuple<string,objectdef>>& state);

#endif