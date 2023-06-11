#include <stdio.h> 
#include <string.h> 

/* FreeRTOS.org includes. */
#include "FreeRTOS.h"
#include "task.h"

/* Demo includes. */
#include "supporting_functions.h"

/* The task functions. */
void vTask1(void *pvParameters);
BaseType_t prvExampleTaskHook(void* pvParameter);

int main(void)
{	

	vPrintString("Test of the vTaskSetApplicationTaskTag() and xTaskCallApplicationTaskHook()\n");
	vPrintString("----------------------------------------\n\n");
	vPrintString("Start task1 with test1\n");

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
	vTaskSetApplicationTaskTag(NULL, prvExampleTaskHook);
	
	uint32_t execTimeCounter = 0;

	vPrintString("\nStart test1\n");

	for (uint32_t i = 0;;i++) {
		
		if (execTimeCounter >= 5) {
			break;
		}

		vPrintString("\nTest1 is running...\n");

		execTimeCounter++;
		
		vPrintString("Test1 is blocked for 1000ms\n");

		vTaskDelay(pdMS_TO_TICKS( 1000 ));
	}

	xTaskCallApplicationTaskHook(NULL, execTimeCounter);
	 
	vPrintString("Task 1 with the test1 is finished");
}

// define a hook (callback) function
// print the name of the function and the number of times it was executed
static BaseType_t prvExampleTaskHook(void* pvParameter)
{
	uint32_t *funcExecTime = pvParameter;

	char msg[100];

	sprintf(msg, "\nTest1 was executed %d times (TaskHookFunction)\n", funcExecTime);

	vPrintString(msg);

	return 0;
}