#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"

// Task handle for Task 1
TaskHandle_t xTask1Handle;

// Task 1
void vTask1(void* pvParameters)
{
    const TickType_t xDelay = pdMS_TO_TICKS(2000);
    uint32_t ulNotifiedValue;

    while (1)
    {
        printf("Task 1: Waiting for notification...\n");

        // Wait for the notification from Task 2
        ulNotifiedValue = ulTaskNotifyTake(pdTRUE, portMAX_DELAY);

        if (ulNotifiedValue > 0)
        {
            printf("Task 1: Received notification with value %lu\n", ulNotifiedValue);
        }

        vTaskDelay(xDelay);
    }
}

// Task 2
void vTask2(void* pvParameters)
{
    const TickType_t xDelay = pdMS_TO_TICKS(5000);
    uint32_t ulValueToSend = 123;

    while (1)
    {
        printf("Task 2: Sending notification with value %lu\n", ulValueToSend);

        // Send the notification to Task 1
        xTaskNotify(xTask1Handle, ulValueToSend, eSetValueWithOverwrite);

        vTaskDelay(xDelay);
    }
}

int main(void)
{
    // Create Task 1
    xTaskCreate(vTask1, "Task 1", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, &xTask1Handle);

    // Create Task 2
    xTaskCreate(vTask2, "Task 2", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 2, NULL);

    // Start the FreeRTOS scheduler
    vTaskStartScheduler();

    return 0;
}
