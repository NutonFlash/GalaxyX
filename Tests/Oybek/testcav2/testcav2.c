#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"

// Task-specific data structure
typedef struct
{
    int taskData;
} TaskData;

// Task 1
void vTask1(void* pvParameters)
{
    TaskData taskData;
    taskData.taskData = 123;

    // Set thread-local storage pointer for Task 1
    xTaskSetThreadLocalStoragePointer(NULL, &taskData);

    while (1)
    {
        // Access and use task-specific data
        TaskData* pData = (TaskData*)xTaskGetThreadLocalStoragePointer(NULL);
        printf("Task 1 data: %d\n", pData->taskData);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

// Task 2
void vTask2(void* pvParameters)
{
    TaskData taskData;
    taskData.taskData = 456;

    // Set thread-local storage pointer for Task 2
    xTaskSetThreadLocalStoragePointer(NULL, &taskData);

    while (1)
    {
        // Access and use task-specific data
        TaskData* pData = (TaskData*)xTaskGetThreadLocalStoragePointer(NULL);
        printf("Task 2 data: %d\n", pData->taskData);
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}

int main(void)
{
    // Create Task 1
    xTaskCreate(vTask1, "Task 1", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);

    // Create Task 2
    xTaskCreate(vTask2, "Task 2", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 2, NULL);

    // Start the FreeRTOS scheduler
    vTaskStartScheduler();

    return 0;
}
