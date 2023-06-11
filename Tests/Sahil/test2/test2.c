#include <stdio.h> 
#include <string.h> 

/* FreeRTOS.org includes. */
#include "FreeRTOS.h"
#include "task.h"

/* Demo includes. */
#include "supporting_functions.h"

/* The task functions. */
void vTask1(void *pvParameters);
void vTask2(void* pvParameters);

int main(void)
{
	vPrintString("Test of the eTaskGetState()\n");
	vPrintString("--------------------------\n\n");
	vPrintString("Start task1\n");
	vPrintString("Start task2 with test2\n");

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
	
	for (int i = 0; i < 3; i++) {

		vPrintString("Task 1 is running\n");

		vPrintString("Task 1 is in the blocked state for 3000ms\n\n");

		vTaskDelay(pdMS_TO_TICKS(3000));
	}

	vPrintString("\nTask 1 is finished\n");
}

void vTask2(void* pvParameters)
{

	for (int i = 0; i < 10; i++) {

		vPrintString("Test 2 is running...\n");

		TaskHandle_t task1Handle = xTaskGetHandle("Task 1");
		eTaskState task1State = eTaskGetState(task1Handle);

		char msg[100];
		char* task1StateStr;

		switch (task1State) {
			case eRunning:
				task1StateStr = "eRunning";
				break;
			case eReady:
				task1StateStr = "eReady";
				break;
			case eBlocked:
				task1StateStr = "eBlocked";
				break;
			case eSuspended:
				task1StateStr = "eSuspended";
				break;
			case eDeleted:
				task1StateStr = "eDeleted";
				break;
			case eInvalid:
				task1StateStr = "eInvalid";
				break;
			default:
				task1StateStr = "unknown";
		}

		sprintf(msg, "Task 1 state: %s\n", task1StateStr);

		vPrintString(msg);

		vPrintString("Task 2 is in the blocked state for 1000ms\n\n");

		vTaskDelay(pdMS_TO_TICKS(1000));
	}

	vPrintString("\nTask 2 with the test2 is finished\n");
}
