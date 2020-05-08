/*****************************************************************************
* University of Southern Denmark
* Embedded Programming (EMP)
*
* MODULENAME.: protocol_function.h
*
* PROJECT....: EMP
*
* DESCRIPTION: Test.
*
* Change Log:
******************************************************************************
* Date    Id    Change
* YYMMDD
* --------------------
* 050128  KA    Module created.
*
*****************************************************************************/

#ifndef _PROTOCOL_FUNCTION_H
  #define _PROTOCOL_FUNCTION_H

/***************************** Include files *******************************/
#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "emp_type.h"

#include "FreeRTOS.h"
#include "queue.h"
#include "queueHandlers.h"
/*****************************    Defines    *******************************/

#define M1  FALSE
#define M2  TRUE

/********************** External declaration of Variables ******************/

/*****************************   Constants   *******************************/

/*************************  Function interfaces ****************************/
INT16U get_encodervalue(BOOLEAN MOTOR);
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : Return the encodervalue for the wanted motor
******************************************************************************/
BOOLEAN get_motordir(BOOLEAN MOTOR);
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : Return the motor direction for the wanted motor
******************************************************************************/
BOOLEAN get_home(BOOLEAN HOME_SW);
/*****************************************************************************
*   Input    : -
*   Output   : -
*   Function : Return true if the wanted Home_SW is true.
******************************************************************************/


/****************************** End Of Module *******************************/
#endif
