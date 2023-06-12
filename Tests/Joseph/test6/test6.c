#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"

#define STACK_SIZE 128
#define PRIORITY 1

void vTaskCode(void* pvParameters) {
    while (1) {
        /* Task code goes here */
        vTaskDelay(pdMS_TO_TICKS(1000)); // Delay for 1 second
    }
}

void vAFunction(void) {
    TaskHandle_t xHandle = NULL;

    /* Create a task, storing the handle to the created task in xHandle. */
    if (xTaskCreate(vTaskCode, "Demo task", STACK_SIZE, NULL, PRIORITY, &xHandle) != pdPASS) {
        /* The task was not created successfully. */
        printf("Task creation failed!\n");
    }
    else {
        /* Use the handle to suspend the created task. */
        vTaskSuspend(xHandle);

        /* The suspended task will not run during this period, unless another task calls vTaskResume(xHandle). */

        /* Resume the suspended task again. */
        vTaskResume(xHandle);

        /* The created task is again available to the scheduler and can enter the Running state. */
    }
}

int main() {
    vAFunction();
    vTaskStartScheduler();
    return 0;
}
