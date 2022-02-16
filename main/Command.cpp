#include "Command.h"

void Command::setContext(Context* o) {
    context_ = o;
    state_ = context_->getState();
}

void CommandA::execute() {
    printf("Command A!\n");
    state_->eventA();
}

void CommandB::execute() {
    printf("Command B!\n");
    state_->eventB();
}