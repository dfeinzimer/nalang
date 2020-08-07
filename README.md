# nalang
A natural language.


## Compilation

`g++ -std=c++11 -o nalang main.cpp repl.cpp operate.cpp pos.cpp recommender.cpp test.cpp utils.cpp`


## Usage

Normal mode: `./nalang`.

Debug mode: `./nalang -d`.

Run tests: `./nalang -t`.

## Syntax

In nalang a valid statment begins with a capital alphabetic character and ends with a period.

Valid: `This is a statement.`

Invalid: `This is not a statement`