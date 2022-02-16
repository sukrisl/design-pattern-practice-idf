#include "State.h"

void StateA::eventA() {
    printf("State A, Event A\n");
    printf("Stay on state A\n\n");
}

void StateA::eventB() {
    printf("State A, Event B\n");
    printf("Transitioning to B\n\n");
    this->context_->changeState(new StateB);
}

void StateB::eventA() {
    printf("State B, Event A\n");
    printf("Transitioning to A\n\n");
    this->context_->changeState(new StateA);
}

void StateB::eventB() {
    printf("State B, Event B\n");
    printf("Stay on state B\n\n");
}