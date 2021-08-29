#ifndef ACTIONS_H
#define ACTIONS_H
#include "Compiler.h"

struct ExecutionState;

class Action{
    public:
        /* exec methods take and modify the current state, 
        and return integer of how far to move in the 
        model vector. */
        virtual int exec(ExecutionState& state) = 0;
};

class LoopAction : public Action {
    public:
        LoopAction(int looplength);
    protected:
        int looplength;
};

class Increment : public Action {
    public:
        virtual int exec(ExecutionState& state);
};

class Decrement : public Action {
    public:
        virtual int exec(ExecutionState& state);
};

class Advance : public Action {
    public:
        virtual int exec(ExecutionState& state);
};

class Backtrack : public Action {
    public:
        virtual int exec(ExecutionState& state);
};

class PointerValue : public Action {
    public:
        virtual int exec(ExecutionState& state);
};

class LoopStart : public LoopAction {
    public:
        LoopStart(int looplength);
        virtual int exec(ExecutionState& state);
};

class LoopEnd : public LoopAction {
    public:
        LoopEnd(int looplength);
        virtual int exec(ExecutionState& state);
};

#endif