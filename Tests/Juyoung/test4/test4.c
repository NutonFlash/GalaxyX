#include <stdio.h> 
#include <string.h> 

/* FreeRTOS.org includes. */
#include "FreeRTOS.h"
#include "task.h"

/* Demo includes. */
#include "supporting_functions.h"

// ARM Cortex-M������ SWITCH_TO_USER_MODE() ��ũ�� ����
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
#define SWITCH_TO_USER_MODE() __asm("MOVS   R0, #0x01"); \
                              __asm("MSR    CONTROL, R0"); \
                              __asm("BX     LR")
#else
void switchToUserMode() {
    printf("Switching to user mode\n");
    // ����� ���� ��ȯ�ϴ� �ڵ� �ۼ�
    // ...
}
#define SWITCH_TO_USER_MODE() switchToUserMode()
#endif

int main(void) {
    printf("Before switching to user mode\n");

    // ����� ���� ��ȯ
    SWITCH_TO_USER_MODE();

    // �� �ڵ�� ����� ��忡�� �����
    printf("After switching to user mode\n");

    return 0;
}
