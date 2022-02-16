#include "Context.h"

void Context::sendCommand(Command* cmd) {
    if (this->cmd_ != NULL) delete this->cmd_;
    cmd_ = cmd;
    cmd_->setContext(this);
    xTaskNotifyGive(contextTaskHandle);
}

void Context::taskContext(void* pvParam) {
    Context *self = static_cast<Context*>(pvParam);
    for (;;) {
        if (ulTaskNotifyTake(pdTRUE, 0) > 0) self->cmd_->execute();;
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}

void Context::init() {
    xTaskCreatePinnedToCore(
        taskContext,
        "Context task",
        1024 * 4,
        this,
        5,
        &contextTaskHandle,
        1
    );
}

void Context::changeState(State* state) {
    if (state_ != NULL) delete this->state_;
    state_ = state;
    state_->setContext(this); 
}