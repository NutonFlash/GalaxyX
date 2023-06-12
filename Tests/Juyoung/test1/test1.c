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

    vPrintString("Test of the pvTaskGetThreadLocalStoragePointer() and vTaskSetThreadLocalStoragePointer()\n");
    vPrintString("----------------------------------------\n\n");
    vPrintString("Start task1 with test1\n");

    xTaskCreate(vTask1, "Task 1", 100, NULL, 1, NULL);

    vTaskStartScheduler();

    for (;;);
    return 0;
}


void vTask1(void* pvParameters)
{
    int array[] = {1, 2, 3 , 4};

    vTaskSetThreadLocalStoragePointer(NULL, 0, &array);
    int* array_pointer = 0;

    vPrintString("\nStart test1\n");

    for (uint32_t i = 0;i < sizeof(*array); i++) {

        char str[100];
        array_pointer = pvTaskGetThreadLocalStoragePointer(NULL, 0);
        sprintf(str, "The number we get: %d\r\n", array_pointer[i]);

        vPrintString("\nTest1 is running...\n");
     
        vPrintString(str);

        vPrintString("Test1 is blocked for 1000ms\n");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }

    vPrintString("Task 1 with the test1 is finished");

}
