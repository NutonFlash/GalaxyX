#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"

// Task handles
TaskHandle_t task1Handle, task2Handle;

// Task 1
void vTask1(void* pvParameters) {
    const TickType_t xDelay = pdMS_TO_TICKS(1000);

    while (1) {
        // Wait for a notification from Task 2
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);

        // Notification received, do something
        printf("Task 1: TimeOut occured!\n");

        // Delay for 1 second
        vTaskDelay(xDelay);
    }
}

// Task 2
void vTask2(void* pvParameters) {
    const TickType_t xDelay = pdMS_TO_TICKS(2000);

    while (1) {
        // Send a notification to Task 1
        xTaskNotifyGive(task1Handle);

        // Delay for 2 seconds
        vTaskDelay(xDelay);
    }
}

int main(void) {
    // Create Task 1
    xTaskCreate(vTask1, "Task 1", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, &task1Handle);

    // Create Task 2
    xTaskCreate(vTask2, "Task 2", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, &task2Handle);

    // Start the FreeRTOS scheduler
    vTaskStartScheduler();

    // Should never reach here
    return 0;
}
