#ifndef COMPILER_H
#define COMPILER_H
#include <string>
#include <vector>
#include <memory>
#include "Actions.h"
using namespace std;

class Action;
const int MAX_SIZE = 10000;

struct ExecutionState{
    char data[MAX_SIZE];
    unsigned int pointer = 0;
    char getCurrentValue(){
        return data[pointer];
    }
};

class Compiler
{
    public:
        Compiler() = delete;
        Compiler(string code);
        void compile();
        string run();
        int checkBalancedBracket();

    private:
        string code;
        vector<shared_ptr<Action>> model;
        ExecutionState state;
};



#endif