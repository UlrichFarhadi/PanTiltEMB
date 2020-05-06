/*****************************************************************************
* University of Southern Denmark
* Embedded C Programming (ECP)
*
* MODULENAME.: controller.h(.h)
*
* PROJECT....: PanTilt
*
* DESCRIPTION: -
*
* Change Log:
******************************************************************************
* Date    Id    Change
* 5 May 2020
* --------------------
* 090215  MoH   Module created.
*
*****************************************************************************/

#ifndef PANTILTEMB_CONTROLLER_H_
#define PANTILTEMB_CONTROLLER_H_

/***************************** Include files *******************************/
#include "emp_type.h"

/*****************************    Defines    *******************************/
//Controller type defined i .h file
typedef struct controller{
    INT8U a_len; //INT16U -> unsigned short
    INT8U b_len;
    INT16U vals[]; //MAX VAL OF 2^16.

};

/*****************************   Constants   *******************************/

/*****************************   Functions   *******************************/

struct controller* addController(INT16S a[], a_size, INT16S b[], b_size);
/*****************************************************************************
*   Input    : Transfer function coefficients of controller
*   Output   : pointer to controller
*   Function : Creates a controller with given coefficients and returns
*              pointer to the controller.
******************************************************************************/

void removeController(struct controller* ctr);
/*****************************************************************************
*   Input    : Pointer to controller.
*   Output   : -
*   Function : Frees allocated memory for controller.
******************************************************************************/

INT16S runController(struct controller* ctr, INT16S in_val);
/*****************************************************************************
*   Input    : Puts in_val as input to controller with pointer ctr.
*   Output   : Corresponding output to given input.
*   Function : Calculates the direct transform II response to the controller
*              input.
******************************************************************************/


/****************************** End Of Module *******************************/


#endif /* PANTILTEMB_CONTROLLER_H_ */
