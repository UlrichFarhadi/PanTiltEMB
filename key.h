/*****************************************************************************
* University of Southern Denmark
* Embedded Programming (EMP)
*
* MODULENAME.: key.h
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
* 150321  MoH   Module created.
* 200525  TAK   Module rewritten to work with FreeRTOS
*****************************************************************************/

#ifndef _KEY_H
  #define _KEY_H

/***************************** Include files *******************************/
// FreeRTOS include files
  #include "FreeRTOS.h"
  #include "task.h"
/*****************************   Constants   *******************************/
/*****************************   Functions   *******************************/
BOOLEAN get_keyboard( INT8U* );
BOOLEAN peek_keyboard( INT8U* );
void key_task(void*);

/****************************** End Of Module *******************************/
#endif
