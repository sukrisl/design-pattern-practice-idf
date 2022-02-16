#pragma once

#include "State.h"
#include "Context.h"

class Context;
class State;

class Command {
 protected:
    Context* context_;
    State* state_;
 public:
    virtual ~Command() {}
    void setContext(Context* o);
    virtual void execute() = 0;
};

class CommandA : public Command {
 public:
    void execute() override;
};

class CommandB : public Command {
 public:
    void execute() override;
};