
#ifndef _REGULERING_H
  #define _REGULERING_H

/***************************** Include files *******************************/
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "tm4c123gh6pm.h"
#include "emp_type.h"

// FreeRTOS include files
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

// Include Task and Queue Handlers
#include "taskHandlers.h"
#include "queueHandlers.h" // queue.h file could come from this include as well

#include "protocol_function.h" // Includes functions for peeking in SPI RX queues

#include "controller.h"

void reg_Task (void *p);


#endif
