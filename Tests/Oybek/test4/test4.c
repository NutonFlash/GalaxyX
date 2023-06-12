#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"

TaskHandle_t taskHandle1;
TaskHandle_t taskHandle2;

void vTask1(void* pvParameters) {
    while (1) {
        // Wait for a notification
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);

        // Notification received
        printf("Task 1: Notification received!\n");
    }
}

void vTask2(void* pvParameters) {
    while (1) {
        // Perform some work

        // Give a notification to Task 1
        xTaskNotifyGive(taskHandle1);

        // Delay before giving another notification
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

int main(void) {
    // Create Task 1
    xTaskCreate(vTask1, "Task 1", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, &taskHandle1);

    // Create Task 2
    xTaskCreate(vTask2, "Task 2", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, &taskHandle2);

    // Start the scheduler
    vTaskStartScheduler();

    // If the scheduler starts, something went wrong
    printf("Error starting FreeRTOS scheduler!\n");

    return 0;
}
