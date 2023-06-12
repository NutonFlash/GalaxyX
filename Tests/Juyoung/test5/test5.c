#include <stdio.h> 
#include <string.h> 

/* FreeRTOS.org includes. */
#include "FreeRTOS.h"
#include "task.h"

/* Demo includes. */
#include "supporting_functions.h"

TickType_t xTaskGetTickCountFromISR(void);
void vTask1(void* pvParameters);

int main(void) {

	vPrintString("Test of the xTaskGetTickCountFromISR()\n");
	vPrintString("----------------------------------------\n\n");
	vPrintString("Start task1 with test5\n");

	xTaskCreate(vTask1, "Task1", 100, NULL, 1, NULL);

	vTaskStartScheduler();

	for (;;);
	return 0;
}


void vTask1(void) {
	static TickType_t xTimeISRLastExecuted = 0;
	TickType_t xTimeNow, xTimeBetweenInterrupts;

	vPrintString("\nStart test5\n");

	for (uint32_t i = 0;; i++) {
		/* Store the time at which this interrupt was entered. */
		xTimeNow = xTaskGetTickCountFromISR();

		vPrintString("Test5 is blocked for 1000ms\n");
		vTaskDelay(pdMS_TO_TICKS(1000));

		/* How many ticks occurred between this and the previous interrupt? */
		xTimeBetweenInterrupts = xTimeISRLastExecuted - xTimeNow;

		/* If more than 200 ticks occurred between this and the previous interrupt then do something. */
		if (xTimeBetweenInterrupts > 200) {
			
			printf("Time Between Interrupts: %u ticks\n", xTimeBetweenInterrupts);
		}
		/* Remember the time at which this interrupt was entered. */
		xTimeISRLastExecuted = xTimeNow;
		printf("Last Executed time from ISR: %u ticks\n", xTimeISRLastExecuted);
	}

}