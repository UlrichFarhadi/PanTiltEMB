#ifndef FILES_TASKHANDLERS_H_
#define FILES_TASKHANDLERS_H_

#include "FreeRTOS.h"
#include "task.h"

TaskHandle_t spiTaskHandle;     // Task Handle for spiTask
TaskHandle_t myTaskTestHandle;  // Task handle for myTaskTest
TaskHandle_t lcdTaskHandle;  // Task handle for lcdTaskHandle
TaskHandle_t keyTaskHandle;  // Task handle for keyTaskHandle
TaskHandle_t displayMenuTaskHandle;  // Task handle for displayMenuTaskHandle
TaskHandle_t menuTaskHandle;  // Task handle for menuTaskHandle
TaskHandle_t regTaskHandle;   // Task handle for regTask
#endif /* FILES_TASKHANDLERS_H_ */
