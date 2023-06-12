#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"

// Task function
void task1(void* pvParameters)
{
    // Task code
    vTaskDelay(pdMS_TO_TICKS(1000)); // Delay for 1 second
    printf("Task 1 is running \n");

    vTaskDelete(NULL); // Delete the task
}

void task2(void* pvParameters)
{
    // Task code
    vTaskDelay(pdMS_TO_TICKS(2000)); // Delay for 2 seconds
    printf("Task 2 is running\n");

    vTaskDelete(NULL); // Delete the task
}

int main()
{
    // Initialize FreeRTOS

    // Create tasks
    xTaskCreate(task1, "Task 1", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    xTaskCreate(task2, "Task 2", configMINIMAL_STACK_SIZE, NULL, 1, NULL);

    // Call uxTaskGetNumberOfTasks() to get the total number of tasks
    UBaseType_t taskCount = uxTaskGetNumberOfTasks();
    printf("Test of the uxTaskGetNumberOfTasks()\n");
    printf("------------------------------------\n\n");
    printf("Counting the number of tasks running\n");
    printf("Total number of tasks: %u\n", taskCount);


    // Start the scheduler
    vTaskStartScheduler();

    // The scheduler will now start running the tasks

    while (1)
    {
        // Code inside the idle task
    }

    return 0;
}
