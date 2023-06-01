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
	vPrintString("Test of the uxTaskGetSystemState()\n");
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

	vPrintString("Start task3 with test4\n");
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
	vPrintString("Task 1 is finished");
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
	vPrintString("Task 2 is finished");
}

void vTask3(void* pvParameters)
{

	vPrintString("\nStart test4\n");

	for (uint32_t i = 0;; i++) {

		vPrintString("Test4 is running...\n");

		TaskStatus_t* pxTaskStatusArray;
		volatile UBaseType_t uxArraySize, x;
		unsigned long ulTotalRunTime, ulStatsAsPercentage;
		
		uxArraySize = uxTaskGetNumberOfTasks();
		
		pxTaskStatusArray = pvPortMalloc(uxArraySize * sizeof(TaskStatus_t));

		if (pxTaskStatusArray != NULL) {
			
			uxArraySize = uxTaskGetSystemState(pxTaskStatusArray, uxArraySize, &ulTotalRunTime);

			ulTotalRunTime /= 100UL;

			char msg[150] = "\nTask\t\t\tAbs Time\t% Time\n***********************************************\n";
			
			vPrintString(msg);

			if (ulTotalRunTime > 0) {
				
				for (x = 0; x < uxArraySize; x++) {
					ulStatsAsPercentage = pxTaskStatusArray[x].ulRunTimeCounter / ulTotalRunTime;

					if (ulStatsAsPercentage > 0UL) {
						sprintf(msg, "%s\t\t\t%lu\t\t%lu%%\r\n",
							pxTaskStatusArray[x].pcTaskName,
							pxTaskStatusArray[x].ulRunTimeCounter,
							ulStatsAsPercentage);
					} else {
						sprintf(msg, "%s\t\t\t%lu\t\t<1%%\r\n",
							pxTaskStatusArray[x].pcTaskName,
							pxTaskStatusArray[x].ulRunTimeCounter);
					}

					vPrintString(msg);
				}
			}
			vPortFree(pxTaskStatusArray);
		}
		
		vPrintString("\nTest4 is in the blocked state for 3000ms\n");
		vTaskDelay(pdMS_TO_TICKS(3000));

		if (i == 1) {
			break;
		}
		
	}
	vPrintString("Task 3 with the test4 is finished");
}