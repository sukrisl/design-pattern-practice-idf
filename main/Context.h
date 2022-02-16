#pragma once

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "State.h"
#include "Command.h"

class Command;
class State;

class Context {
 private:
    State* state_ = NULL;
    Command* cmd_ = NULL;

    TaskHandle_t contextTaskHandle = NULL;

 public:
    Context(State* initialState) {
        this->changeState(initialState);
    }

    void sendCommand(Command* cmd);
    static void taskContext(void* pvParam);
    void init();
    void changeState(State* state);
    State* getState() { return state_; }
};