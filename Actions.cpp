#include "Actions.h"
#include <iostream>

int Increment::exec(ExecutionState& es){
    es.data[es.pointer]++;
    return 1;
}

int Decrement::exec(ExecutionState& es){
    es.data[es.pointer]--;
    return 1;
}

int Advance::exec(ExecutionState& es){
    if (es.pointer < MAX_SIZE){
        es.pointer++;
    } 
    else{
        throw runtime_error("Cannot advance past the limit of the ExecutionState.data array.");
    }
    return 1;
}

int Backtrack::exec(ExecutionState& es){
    if (es.pointer > 0){
        es.pointer--;
    } 
    else{
        throw runtime_error("Cannot backtrack before the beginning of the ExecutionState.data array.");
    }
    return 1;
}

int PointerValue::exec(ExecutionState& es){
    std:cout << es.getCurrentValue();
    return 1;
}

LoopAction::LoopAction(int len) : looplength(len){
}

void LoopAction::setLoopLength(int len){
    looplength = len;
}

LoopStart::LoopStart(int len) : LoopAction(len){ }

LoopEnd::LoopEnd(int len) : LoopAction(len){ }

int LoopStart::exec(ExecutionState& es){
    if (!es.getCurrentValue()){
        return looplength;
    }
    else
    {
        return 1;
    }
}

int LoopEnd::exec(ExecutionState& es){
    if (es.getCurrentValue()){
        return -looplength;
    }
    else
    {
        return 1;
    }
}