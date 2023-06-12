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

    vPrintString("Test of the pcTaskGetName()\n");
    vPrintString("----------------------------------------\n\n");
    vPrintString("Start task1 with test2\n");

    xTaskCreate(vTask1, "Task 1", 100, NULL, 1, NULL);

    vTaskStartScheduler();

    for (;;);
    return 0;
}

void vTask1(void* pvParameters) {
    uint32_t ul = 0;

    vPrintString("\nStart test1\n");

    for (uint32_t i = 0;; i++) {

        const char* taskName = pcTaskGetName(NULL);
        printf("Current Task Name: %s\n", taskName);

        vTaskDelay(pdMS_TO_TICKS(1000));
    }
    vPrintString("Task 1 with the test1 is finished");
}
