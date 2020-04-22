/*****************************************************************************

SDU Semesterproject 4 Group 1

*****************************************************************************/

/***************************** Include files *******************************/
#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "emp_type.h"

// Systick Timer used for software TICK timer by FreeRTOS
// (used for context switching and time measuring)
#include "systick_frt.h"

// FreeRTOS include files
#include "FreeRTOS.h"   // IMPORTANT!!! Always include FreeRTOS.h before task.h or queue.h etc.
#include "task.h"
#include "queue.h"
#include "semphr.h"

// SPI protocol setup and functions.
#include "spi_config.h"

// Tasks
#include "tasktest.h" // (An example of a setup of a task, use this for reference)
#include "spiTask.h"
#include "menu.h"
#include "lcd.h"
#include "ui.h"
#include "key.h"

// Display Color (For Debugging Purposes)
#include "display_color.h"

// Initialize GPIO pins for on board LEDs, Button Matrix and LCD.
#include "gpio.h"

// Others
#include "taskHandlers.h"
#include "queueHandlers.h"
#include "semaphoreHandlers.h"
#include "file.h"
//#include "tmodel.h"

/*****************************    Defines    *******************************/
//#define USERTASK_STACK_SIZE configMINIMAL_STACK_SIZE
#define IDLE_PRIO 0
#define LOW_PRIO  1
#define MED_PRIO  2
#define HIGH_PRIO 3

/*****************************   Constants   *******************************/

/*****************************   Variables   *******************************/

/*****************************   Functions   *******************************/

static void setupHardware(void)
/*****************************************************************************
*   Input    :  -
*   Output   :  -
*   Function :
*****************************************************************************/
{
  init_systick();       // Initialize Real time clock SystickTimer for Ticks
  init_gpio();          // Initialize GPIO pins for on board LEDs,
                        // Button Matrix and LCD.
  init_files();
  init_master_spi();    // Initialize the spi protocol
}



int main(void)
/*****************************************************************************
*   Input    :
*   Output   :
*   Function : The super loop.
******************************************************************************/
{

  setupHardware();

  // Create the queues
  // ----------------

  Q_KEY = xQueueCreate(QUEUE_SIZE, sizeof(INT8U));
  Q_LCD = xQueueCreate(QUEUE_SIZE, sizeof(int));

  // Create the semaphore
  // ----------------
  SEM_MENU_UPDATED = xSemaphoreCreateMutex();

  // Start the tasks.
  // ----------------
  xTaskCreate(myTaskTest, "taskTest", configMINIMAL_STACK_SIZE, NULL, LOW_PRIO, &myTaskTestHandle);
  xTaskCreate(spiTask, "spiTask", configMINIMAL_STACK_SIZE, NULL, LOW_PRIO, &spiTaskHandle);
  xTaskCreate(lcd_task, "lcdTask", configMINIMAL_STACK_SIZE, NULL, LOW_PRIO, &lcdTaskHandle);
  xTaskCreate(key_task, "keyTask", configMINIMAL_STACK_SIZE, NULL, LOW_PRIO, &keyTaskHandle);
  xTaskCreate(display_menu_task, "displayMenuTask", configMINIMAL_STACK_SIZE, NULL, LOW_PRIO, &displayMenuTaskHandle);
  xTaskCreate(menu_task, "menuTask", configMINIMAL_STACK_SIZE, NULL, LOW_PRIO, &menuTaskHandle);


  // Start the scheduler.
  // --------------------
  vTaskStartScheduler();

  // Will only get here, if there was insufficient memory.
  // -----------------------------------------------------
  return 1;
}

/****************************** End Of Module *******************************/
