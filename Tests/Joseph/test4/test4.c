#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"

// Task function
void task1(void* pvParameters)
{
    UBaseType_t priority;

    // Get the priority of this task
    priority = uxTaskPriorityGet(NULL);
    printf("Retrieving Priority of Task 1\n");
    printf("Task 1 priority: %u\n\n", priority);

    vTaskDelete(NULL); // Delete the task
}

void task2(void* pvParameters)
{
    UBaseType_t priority;

    // Get the priority of this task
    priority = uxTaskPriorityGet(NULL);
    printf("Retrieving Priority of Task 2\n");
    printf("Task 2 priority: %u\n\n", priority);

    vTaskDelete(NULL); // Delete the task
}

int main()
{
    // Initialize FreeRTOS

    // Create tasks
    xTaskCreate(task1, "Task 1", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    xTaskCreate(task2, "Task 2", configMINIMAL_STACK_SIZE, NULL, 2, NULL);

    // Start the scheduler
    vTaskStartScheduler();

    // The scheduler will now start running the tasks

    while (1)
    {
        // Code inside the idle task
    }

    return 0;
}
