#include <stdio.h> 
#include <string.h> 
#include <math.h>

/* FreeRTOS.org includes. */
#include "FreeRTOS.h"
#include "task.h"

/* Demo includes. */
#include "supporting_functions.h"

/* The task functions. */
void vTask1(void *pvParameters);
void vTask2(void* pvParameters);
void vTask3(void* pvParameters);

int main(void)
{
	vPrintString("Test of the xTaskGetHandle() and vTaskGetTaskInfo()\n");
	vPrintString("----------------------------------------\n\n");

	vPrintString("Start task1\n");
	/* Create one of the two tasks. */
	xTaskCreate(vTask1,	  /* Pointer to the function that implements the task. */
				"Task 1", /* Text name for the task.  This is to facilitate debugging only. */
				100,	  /* Stack depth - most small microcontrollers will use much less stack than this. */
				NULL,	  /* We are not using the task parameter. */
				1,		  /* This task will run at priority 1. */
				NULL);	  /* We are not using the task handle. */

	vPrintString("Start task2\n");
	xTaskCreate(vTask2, "Task 2", 100, NULL, 1, NULL);

	vPrintString("Start task3 with test5\n");
	xTaskCreate(vTask3, "Task 3", 100, NULL, 1, NULL);
	/* Start the scheduler to start the tasks executing. */
	vTaskStartScheduler();

	for (;;)
		;
	return 0;
}

void vTask1(void *pvParameters)
{

	for (uint32_t i = 0;;i++) {
		vPrintString("\nTask1 is running...\n");
		
		if (i > 0) {
			uint32_t factorial = 1;

			for (uint32_t k = 1; k <= i; k++) {
				factorial *= k;
			}

			char msg[100];

			sprintf(msg, "Iteration number = %d;\tfactorial(%d) = %d\n", i, i, factorial);

			vPrintString(msg);
		}

		if (i == 2) {
			break;
		}

		vPrintString("Task1 is in the blocked state for 1000ms\n\n");
		vTaskDelay(pdMS_TO_TICKS(1000));
	}
	vPrintString("Task 1 is finished\n");
}

void vTask2(void* pvParameters)
{

	for (uint32_t i = 0;; i++) {
		vPrintString("\nTask2 is running...\n");

		if (i > 0) {
			double pow_of_two = pow(i, 2);

			char msg[100];

			sprintf(msg, "Iteration number = %d;\t%d^2 = %lf\n", i, i, pow_of_two);

			vPrintString(msg);
		}

		if (i == 2) {
			break;
		}

		vPrintString("Task2 is in the blocked state for 1000ms\n\n");
		vTaskDelay(pdMS_TO_TICKS(1000));
	}
	vPrintString("Task 2 is finished\n");
}

void vTask3(void* pvParameters)
{

	vPrintString("\nStart test5\n");

	vPrintString("Get Task 1 handle\n");
	TaskHandle_t xHandle = xTaskGetHandle("Task 1");

	for (uint32_t i = 0;; i++) {

		vPrintString("\nTest5 is running...\n");

		TaskStatus_t xTaskDetails;
		
		vTaskGetTaskInfo(xHandle, &xTaskDetails, pdTRUE, eInvalid);

		char msg[300];

		char* state_str;
		
		switch (xTaskDetails.eCurrentState) {
			case eRunning:
				state_str = "eRunning";
				break;
			case eReady:
				state_str = "eReady";
				break;
			case eBlocked:
				state_str = "eBlocked";
				break;
			case eSuspended:
				state_str = "eSuspended";
				break;
			case eDeleted:
				state_str = "eDeleted";
				break;
			default:
				state_str = "unknown";
		}

		sprintf(msg, "\nInformation about Task 1:\nName: %s\tTask state: %s\nBase task priority: %d\tCurrent task priority: %d\nTask run time: %d\tMinimum amount of stack space: %d\n", xTaskDetails.pcTaskName, state_str, xTaskDetails.uxBasePriority, xTaskDetails.uxCurrentPriority, xTaskDetails.ulRunTimeCounter, xTaskDetails.usStackHighWaterMark);

		vPrintString(msg);

		vPrintString("\nTest5 is in the blocked state for 3000ms\n");
		vTaskDelay(pdMS_TO_TICKS(3000));

		if (i == 1) {
			break;
		}
		
	}
	vPrintString("Task 3 with the test5 is finished\n");
}