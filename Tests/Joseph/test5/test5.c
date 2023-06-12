#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "supporting_functions.h"

void testTaskGetHandle(void* pvParameters)
{
	printf("'testTaskGetHandle' has finished executnig ~ \n");
}

int main(void)
{
	xTaskCreate(testTaskGetHandle,
		"task 1",   
		1000,		
		NULL,		
		1,			
		NULL
	);

	TaskHandle_t handle = xTaskGetHandle("task 1");

	if (handle != NULL) {
		printf("Handle to 'testTaskGetHandle' obtained successfully!\n");
	}
	else {
		printf("Failed to obtain handle to 'testTaskGetHandle'.\n");
	}

	vTaskStartScheduler();

	return 0;
}