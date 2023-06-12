#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "supporting_functions.h"

TaskHandle_t handle_idleTask;

void vIdleTask(void *pvParameters) {
    printf("IDLE TASK: Idle task is running and will now be suspended...\n");
	vTaskSuspend(handle_idleTask);
}


void task2(void* pvParameters) {
	printf("Get a handle for the idle task, and called vTaskResume() \n");

	TaskHandle_t idleTaskHandle = xTaskGetIdleTaskHandle();
	if (idleTaskHandle != NULL) {
		printf("Handle to the idle task obtained successfully!\n");
		vTaskResume(idleTaskHandle);
		printf("Idle task resumed successfully!\n");
	}
	else {
		printf("Failed to obtain handle to the idle task.\n");
	}
}

int main(void)
{
	xTaskCreate(vIdleTask, "Idle Task", 100, NULL, 1, handle_idleTask);
	xTaskCreate(task2, "task 2", 100, NULL, 1, handle_idleTask);


	vTaskStartScheduler();

	return 0;
}