#include <stdio.h> 
#include <string.h> 

/* FreeRTOS.org includes. */
#include "FreeRTOS.h"
#include "task.h"

/* Demo includes. */
#include "supporting_functions.h"

#define mainDELAY_LOOP_COUNT		( 0xffffff )

void vTask1(void* pvParameters);

int main(void) {

    vPrintString("Test of the xTaskGetTickCount()\n");
    vPrintString("----------------------------------------\n\n");
    vPrintString("Start task1 with test3\n");

    xTaskCreate(vTask1, "Task 1", 100, NULL, 1, NULL);

    vTaskStartScheduler();

    for (;;);
    return 0;
}


void vTask1(void* pvParameters)
{
    TickType_t xTime1, xTime2, xExecutionTime;

    vPrintString("\nStart test3\n");

    for (uint32_t i = 0;; i++) {

        xTime1 = xTaskGetTickCount();
        Sleep(10);

        vPrintString("Test3 is blocked for 1000ms\n");
        vTaskDelay(pdMS_TO_TICKS(1000));

        xTime2 = xTaskGetTickCount();
        xExecutionTime = xTime2 - xTime1;
        printf("Elapsed time: %u ticks\n", xExecutionTime);
    }
    
    vPrintString("Task 1 with the test3 is finished");

}
