#ifndef objectdef_h
#define objectdef_h

#include <string>
#include <vector>

struct objectdef
{
    int intVal;
    std::string stringVal;
    std::vector<objectdef> listVal;
};


#endif