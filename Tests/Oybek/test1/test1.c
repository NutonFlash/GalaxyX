#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"

TaskHandle_t taskHandle1, taskHandle2;

void vTask1(void* pvParameters) {
    const TickType_t xDelay = pdMS_TO_TICKS(1000);
    const TickType_t xMaxBlockTime = pdMS_TO_TICKS(200);

    while (1) {
        printf("Task 1: Waiting for notification...\n");

        // Wait for a notification from Task 2
        ulTaskNotifyTake(pdTRUE, xMaxBlockTime);

        printf("Task 1: Received notification!\n");

        vTaskDelay(xDelay);
    }
}

void vTask2(void* pvParameters) {
    const TickType_t xDelay = pdMS_TO_TICKS(2000);

    while (1) {
        printf("Task 2: Sending notification...\n");

        // Send a notification to Task 1
        xTaskNotifyGive(taskHandle1);

        printf("Task 2: Notification sent!\n");

        vTaskDelay(xDelay);
    }
}

int main(void) {
    xTaskCreate(vTask1, "Task 1", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, &taskHandle1);
    xTaskCreate(vTask2, "Task 2", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, &taskHandle2);

    vTaskStartScheduler();

    return 0;
}
