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
    char data[MAX_SIZE]; // array that keeps the data for manipulation
    unsigned int pointer = 0; // current cursor position in data array
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
        void run();
        int checkBalancedBracket();

    private:
        string code;
        vector<shared_ptr<Action>> model;
        ExecutionState state;
};



#endif