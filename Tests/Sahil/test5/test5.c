#include <stdio.h> 
#include <string.h> 

/* FreeRTOS.org includes. */
#include "FreeRTOS.h"
#include "task.h"
#include <stdbool.h>

/* Demo includes. */
#include "supporting_functions.h"

/* The task functions. */
void vTask1(void *pvParameters);
void vTask2(void* pvParameters);

int main(void)
{
	vPrintString("Test of the vTaskSuspend()\n");
	vPrintString("------------------------\n\n");
	vPrintString("Start Task 1 with test5\n");
	vPrintString("Start Task 2\n");

	/* Create one of the two tasks. */
	xTaskCreate(vTask1,	  /* Pointer to the function that implements the task. */
				"Task 1", /* Text name for the task.  This is to facilitate debugging only. */
				100,	  /* Stack depth - most small microcontrollers will use much less stack than this. */
				NULL,	  /* We are not using the task parameter. */
				1,		  /* This task will run at priority 1. */
				NULL);	  /* We are not using the task handle. */

	xTaskCreate(vTask2, "Task 2", 100, NULL, 1, NULL);
	/* Start the scheduler to start the tasks executing. */
	vTaskStartScheduler();

	for (;;)
		;
	return 0;
}

void vTask1(void *pvParameters)
{
	for (int i = 0;;i++) {
		vPrintString("\nTask 1 is running\n");

		if (i == 2) {
			vPrintString("\nTask 1 is suspended\n");
			vTaskSuspend(NULL);
		}

		vPrintString("Task 1 is blocked for 3000ms\n");

		vTaskDelay(pdMS_TO_TICKS(3000));
	}
}

void vTask2(void* pvParameters) {
	for (;;) {
		vPrintString("\nTask 2 is running\n");

		vPrintString("Task 2 is blocked for 3000ms\n");

		vTaskDelay(pdMS_TO_TICKS(3000));
	}
}