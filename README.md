# GalaxyX
Me and my student team write tests on C to examine APIs related to Task Management &amp; Scheduling modules of FreeRTOS
## Assignment of API functions to test
1. 박철현
   - [x] xTaskCreate
   - [ ] xTaskCreateStatic
   - [x] vTaskDelete
   - [x] vTaskDelay
   - [x] vTaskDelayUntil
   - [ ] taskDISABLE_INTERRUPTS
   - [ ] taskENABLE_INTERRUPTS
   - [x] xTaskGetApplicationTaskTag
   - [x] vTaskSetApplicationTaskTag
2. Joseph
   - [x] taskENTER_CRITICAL
   - [x] taskEXIT_CRITICAL
   - [ ] taskENTER_CRITICAL_FROM_ISR (unrealizable)
   - [ ] taskEXIT_CRITICAL_FROM_ISR (unrealizable)
   - [ ] xTaskGetCurrentTaskHandle
   - [x] xTaskGetIdleTaskHandle
   - [x] xTaskGetHandle
   - [x] uxTaskGetNumberOfTasks
   - [ ] xTaskGetSchedulerState
3. 김주영
   - [x] pvTaskGetThreadLocalStoragePointer
   - [x] vTaskSetThreadLocalStoragePointer
   - [x] pcTaskGetName
   - [x] xTaskGetTickCount
   - [x] xTaskGetTickCountFromISR
   - [x] uxTaskPriorityGet
   - [x] vTaskPrioritySet
   - [x] vTaskResume
   - [x] xTaskResumeAll
   - [ ] xTaskResumeFromISR (unrealizable)
4. Oybek
   - [x] xTaskNotify
   - [x] xTaskNotifyAndQuery
   - [ ] xTaskNotifyAndQueryFromISR (unrealizable)
   - [ ] xTaskNotifyFromISR (unrealizable)
   - [x] xTaskNotifyGive
   - [ ] vTaskNotifyGiveFromISR (unrealizable)
   - [x] xTaskNotifyStateClear
   - [x] ulTaskNotifyTake
   - [x] xTaskNotifyWait
5. Aleksei
   - [x] portSWITCH_TO_USER_MODE
   - [ ] vTaskAllocateMPURegions (unrealizable)
   - [x] xTaskCallApplicationTaskHook
   - [x] xTaskCheckForTimeOut
   - [x] vTaskGetRunTimeStats
   - [x] uxTaskGetSystemState
   - [x] vTaskGetTaskInfo
   - [x] vTaskList
   - [x] vTaskSetTimeOutState
   - [ ] vTaskStepTick (unrealizable)
6. Sahil
   - [ ] xTaskCreateRestricted (unrealizable)
   - [x] xTaskAbortDelay
   - [x] eTaskGetState
   - [x] uxTaskGetStackHighWaterMark
   - [x] vTaskStartScheduler
   - [x] vTaskSuspend
   - [x] vTaskSuspendAll
   - [ ] taskYIELD
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
