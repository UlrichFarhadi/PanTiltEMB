#ifndef FILES_QUEUEHANDLERS_H_
#define FILES_QUEUEHANDLERS_H_

#include "FreeRTOS.h"
#include "queue.h"

  QueueHandle_t Q_KEY;
  QueueHandle_t Q_LCD;
  QueueHandle_t Q_SPIDATAM1;
  QueueHandle_t Q_SPIDATAM2;

/*****************************    Defines    *******************************/
#define QUEUE_SIZE   128


#endif /* FILES_QUEUEHANDLERS_H_ */
