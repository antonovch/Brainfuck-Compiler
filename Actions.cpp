#include "Actions.h"
#include <iostream>

int Increment::exec(ExecutionState& state){
    state.data[state.pointer]++;
    return 1;
}

int Decrement::exec(ExecutionState& state){
    state.data[state.pointer]--;
    return 1;
}

int Advance::exec(ExecutionState& state){
    if (state.pointer < MAX_SIZE){
        state.pointer++;
    } 
    else{
        throw runtime_error("Cannot advance past the limit of the ExecutionState.data array.");
    }
    return 1;
}

int Backtrack::exec(ExecutionState& state){
    if (state.pointer > 0){
        state.pointer--;
    } 
    else{
        throw runtime_error("Cannot backtrack before the beginning of the ExecutionState.data array.");
    }
    return 1;
}

int PointerValue::exec(ExecutionState& state){
    std:cout << state.getCurrentValue();
    return 1;
}

LoopAction::LoopAction(int len) : looplength(len){ }

LoopStart::LoopStart(int len) : LoopAction(len){ }

LoopEnd::LoopEnd(int len) : LoopAction(len){ }

int LoopStart::exec(ExecutionState& state){
    if (!state.getCurrentValue()){
        return looplength;
    }
    else
    {
        return 1;
    }
}

int LoopEnd::exec(ExecutionState& state){
    if (state.getCurrentValue()){
        return -looplength;
    }
    else
    {
        return 1;
    }
}