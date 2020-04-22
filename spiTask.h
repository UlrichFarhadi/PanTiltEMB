#ifndef FILES_SPITASK_H_
#define FILES_SPITASK_H_

#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "emp_type.h"

// FreeRTOS include files
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

// Include Task Handlers for each task for task communication
#include "taskHandlers.h"
#include "queueHandlers.h" // queue.h file comes from this include as well

// Display Color (For debugging purposes)
#include "display_color.h"
#include "spi_config.h"



void spiTask (void *p);

#endif /* FILES_SPITASK_H_ */
