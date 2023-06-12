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

    vPrintString("Test of the uxTaskPriorityGet() and vTaskPrioritySet()\n");
    vPrintString("----------------------------------------\n\n");
    vPrintString("Start task1 with test6\n");

    xTaskCreate(vTask1, "Task 1", 100, NULL, 1, NULL);

    vTaskStartScheduler();

    for (;;);
    return 0;
}


void vTask1(void* pvParameters)
{
    vPrintString("\nStart test1\n");

    for (uint32_t i = 0; i < 3; i++) {
        UBaseType_t priority = uxTaskPriorityGet(NULL); // 현재 태스크의 우선순위를 가져옴
        printf("Task 1 priority: %u\n", priority);

        // 우선순위 변경
        vTaskPrioritySet(NULL, configMAX_PRIORITIES - 1);

        vPrintString("Test1 is blocked for 1000ms\n");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }

    vPrintString("Task 1 with the test6 is finished");

}

