#include <iostream>
#include <stack>
#include "Compiler.h"

Compiler::Compiler(std::string code) : code(code) { }

int Compiler::checkBalancedBracket(){
    int balance(0);
    for (char ch : code){
        switch (ch){
            case '[': 
                ++balance;
                break;
            case ']': 
                --balance;
                break;
            default: 
                break;
        }
    }
    return balance;
}

void Compiler::compile(){
    int balance = checkBalancedBracket();
    if (balance > 0){
        throw invalid_argument("Unbalanced [");
    }
    else if(balance < 0){
        throw invalid_argument("Unbalanced ]");
    }
    const int numCommands = code.length();
    model.resize(numCommands);
    stack<int> loopStartInd;
    for (int i = 0; i < numCommands; i++){
        switch (code[i]){
            case '+': {
                shared_ptr<Action> actn(new Increment());
                model[i] = actn;
                break;
                }
            case '-':{
                shared_ptr<Action> actn(new Decrement());
                model[i] = actn;
                break;
            }
            case '<':{
                shared_ptr<Action> actn(new Backtrack());
                model[i] = actn;
                break;
            }
            case '>':{
                shared_ptr<Action> actn(new Advance());
                model[i] = actn;
                break;
            }
            case '.':{
                shared_ptr<Action> actn(new PointerValue());
                model[i] = actn;
                break;
            }
            case '[':{
                loopStartInd.push(i);
                break;
            }
            case ']':{
                int j = loopStartInd.top();
                loopStartInd.pop();
                int looplength = i - j;
                shared_ptr<Action> actn(new LoopEnd(looplength));
                model[i] = actn;
                shared_ptr<Action> actnstart(new LoopStart(looplength));
                model[j] = actnstart;
                break;
            }
        }
    }
}

void Compiler::run(){
    int move;
    for (int i = 0; i < model.size();){
        move = model[i]->exec(state);
        i += move;
    }
}