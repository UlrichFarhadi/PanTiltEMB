
#include "spiTask.h"



void spiTask (void *p)
{
    TickType_t myLastUnblock;
    myLastUnblock = xTaskGetTickCount();

    INT16U spiSendData = 0;
    INT16U temp1;
    INT16U temp2;
    INT16U motor_select_MASK = 0x0008; // 0b 0000 0000 0000 1000
    while(1)
    {
        vTaskDelayUntil( &myLastUnblock , pdMS_TO_TICKS ( 10 ) ); // Block this task at all time
                                                                 // Wake up once every 10ms
                                                                 // Execute code.

        // Motor 1
        write_spi(spiSendData++);
        temp1 = read_spi();
        if(temp1 & motor_select_MASK == FALSE) // SPI values read from M1
        {
          // Put queue M1
          xQueueOverwrite(Q_SPIDATAM1, &temp1);
        }
        else if(temp1 & motor_select_MASK == TRUE) // SPI values read from M2
        {
          // Put queue M2
          xQueueOverwrite(Q_SPIDATAM2, &temp1);

        }


        // Motor 2
        write_spi(spiSendData++);
        temp2 = read_spi();
        if(temp2 & motor_select_MASK == FALSE)
        {
          //put queue M1
          xQueueOverwrite(Q_SPIDATAM1, &temp2);

        }
        else if(temp2 & motor_select_MASK == TRUE)
        {
          // Put queue M2
          xQueueOverwrite(Q_SPIDATAM2, &temp2);

        }
    }
}
