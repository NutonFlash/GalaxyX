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
void printArray(int* array, int length);

int main(void)
{
	vPrintString("Test of the vTaskSetThreadLocalStoragePointer()\n");
	vPrintString("---------------------------------------------\n\n");

	vPrintString("Start task1\n");
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
	char msg[500];
	sprintf(msg, "Defined number of thread local storage pointers is %d\n", configNUM_THREAD_LOCAL_STORAGE_POINTERS);
	vPrintString(msg);

	int arr1[] = {0, 1};
	int arr2[] = {0, 1, 2};
	int arr3[] = {0, 1, 2, 3};

	for (uint32_t i = 0;;i++) {
		vPrintString("\nTask 1 is running...\n");
		
		switch (i) {
		case 0: {
			int index = 0;

			sprintf(msg, "Set array of integers for %d index (correct parametres)\n", index);
			vPrintString(msg);
			
			vTaskSetThreadLocalStoragePointer(NULL, 0, arr1);
			
			sprintf(msg, "Get value from %d index\n", index);
			vPrintString(msg);
			
			int* getted_num_arr = pvTaskGetThreadLocalStoragePointer(NULL, 0);
			
			if (getted_num_arr == NULL) {
				vPrintString("The returned value is NULL\n");
			}
			else
			{
				vPrintString("Compare initial and getted arrays:\n");
				vPrintString("Initial array - ");
				printArray(arr1, sizeof(arr1) / sizeof(int));
				vPrintString("Getted array - ");
				printArray(getted_num_arr, sizeof(arr1) / sizeof(int));
			}
				break;
		}
		case 1: {
			int index = configNUM_THREAD_LOCAL_STORAGE_POINTERS - 1;

			sprintf(msg, "Set array of integers for %d (max) index\n", index);
			vPrintString(msg);

			vTaskSetThreadLocalStoragePointer(NULL, index, arr3);

			sprintf(msg, "Get value from %d index\n", index);
			vPrintString(msg);

			int* getted_num_arr = pvTaskGetThreadLocalStoragePointer(NULL, index);
			
			if (getted_num_arr == NULL) {
				vPrintString("The returned value is NULL\n");
			}
			else
			{
				vPrintString("Compare initial and getted arrays:\n");
				vPrintString("Initial array - ");
				printArray(arr3, sizeof(arr3) / sizeof(int));
				vPrintString("Getted array - ");
				printArray(getted_num_arr, sizeof(arr3) / sizeof(int));
			}
			break;
		}
		
		case 2: {
			int index = configNUM_THREAD_LOCAL_STORAGE_POINTERS;

			sprintf(msg, "Set array of integers for %d (exceeding) index\n", index);
			vPrintString(msg);

			vTaskSetThreadLocalStoragePointer(NULL, index, arr3);

			sprintf(msg, "Get value from %d index\n", index);
			vPrintString(msg);

			int* getted_num_arr = pvTaskGetThreadLocalStoragePointer(NULL, index);

			if (getted_num_arr == NULL) {
				vPrintString("The returned value is NULL\n");
			}
			else
			{
				vPrintString("Compare initial and getted arrays:\n");
				vPrintString("Initial array - ");
				printArray(arr3, sizeof(arr3) / sizeof(int));
				vPrintString("Getted array - ");
				printArray(getted_num_arr, sizeof(arr3) / sizeof(int));
			}
			break;
		}

		case 3: {
			int index = -100;

			sprintf(msg, "Set array of integers for %d (negative) index\n", index);
			vPrintString(msg);

			vTaskSetThreadLocalStoragePointer(NULL, index, arr2);

			sprintf(msg, "Get value from %d index\n", index);
			vPrintString(msg);

			int* getted_num_arr = pvTaskGetThreadLocalStoragePointer(NULL, index);

			if (getted_num_arr == NULL) {
				vPrintString("The returned value is NULL\n");
			}
			else
			{
				vPrintString("Compare initial and getted arrays:\n");
				vPrintString("Initial array - ");
				printArray(arr2, sizeof(arr2) / sizeof(int));
				vPrintString("Getted array - ");
				printArray(getted_num_arr, sizeof(arr2) / sizeof(int));
			}
			break;
		}
		default:
			goto end_of_loop;
		}

		vPrintString("Task1 is in the blocked state for 1000ms\n\n");
		vTaskDelay(pdMS_TO_TICKS(1000));
	}
	end_of_loop:
	vPrintString("Task 1 is finished\n");
}

void printArray(int* array, int length) {
	for (int i = 0; i < length; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}