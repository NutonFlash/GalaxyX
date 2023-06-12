#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"

void vTask1(void* pvParameters)
{
    TickType_t xTimeOut;

    while (1)
    {
        // Set a timeout of 1000 milliseconds
        vTaskSetTimeOutState(&xTimeOut);
        vTaskDelay(pdMS_TO_TICKS(1000));

        // Perform API operations here...

        // Check if the timeout has occurred
        if (xTaskCheckForTimeOut(&xTimeOut, NULL) == pdTRUE)
        {
            // Timeout occurred
            printf("TimeOut occurred!\n");
        }
        else
        {
            // Timeout not occurred
            printf("No timeout yet.\n");
        }
    }
}

int main(void)
{
    xTaskCreate(vTask1, "Task 1", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);
    vTaskStartScheduler();

    while (1)
    {
        // Main loop
    }

    return 0;
}

