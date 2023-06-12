#include <stdio.h>

/* FreeRTOS.org includes. */
#include "FreeRTOS.h"
#include "task.h"

/* Function prototypes */
void vTask1(void* pvParameters);

/* A task that calls vDemoFunction() from within a critical section. */
void vTask1(void* pvParameters)
{
    TickType_t xLastWakeTime = xTaskGetTickCount();

    vPrintString("\nStart test1\n");

    for (;;)
    {

        vPrintString("\nTest1 is running...\n");

        vPrintString("Enter the critical section\n");

        taskENTER_CRITICAL();
     
        vPrintString("Try to turn task in the Blocked state for 10000ms\n");

        vTaskDelay(pdMS_TO_TICKS(10000));

        vPrintString("Test1 is running continuosly\n");

        taskEXIT_CRITICAL();
        
        vPrintString("Exit the critical section\n");
        
        vPrintString("Try to turn task in the Blocked state for 3000ms\n");

        vTaskDelay(pdMS_TO_TICKS(3000));

        vPrintString("Test1 is blocked for 3000ms\n");

        break;
    }

    vPrintString("\nTask 1 with the test1 is finished");
}

/* Main function */
int main()
{
    vPrintString("Test of the taskEXIT_CRITICAL() and taskENTER_CRITICAL()\n");
    vPrintString("----------------------------------------\n\n");
    vPrintString("Start task1 with test1\n");

    /* Create a task that calls vTask1 */
    xTaskCreate(vTask1, "Task1", 100, NULL, 1, NULL);

    /* Start the FreeRTOS scheduler */
    vTaskStartScheduler();

    return 0;
}
