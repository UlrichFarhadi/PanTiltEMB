#ifndef FILES_QUEUEHANDLERS_H_
#define FILES_QUEUEHANDLERS_H_

#include "FreeRTOS.h"
#include "queue.h"

  QueueHandle_t Q_KEY;
  QueueHandle_t Q_LCD;

  // Queues for receiving spi data
  QueueHandle_t Q_SPIDATAM1;
  QueueHandle_t Q_SPIDATAM2;

  // Queues for writing spi data
  QueueHandle_t Q_SPIDATATXM1;
  QueueHandle_t Q_SPIDATATXM2;

  // Queues for new positions for motors
  QueueHandle_t Q_NEWPOSM1;
  QueueHandle_t Q_NEWPOSM2;

/*****************************    Defines    *******************************/
#define QUEUE_SIZE   128


#endif /* FILES_QUEUEHANDLERS_H_ */
