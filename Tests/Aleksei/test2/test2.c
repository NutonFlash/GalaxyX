#include <stdio.h> 
#include <string.h> 

/* FreeRTOS.org includes. */
#include "FreeRTOS.h"
#include "task.h"

/* Demo includes. */
#include "supporting_functions.h"

/* The task functions. */
void vTask1(void *pvParameters);
void vTaskSetTimeOutState(TimeOut_t* const pxTimeOut);

int main(void)
{
	vPrintString("Test of the vTaskSetTimeOutState() and xTaskCheckForTimeOut()\n");
	vPrintString("----------------------------------------\n\n");
	vPrintString("Start task1 with test2\n");

	/* Create one of the two tasks. */
	xTaskCreate(vTask1,	  /* Pointer to the function that implements the task. */
				"Task 1", /* Text name for the task.  This is to facilitate debugging only. */
				100,	  /* Stack depth - most small microcontrollers will use much less stack than this. */
				NULL,	  /* We are not using the task parameter. */
				1,		  /* This task will run at priority 1. */
				NULL);	  /* We are not using the task handle. */

	/* Start the scheduler to start the tasks executing. */
	vTaskStartScheduler();

	for (;;)
		;
	return 0;
}

void vTask1(void *pvParameters)
{
	TimeOut_t xtimeOut;
	TickType_t xTicksToWait = pdMS_TO_TICKS(3500);
	
	vTaskSetTimeOutState(&xtimeOut);

	vPrintString("\nStart test2\n");

	vPrintString("Initialize timeOutState for test2\n\n");
	

	for (;;) {
		if (xTaskCheckForTimeOut(&xtimeOut, &xTicksToWait) != pdFALSE) {
			vPrintString("Task is timed out due to exceeds ticks to wait limit\n");
			break;
		}

		vPrintString("Test2 is running...\n");

		vPrintString("Test2 is in the blocked state for 1000ms\n\n");
		vTaskDelay(pdMS_TO_TICKS(1000));
	}
	vPrintString("Task 1 with the test2 is finished");
}


