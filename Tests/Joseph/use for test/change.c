#include <stdio.h>

/* FreeRTOS.org includes. */
#include "FreeRTOS.h"
#include "task.h"

/* Function prototypes */
void vDemoFunction(void);
void vDemoISR(void);

/* A function called from an ISR. */
void vDemoFunction(void)
{
    UBaseType_t uxSavedInterruptStatus;
    /* Enter the critical section. Save the value returned by taskENTER_CRITICAL_FROM_ISR()
    into a local stack variable so it can be passed into taskEXIT_CRITICAL_FROM_ISR(). */
    uxSavedInterruptStatus = taskENTER_CRITICAL_FROM_ISR();

    /* Perform the action that is being protected by the critical section here. */
    printf("Inside vDemoFunction: Critical section protected action\n");

    /* Exit the critical section. */
    taskEXIT_CRITICAL_FROM_ISR(uxSavedInterruptStatus);
}

/* A task that calls vDemoFunction() from within an interrupt service routine. */
void vDemoISR(void)
{
    UBaseType_t uxSavedInterruptStatus;
    /* Call taskENTER_CRITICAL_FROM_ISR() to create a critical section, saving the
    returned value into a local stack. */
    uxSavedInterruptStatus = taskENTER_CRITICAL_FROM_ISR();

    /* Execute the code that requires the critical section here. */
    printf("Inside vDemoISR: Code before vDemoFunction\n");

    /* Calls to taskENTER_CRITICAL_FROM_ISR() can be nested, so it is safe to call a
    function that includes its own calls to taskENTER_CRITICAL_FROM_ISR() and
    taskEXIT_CRITICAL_FROM_ISR(). */
    vDemoFunction();

    /* The operation that required the critical section is complete, so exit the
    critical section. Assuming interrupts were enabled on entry to this ISR, the value
    saved in uxSavedInterruptStatus will result in interrupts being re-enabled. */
    taskEXIT_CRITICAL_FROM_ISR(uxSavedInterruptStatus);
}

/* Main function */
int main()
{
    /* Simulating an interrupt by calling vDemoISR */
    vDemoISR();

    return 0;
}
