#include "spiTask.h"


void spiTask (void *p)
{
    TickType_t myLastUnblock;
    myLastUnblock = xTaskGetTickCount();

    INT16U spiSendData = 0;
    while(1)
    {
        vTaskDelayUntil( &myLastUnblock , pdMS_TO_TICKS ( 1 ) ); // Block this task at all time
                                                                 // Wake up once every 1ms
                                                                 // Execute code.
        // An overestimate of context switch time is 200 cycles + 100 cycles for interrupt handling.
        // Tick time is 1600 cycles. This code should therefore not exceed 1000 cycles. Since
        // SPI must happen precise once every 1ms (for the PanTilt control to work the best)
        // However if write_spi() or read_spi() is used any interrupts will not disturb this
        // since the data transfer is handled by hardware. Once data transfer is finished, it awaits next instruction.
        write_spi(spiSendData++);
    }
}
