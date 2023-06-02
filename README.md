# GalaxyX
Me and my student team write tests on C to examine APIs related to Task Management &amp; Scheduling modules of FreeRTOS
## Assignment of API functions to test
1. 박철현
   - xTaskCreate
   - xTaskCreateStatic
   - vTaskDelete
   - vTaskDelay
   - vTaskDelayUntil
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
5. Aleksei
 [ ] portSWITCH_TO_USER_MODE
 [ ] vTaskAllocateMPURegions
 [x] xTaskCallApplicationTaskHook
 [x] xTaskCheckForTimeOut
 [x] vTaskGetRunTimeStats
 [x] uxTaskGetSystemState
 [x] vTaskGetTaskInfo
 [x] vTaskList
 [x] vTaskSetTimeOutState
 [ ] vTaskStepTick
6. Sahil
   - xTaskCreateRestricted
   - xTaskAbortDelay
   - eTaskGetState
   - uxTaskGetStackHighWaterMark
   - vTaskStartScheduler
   - vTaskSuspend
   - vTaskSuspendAll
   - taskYIELD
## Guide for working with Github
1. Install Git on your PC ([look here](https://github.com/git-guides/install-git))
2. Clone remote repository to your workspace folder (`git clone https://github.com/NutonFlash/GalaxyX.git`)
4. Create new branch to use for your commits (`git checkout -b name_of_the_branch`)
5. In the process of developing tests, you should add your files to this repository, after which I will review them
   - Add new files for the git tree (`git add path/to/files`)
   - Commit added files with some informational message (`git commit -m 'some info about changes'`)
   - Push commits to the remote repository (`git push name_of_the_remote_repo name_of_your_branch`)
   - Create pull request on Github
6. I'll review your code and give a feedback, you'll see it in the tab "Pull requests"
7. Git commands usage example:
![git commands](/doc/git_commands1.png)
![git commands](/doc/git_commands2.png)
