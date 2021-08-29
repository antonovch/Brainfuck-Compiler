#ifndef ACTIONS_H
#define ACTIONS_H
#include "Compiler.h"

struct ExecutionState;

class Action{
    public:
        virtual int exec(ExecutionState& es) = 0;
};

class LoopAction : public Action {
    public:
        LoopAction(int looplength);
        void setLoopLength(int looplength);
    protected:
        int looplength;
};

class Increment : public Action {
    public:
        virtual int exec(ExecutionState& es);
};

class Decrement : public Action {
    public:
        virtual int exec(ExecutionState& es);
};

class Advance : public Action {
    public:
        virtual int exec(ExecutionState& es);
};

class Backtrack : public Action {
    public:
        virtual int exec(ExecutionState& es);
};

class PointerValue : public Action {
    public:
        virtual int exec(ExecutionState& es);
};

class LoopStart : public LoopAction {
    public:
        LoopStart(int looplength);
        virtual int exec(ExecutionState& es);
};

class LoopEnd : public LoopAction {
    public:
        LoopEnd(int looplength);
        virtual int exec(ExecutionState& es);
};

#endif