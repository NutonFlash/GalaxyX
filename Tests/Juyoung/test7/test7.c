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

    vPrintString("Test of the vTaskSuspendAll() and xTaskResumeAll()\n");
    vPrintString("----------------------------------------\n\n");
    vPrintString("Start task1 with test7\n");

    xTaskCreate(vTask1, "Task 1", 100, NULL, 1, NULL);

    vTaskSuspendAll();
    printf("Task scheduling is suspended\n");

    xTaskResumeAll();
    printf("Task scheduling is resumed\n");

    vTaskStartScheduler();

    for (;;);
    return 0;
}


void vTask1(void* pvParameters) {
    for (uint32_t i = 0;; i++) {
        printf("Task 1 is running\n");

        vPrintString("\nTest7 is running...\n");

        vPrintString("Test7 is blocked for 1000ms\n");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
    vPrintString("Task 1 with the test7 is finished");
}
