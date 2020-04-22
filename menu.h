#ifndef MENU_H_
#define MENU_H_
/*****************************************************************************
* University of Southern Denmark
* Embedded C Programming (ECP)
*
* MODULENAME.: menu.h
*
* PROJECT....: ECP
*
* DESCRIPTION: Test.
*
* Change Log:
******************************************************************************
* Date    Id    Change
* YYMMDD
* --------------------
* 090315  MoH   Module created.
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

/*****************************   Constants   *******************************/

/*****************************   Functions   *******************************/
void menu_task(void *p);
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : Test function
******************************************************************************/
void display_menu_task(void *p);

/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : Test function
******************************************************************************/


/****************************** End Of Module *******************************/

#endif
