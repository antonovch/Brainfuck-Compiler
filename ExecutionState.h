#define EXECUTIONSTATE_H
#ifndef EXECUTIONSTATE_H
#include "Compiler.h"

struct ExecutionState{
    char data[MAX_SIZE]; // array that keeps the data for manipulation
    unsigned int pointer; // current cursor position in data array
    char getCurrentValue(){
        return data[pointer];
    }
};

#endif