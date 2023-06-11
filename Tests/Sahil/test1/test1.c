#include <stdio.h> 
#include <string.h> 

/* FreeRTOS.org includes. */
#include "FreeRTOS.h"
#include "task.h"

/* Demo includes. */
#include "supporting_functions.h"

/* The task functions. */
void vTask1(void* pvParameters);
void vTask2(void* pvParameters);

int main(void)
{	

	vPrintString("Test of the xTaskAbortDelay()\n");
	vPrintString("----------------------------------------\n\n");
	vPrintString("Start task1\n");
	vPrintString("Start task2 with test1\n");

	TaskHandle_t task1Hadle;

	/* Create one of the two tasks. */
	xTaskCreate(vTask1,	  /* Pointer to the function that implements the task. */
				"Task 1", /* Text name for the task.  This is to facilitate debugging only. */
				100,	  /* Stack depth - most small microcontrollers will use much less stack than this. */
				NULL,	  /* We are not using the task parameter. */
				1,		  /* This task will run at priority 1. */
				&task1Hadle);	  /* We are not using the task handle. */

	xTaskCreate(vTask2, "Task 2", 100, task1Hadle, 1, NULL);

	/* Start the scheduler to start the tasks executing. */
	vTaskStartScheduler();

	for (;;)
		;
	return 0;
}

void vTask1(void *pvParameters)
{

	for (;;) {

		vPrintString("\nTask1 is running\n");

		vPrintString("Task1 is blocked for 20000ms\n");

		vTaskDelay(pdMS_TO_TICKS( 20000 ));

		break;

	}
	vPrintString("\nTask 1 is finished\n");
}

void vTask2(void* pvParameters) 
{

	vPrintString("\nStart test1\n");

	TaskHandle_t taskHandle = xTaskGetHandle("Task 1");

	for (;;) {

		vTaskDelay(pdMS_TO_TICKS(1500));

		vPrintString("\nTest1 is running...\n");

		vPrintString("Try to call xTaskAbortDelay() for Task 1\n");
		
		char* taskName = pcTaskGetName(taskHandle);

		eTaskState state = eTaskGetState(taskHandle);

		BaseType_t abort = xTaskAbortDelay(taskHandle);

		vPrintString("xTaskAbortDelay() for Task 1 was executed successfully\n");
		
		break;
		
	}
	vPrintString("Task 2 with the test1 is finished");
}