#include <iostream>
#include "repl.h"

using namespace std;

int main() {
    while (true) {
        prompt();
        string input = read();
        print(input);
    }
    return 0;
}