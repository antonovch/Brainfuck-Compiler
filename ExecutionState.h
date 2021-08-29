#define EXECUTIONSTATE_H
#ifndef EXECUTIONSTATE_H
#include "Compiler.h"

struct ExecutionState{
    char data[MAX_SIZE];
    unsigned int pointer;
    char getCurrentValue(){
        return data[pointer];
    }
};

#endif