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
    vector<char>::iterator it = data.begin(); // current cursor position in data array
    char& getCurrentValue(){
        return *it;
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