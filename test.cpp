#include <iostream>
#include <string>

#include "operate.h"
#include "pos.h"
#include "repl.h"

using namespace std;

int failsnum = 0;
int passnum = 0;

void fail() {
    cout << "Fail" << endl << endl;
    failsnum++;
}


void pass() {
    cout << "Pass" << endl << endl;
    passnum++;
}

void runTests() {
    cout << "Testing..." << endl << endl;
    
    cout << "Contains" << endl;
    if (contains(verbs, "show")) { pass(); } else { fail(); }

    cout << "isNumber" << endl;
    if (isNumber("35")) { pass(); } else { fail(); }
    if (isNumber("3.5")) { fail(); } else { pass(); }
    if (isNumber("threefive")) { fail(); } else { pass(); }

    cout << "Package Tokens" << endl;
    vector<string> onetoken = {"their"};
    vector<string> twotokens = {"their", "apple"};
    vector<partOfSpeech> pos = { VERB, NOUN };
    if (packageTokens(onetoken, pos).size() == 0) { pass(); } else { fail(); }
    if (packageTokens(twotokens, pos).size() == 2) { pass(); } else { fail(); }

    cout << "Get Part Of Speech" << endl;
    if (getPartOfSpeech("make") == VERB) { pass(); } else { fail(); }
    if (getPartOfSpeech("a") == PREPOSITION) { pass(); } else { fail(); }
    if (getPartOfSpeech("wow") != INTERJECTION) { fail(); } else { pass(); } 

    cout << "Get Parts Of Speech" << endl;
    vector<string> toks2 = {"i", "wow"};
    vector<partOfSpeech> pos2 = getPartsOfSpeech(toks2);
    if (pos.at(0) == PRONOUN && pos.at(1) == INTERJECTION) { pass(); } else { fail(); }

    cout << "Show Defined Statement" << endl;
    definedStatement dS = packageTokens(twotokens, pos);
    showDefinedStatement(dS);
    pass();

    cout << "Lowercased" << endl;
    if (lowercased("CAT") == "cat") { pass(); } else { fail(); }

    cout << "Show Part Of Speech" << endl;
    showPartOfSpeech(INTERJECTION);
    pass();

    cout << "Describe Action" << endl;
    describeAction(DEFINE_VALUE);
    describeAction(DELETE_VALUE);
    describeAction(NO_OP);
    describeAction(SHOW_VALUE);
    pass();

    cout << "Recommend Action" << endl;
    vector<string> s1 = {"i", "like", "dogs"};
    vector<string> s2 = {"create", "my", "data"};
    vector<string> s3 = {"show", "my", "data"};
    vector<string> s4 = {"delete", "my", "data"};
    vector<partOfSpeech> p1 = getPartsOfSpeech(s1);
    vector<partOfSpeech> p2 = getPartsOfSpeech(s2);
    vector<partOfSpeech> p3 = getPartsOfSpeech(s3);
    vector<partOfSpeech> p4 = getPartsOfSpeech(s4);
    definedStatement d1 = packageTokens(s1, p1);
    definedStatement d2 = packageTokens(s2, p2);
    definedStatement d3 = packageTokens(s3, p3);
    definedStatement d4 = packageTokens(s4, p4);
    if (recommendAction(d1) == NO_OP &&
        recommendAction(d2) == DEFINE_VALUE &&
        recommendAction(d3) == SHOW_VALUE &&
        recommendAction(d4) == DELETE_VALUE) { pass(); } else{ fail(); }

    cout << "Extract Statement" << endl;
    if (extractStatements("not a statement" ,true).size() == 0 &&
        extractStatements("this is a statement.", true).size() == 1 &&
        extractStatements("one statement. two statements", true).size() == 2) { pass(); } else { fail(); }

    cout << "Tokenize" << endl;
    if (tokenize(".", true).size() == 0 &&
        tokenize("two tokens", true).size() == 2) { pass(); } else { fail(); }

    cout << "Definition Operation" << endl;
    vector<tuple<string,objectdef>> state0 = vector<tuple<string,objectdef>>();
    definitionOp(state0);
    if (state0.size() == 1) { pass(); }
    else { fail(); }

    cout << "Exhibition Operation" << endl;
    exhibitionOp(state0);
    pass();
    
    cout << "Deletion Operation" << endl;
    deletionOp(state0);
    if (state0.size() == 0) { pass(); }
    else { fail(); }

    cout << "No Operation" << endl;
    noOp();
    pass();

    cout << "Print List Val" << endl;
    objectdef obj1, obj2, obj3;
    obj1.intVal = 5;
    obj1.stringVal = "Object 1";
    obj2.intVal = 10;
    obj2.stringVal = "Object 2";
    obj2.listVal.push_back(obj1);
    obj3.intVal = 15;
    obj3.stringVal = "Object 3";
    obj3.listVal.push_back(obj2);
    vector<objectdef> listVal;
    listVal.push_back(obj1);
    listVal.push_back(obj2);
    listVal.push_back(obj3);
    printListVal(listVal);
    pass();

    cout << "Route Operation - NO OP" << endl;
    routeOperation(NO_OP, state0);
    pass();

    cout << "Route Operation - DEFINE OP" << endl;
    routeOperation(DEFINE_VALUE, state0);
    if (state0.size() == 1) { pass(); }
    else { fail(); }

    cout << "Route Operation - SHOW OP" << endl;
    routeOperation(SHOW_VALUE, state0);
    pass();

    cout << "Route Operation - DELETE OP" << endl;
    routeOperation(DELETE_VALUE, state0);
    if (state0.size() == 0) { pass(); }
    else { fail(); }

    cout << "Testing Done" << endl;
    cout << "Pasing: " << passnum << endl;
    cout << "Failing: " << failsnum << endl;
}