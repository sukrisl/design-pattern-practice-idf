#pragma once

#include "Context.h"

class Context;

class State {
 protected:
    Context* context_;

 public:
    virtual ~State() {}

    void setContext(Context* o) {
        this->context_ = o;
    }

    virtual void eventA() = 0;
    virtual void eventB() = 0;
};

class StateA : public State {
 public:
    void eventA() override;
    void eventB() override;
};

class StateB : public State {
 public:
    void eventA() override;
    void eventB() override;
};