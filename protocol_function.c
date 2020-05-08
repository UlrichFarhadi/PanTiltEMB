/*****************************************************************************
* University of Southern Denmark
* Embedded Programming (EMP)
*
* MODULENAME.: protocol_function.c
*
* PROJECT....: EMP
*
* DESCRIPTION: See module specification file (.h-file).
*
* Change Log:
*****************************************************************************
* Date    Id    Change
* YYMMDD
* --------------------
* 050128  KA    Module created.
*
*****************************************************************************/

/***************************** Include files *******************************/
#include "protocol_function.h"
/*****************************    Defines    *******************************/
// Masks:
INT16U home_Sw2_MASK     = 1;
INT16U home_Sw1_MASK     = 2;
INT16U motordir_MASK     = 4;
INT16U encodervalue_MASK = 0x7FF0; // dec = 32752 --> 0b 0111 1111 1111 0000


/*****************************   Constants   *******************************/

/*****************************   Variables   *******************************/

/*****************************   Functions   *******************************/


INT16U get_encodervalue(BOOLEAN MOTOR)
{
  INT16U encodervalue_holder;
  //INT16U temp_encoder_holder = 0;
  if (MOTOR == FALSE) // FALSE = M1, TRUE = M2
  {
    if(Q_SPIDATAM1 != 0) // Check if the SPIDATA queue for M1 is empty
    {
      if (xQueuePeek(Q_SPIDATAM1, &encodervalue_holder, 0)) //Read the value from M1's SPIDATA queue
      {
        encodervalue_holder &= encodervalue_MASK; // Keep the bits from the encoder only, rest is set to zero.
        encodervalue_holder = (encodervalue_holder >> 4); // Bitshift with 4 to get int value
      }
    }
  }
  else if (MOTOR == TRUE) // FALSE = M1, TRUE = M2
  {
    if(Q_SPIDATAM2 != 0) // Check if the SPIDATA queue for M2 is empty
    {
      if (xQueuePeek(Q_SPIDATAM2, &encodervalue_holder, 0)) //Read the value from M2's SPIDATA queue
      {
        encodervalue_holder &= encodervalue_MASK; // Keep the bits from the encoder only, rest is set to zero.
        encodervalue_holder = (encodervalue_holder >> 4); // Bitshift with 4 to get int value
      }
    }
  }
  return(encodervalue_holder); // Return INT16U bitvalue
}

BOOLEAN get_motordir(BOOLEAN MOTOR) // Return FALSE = CounterClockWise, Return True = ClockWise
{
  INT16U motordir_holder;
  BOOLEAN motordir;
  if (MOTOR == FALSE) // FALSE = M1, TRUE = M2
  {
    if(Q_SPIDATAM1 != 0) // Check if the SPIDATA queue for M1 is empty
    {
      if (xQueuePeek(Q_SPIDATAM1, &motordir_holder, 0)) //Read the value from M1's SPIDATA queue
      {
        if((motordir_holder & motordir_MASK) == FALSE) // Checks on motor direction FALSE = CounterClockWise, TRUE = ClockWise
        {
          // Negativ (CounterClockWise)
          motordir = FALSE;
          return(motordir); // Return BOOLEAN
        }
        else if((motordir_holder & motordir_MASK) == TRUE)
        {
          // Positiv (ClockWise)
          motordir = TRUE;
          return(motordir); // Return BOOLEAN
        }
      }
    }
  }
  else if (MOTOR == TRUE) // FALSE = M1, TRUE = M2
  {
    if(Q_SPIDATAM2 != 0) // Check if the SPIDATA queue for M2 is empty
    {
      if (xQueuePeek(Q_SPIDATAM2, &motordir_holder, 0)) //Read the value from M2's SPIDATA queue
      {
        if((motordir_holder & motordir_MASK) == FALSE) // Checks on motor direction FALSE = CounterClockWise, TRUE = ClockWise
        {
          // Negativ (CounterClockWise)
          motordir = FALSE;
          return(motordir); // Return BOOLEAN
        }
        else if((motordir_holder & motordir_MASK) == TRUE)
        {
          // Positiv (ClockWise)
          motordir = TRUE;
          return(motordir); // Return BOOLEAN
        }
      }
    }
  }
}

BOOLEAN get_home(BOOLEAN HOME_SW)
{
  INT16U home_holder;
  BOOLEAN sw_status;
  if (HOME_SW == FALSE) // FALSE = Home_SW1, TRUE = Home_SW2
  {
    if(Q_SPIDATAM1 != 0) // Check if the SPIDATA queue for M1 is empty
    {
      if (xQueuePeek(Q_SPIDATAM1, &home_holder, 0)) //Read the value from M1's SPIDATA queue
      {
        if((home_holder & home_Sw1_MASK) == FALSE) // Checks HOME_SW for M1, FALSE = SW not active, TRUE = SW active
        {
          // FALSE = sensor is not active
          sw_status = FALSE;
          return(sw_status); // Return BOOLEAN
        }
        else if((home_holder & home_Sw1_MASK) == TRUE)
        {
          // TRUE = sensor is active
          sw_status = TRUE;
          return(sw_status); // Return BOOLEAN
        }
      }
    }
  }
  else if (HOME_SW == TRUE) // FALSE = Home_SW1, TRUE = Home_SW2
  {
    if(Q_SPIDATAM2 != 0) // Check if the SPIDATA queue for M2 is empty
    {
      if (xQueuePeek(Q_SPIDATAM2, &home_holder, 0)) //Read the value from M2's SPIDATA queue
      {
        if((home_holder & home_Sw2_MASK) == FALSE) // Checks HOME_SW for M2, FALSE = SW not active, TRUE = SW active
        {
          // FALSE = sensor is not active
          sw_status = FALSE;
          return(sw_status); // Return BOOLEAN
        }
        else if((home_holder & home_Sw2_MASK) == TRUE)
        {
          // TRUE = sensor is active
          sw_status = TRUE;
          return(sw_status); // Return BOOLEAN
        }
      }
    }
  }
}

/****************************** End Of Module *******************************/
