#include "Actions.h"
#include <iostream>

int Increment::exec(ExecutionState& state){
    ++(*state.it);
    return 1;
}

int Decrement::exec(ExecutionState& state){
    --(*state.it);
    return 1;
}

int Advance::exec(ExecutionState& state){
    if (state.it == state.data.end()){
        state.data.push_back(0);
    } 
    ++state.it;
    return 1;
}

int Backtrack::exec(ExecutionState& state){
    if (state.it != state.data.begin()){
        --state.it;
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