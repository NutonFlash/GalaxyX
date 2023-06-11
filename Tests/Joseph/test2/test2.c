#include <stdio.h>

/* FreeRTOS.org includes. */
#include "FreeRTOS.h"
#include "task.h"

/* Function prototypes */
void vTask1(void* pvParameters);
void nestedCritical();

/* A task that calls vDemoFunction() from within a critical section. */
void vTask1(void* pvParameters)
{
    TickType_t xLastWakeTime = xTaskGetTickCount();

    vPrintString("\nStart test2\n");

    UBaseType_t uxSavedInterruptStatus;

    for (;;)
    {

        vPrintString("\nTest2 is running...\n");

        vPrintString("Enter the critical section\n");

        uxSavedInterruptStatus = taskENTER_CRITICAL_FROM_ISR();

        nestedCritical();

        vPrintString("Try to turn task in the Blocked state for 20000ms\n");

        vTaskDelay(pdMS_TO_TICKS(20000));

        vPrintString("Test1 is running continuosly\n");

        taskEXIT_CRITICAL_FROM_ISR(uxSavedInterruptStatus);

        vPrintString("Exit the critical section\n");

        vPrintString("Try to turn task in the Blocked state for 3000ms\n");

        vTaskDelay(pdMS_TO_TICKS(3000));

        vPrintString("Test1 is blocked for 3000ms\n");

        break;
    }

    vPrintString("\nTask 1 with the test1 is finished");
}

void nestedCritical() {

    vPrintString("\nEnter nested critical section\n");

    UBaseType_t uxSavedInterruptStatus = taskENTER_CRITICAL_FROM_ISR();

    vPrintString("Try to turn task in the Blocked state for 20000ms\n");

    vTaskDelay(pdMS_TO_TICKS(20000));

    vPrintString("Test1 is running continuosly\n");

    taskEXIT_CRITICAL_FROM_ISR(uxSavedInterruptStatus);

    vPrintString("Exit the nested critical section\n");
}

/* Main function */
int main()
{
    vPrintString("Test of the taskENTER_CRITICAL_FROM_ISR() and taskEXIT_CRITICAL_FROM_ISR()\n");
    vPrintString("-------------------------------------------------------------------------\n\n");
    vPrintString("Start task1 with test2\n");

    /* Create a task that calls vTask1 */
    xTaskCreate(vTask1, "Task1", 100, NULL, 1, NULL);

    /* Start the FreeRTOS scheduler */
    vTaskStartScheduler();

    return 0;
}
