# GalaxyX
Me and my student team write tests on C to examine APIs related to Task Management &amp; Scheduling modules of FreeRTOS
## Assignment of API functions to test
1. 박철현
   - xTaskCreate
   - xTaskCreateStatic
   - xTaskCreateRestricted
   - vTaskDelete
   - vTaskDelay
   - vTaskDelayUntil
   - xTaskAbortDelay
   - taskDISABLE_INTERRUPTS
   - taskENABLE_INTERRUPTS
   - xTaskGetApplicationTaskTag
   - vTaskSetApplicationTaskTag
2. Joseph
   - taskENTER_CRITICAL
   - taskEXIT_CRITICAL
   - taskENTER_CRITICAL_FROM_ISR
   - taskEXIT_CRITICAL_FROM_ISR
   - xTaskGetCurrentTaskHandle
   - xTaskGetIdleTaskHandle
   - xTaskGetHandle
   - uxTaskGetNumberOfTasks
   - xTaskGetSchedulerState
   - uxTaskGetStackHighWaterMark
   - eTaskGetState
3. 김주영
   - pvTaskGetThreadLocalStoragePointer
   - vTaskSetThreadLocalStoragePointer
   - pcTaskGetName
   - xTaskGetTickCount
   - xTaskGetTickCountFromISR
   - uxTaskPriorityGet
   - vTaskPrioritySet
   - vTaskResume
   - xTaskResumeAll
   - xTaskResumeFromISR
   - vTaskStartScheduler
4. Oybek
   - xTaskNotify
   - xTaskNotifyAndQuery
   - xTaskNotifyAndQueryFromISR
   - xTaskNotifyFromISR
   - xTaskNotifyGive
   - vTaskNotifyGiveFromISR
   - xTaskNotifyStateClear
   - ulTaskNotifyTake
   - xTaskNotifyWait
   - vTaskSuspend
   - vTaskSuspendAll
6. Aleksei
   - portSWITCH_TO_USER_MODE
   - vTaskAllocateMPURegions
   - xTaskCallApplicationTaskHook
   - xTaskCheckForTimeOut
   - vTaskGetRunTimeStats
   - uxTaskGetSystemState
   - vTaskGetTaskInfo
   - vTaskList
   - vTaskSetTimeOutState
   - vTaskStepTick
   - taskYIELD
## Guide for working with Github
1. Install Git on your PC ([look here])(https://github.com/git-guides/install-git)
2. Init git repository in your workspace folder (`git init`)
3. Add remote repository (`git remote add name_of_the_remote_repo https://github.com/NutonFlash/GalaxyX.git`)
4. Create new branch to use for your commits (`git checkout -b name_of_the_branch`)
5. In the process of developing tests, you should add your files to this repository, after which I will review them
   - Add new files for the git tree (`git add path/to/files`)
   - Commit added files with some informational message (`git commit -m 'some info about changes'`)
   - Push commits to the remote repository (`git push name_of_the_remote_repo`)
6. After you have pushed commits, you will be able to see it in the "Pull requests" tab. I'll review your code and make a feedback.
![git commands](/doc/terminal_screen1.png)
![git commands](/doc/terminal_screen2.png)
