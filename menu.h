#ifndef MENU_H_
#define MENU_H_
/*****************************************************************************
* University of Southern Denmark
* Embedded C Programming (ECP)
*
* MODULENAME.: menu.h
*
* PROJECT....: Semesterproject
*
* DESCRIPTION: Test.
*
* Change Log:
******************************************************************************
* Date    Id    Change
* YYMMDD
* --------------------
* 200425  TAK   Module created
*
*****************************************************************************/


/***************************** Include files *******************************/
#include "emp_type.h"
// FreeRTOS include files
#include "FreeRTOS.h"
#include "task.h"
#include "semaphoreHandlers.h"
#include "queueHandlers.h"

/*****************************    Defines    *******************************/
BOOLEAN HOMING_M1_ACTIVE;
BOOLEAN HOMING_M2_ACTIVE;
/*****************************   Constants   *******************************/

/*****************************   Functions   *******************************/
void menu_task(void *p);
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : -
******************************************************************************/
void display_menu_task(void *p);

/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : -
******************************************************************************/


/****************************** End Of Module *******************************/

#endif
