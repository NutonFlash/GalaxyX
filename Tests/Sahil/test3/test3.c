#include <stdio.h> 
#include <string.h> 

/* FreeRTOS.org includes. */
#include "FreeRTOS.h"
#include "task.h"
#include <stdbool.h>

/* Demo includes. */
#include "supporting_functions.h"

#define STACK_SIZE 100

/* The task functions. */
void vTask1(void *pvParameters);
void increaseStackUse();

int main(void)
{
	vPrintString("Test of the uxTaskGetStackHighWaterMark()\n");
	vPrintString("--------------------------\n\n");
	vPrintString("Start task1 with test3\n");

	char msg[100];

	sprintf(msg, "Task 1 was assigned with %d stack size", STACK_SIZE);

	/* Create one of the two tasks. */
	xTaskCreate(vTask1,	  /* Pointer to the function that implements the task. */
				"Task 1", /* Text name for the task.  This is to facilitate debugging only. */
				STACK_SIZE,	  /* Stack depth - most small microcontrollers will use much less stack than this. */
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

	char msg[100];

	UBaseType_t stackHighWaterMark;

	vPrintString("Test 3 is running...\n");
	
	uint_fast64_t x1 = 1000;
	uint_fast64_t x2 = 1000;
	uint_fast64_t x3 = 1000;

	stackHighWaterMark = uxTaskGetStackHighWaterMark(NULL);
	sprintf(msg, "stackHighWaterMark after task initialization: %d\n", stackHighWaterMark);
	vPrintString(msg);

	increaseStackUse();

	vPrintString("\nTask 1 with test3 is finished\n");
}

void increaseStackUse() {
	int32_t x1 = 1000;
	int32_t x2 = 1000;
	int32_t x3 = 1000;
	int32_t x4 = 1000;
	int32_t x5 = 1000;

	char msg[100];
	UBaseType_t stackHighWaterMark = uxTaskGetStackHighWaterMark(NULL);
	sprintf(msg, "stackHighWaterMark after calling nested function: %d\n", stackHighWaterMark);
	vPrintString(msg);
}