#ifndef COMPILER_H
#define COMPILER_H
#include <string>
#include <vector>
#include <memory>
#include "Actions.h"
using namespace std;

class Action;

struct ExecutionState{
    vector<char> data{0}; // vector to keep the data for manipulation in
    unsigned int current_index = 0; // current cursor position in data array
    char getCurrentValue(){
        return data[current_index];
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