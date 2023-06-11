#include <stdio.h> 
#include <string.h> 

/* FreeRTOS.org includes. */
#include "FreeRTOS.h"
#include "task.h"

/* Demo includes. */
#include "supporting_functions.h"

// ARM Cortex-M에서의 SWITCH_TO_USER_MODE() 매크로 정의
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
#define SWITCH_TO_USER_MODE() __asm("MOVS   R0, #0x01"); \
                              __asm("MSR    CONTROL, R0"); \
                              __asm("BX     LR")
#else
void switchToUserMode() {
    printf("Switching to user mode\n");
    // 사용자 모드로 전환하는 코드 작성
    // ...
}
#define SWITCH_TO_USER_MODE() switchToUserMode()
#endif

int main(void) {
    printf("Before switching to user mode\n");

    // 사용자 모드로 전환
    SWITCH_TO_USER_MODE();

    // 이 코드는 사용자 모드에서 실행됨
    printf("After switching to user mode\n");

    return 0;
}
