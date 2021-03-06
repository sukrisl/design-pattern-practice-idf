/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "esp_log.h"

#include "Context.h"
#include "Command.h"
#include "State.h"

extern "C" void app_main(void) {
    Context* context = new Context(new StateB);
    context->init();
    vTaskDelay(1000 / portTICK_PERIOD_MS);

    // State B to A
    context->sendCommand(new CommandA);
    vTaskDelay(1000 / portTICK_PERIOD_MS);

    // State A to B
    context->sendCommand(new CommandB);
    vTaskDelay(1000 / portTICK_PERIOD_MS);

    // Stay on state B
    context->sendCommand(new CommandB);
    vTaskDelay(1000 / portTICK_PERIOD_MS);

    // State B to A
    context->sendCommand(new CommandA);
    vTaskDelay(1000 / portTICK_PERIOD_MS);

    // Stay on state A
    context->sendCommand(new CommandA);
    vTaskDelay(1000 / portTICK_PERIOD_MS);

    // State A to B
    context->sendCommand(new CommandB);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
}
