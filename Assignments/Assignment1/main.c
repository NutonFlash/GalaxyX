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
	/* Create one of the two tasks. */
	xTaskCreate(vTask1,	  /* Pointer to the function that implements the task. */
				"Task 1", /* Text name for the task.  This is to facilitate debugging only. */
				100,	  /* Stack depth - most small microcontrollers will use much less stack than this. */
				NULL,	  /* We are not using the task parameter. */
				1,		  /* This task will run at priority 1. */
				NULL);	  /* We are not using the task handle. */

	// xTaskCreate(vTask2, "Task 2", 100, NULL, 1, NULL);

	/* Start the scheduler to start the tasks executing. */
	vTaskStartScheduler();

	for (;;)
		;
	return 0;
}

void vTask1(void *pvParameters)
{
	// taskENTER_CRITICAL();
	
	for (;;) {

		vPrintString("Task1 is running...\n");
		
		vTaskDelay(pdMS_TO_TICKS( 2000 ));

	}
	
	 // taskEXIT_CRITICAL();
}

void vTask2(void* pvParameters)
{
	for (;;) {

		int c;

		printf("\nEnter a value :");
		c = getchar();

		printf("\nYou entered: ");
		putchar(c);

	}
}