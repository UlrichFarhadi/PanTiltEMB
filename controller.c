/*****************************************************************************
* University of Southern Denmark
* Embedded C Programming (ECP)
*
* MODULENAME.: controller.c(.h)
*
* PROJECT....: PanTilt
*
* DESCRIPTION: -
*
* Litterature reference
* - https://en.wikipedia.org/wiki/Flexible_array_member
* - https://en.wikipedia.org/wiki/C_dynamic_memory_allocation
* - https://stackoverflow.com/questions/32311269/can-we-have-a-struct-element-of-type-variable-length-array
*
* Change Log:
******************************************************************************
* Date    Id    Change
* 5 May 2020
* --------------------
* 090215  MoH   Module created.
*
*****************************************************************************/

/***************************** Include files *******************************/
#include "emp_type.h"
#include <stdlib.h> //malloc and free

/*****************************    Defines    *******************************/
typedef struct controller{
    INT8U a_len; //INT16U -> unsigned short
    INT8U b_len;
    INT16U vals[]; //MAX VAL OF 2^16.

};

/*****************************   Constants   *******************************/

/*****************************   Variables   *******************************/

/*****************************   Functions   *******************************/

struct controller* addController(INT16S a[], INT8U a_size, INT16S b[], INT8U b_size)
/*****************************************************************************
*   Input    : Transfer function coefficients of controller and size of each array.
*   Output   : pointer to controller. If return value = NULL then no controller was created.
*   Function : Creates a controller with given coefficients and returns
*              pointer to the controller.
******************************************************************************/
{
    INT8U w_size = a_size;

    INT16U vec_len = a_size + b_size + w_size;
    struct controller *ctr;
    ctr = (struct controller *)malloc(sizeof(struct controller) + vec_len * sizeof(INT16S)); //Space for struct plus lenght of dynamic array

    //Set struct members
    ctr->a_len = a_size;
    ctr->b_len = b_size;

    for (INT8U i = 0; i < a_size; ++i)
    {
        ctr->vals[i] = a[i];
        ctr->vals[i + a_size + b_size] = 0; //Just as many w elements but with offsets.
    }
    for (INT8U i = 0; i < b_size; ++i)
    {
        ctr->vals[i + a_size] = b[i];
    }


    return ctr; //Controller created with given coefficients
}


void removeController(struct controller* ctr)
/*****************************************************************************
*   Input    : Pointer to controller.
*   Output   : -
*   Function : Frees allocated memory for controller.
******************************************************************************/
{
    free(ctr);
}

INT16S runController(struct controller* ctr, INT16S in_val)
/*****************************************************************************
*   Input    : Puts in_val as input to controller with pointer ctr.
*   Output   : Corresponding output to given input.
*   Function : Calculates the direct transform II response to the controller
*              input.
******************************************************************************/
{
    INT8U a_size = ctr->a_len;
    INT8U b_size = ctr->b_len;
    INT8U w_size = a_size;

    INT16S w = in_val;
    for (INT8U i = 0; i < ctr->a_len; ++i)
    {
        w = w - (ctr->vals[i]) * (ctr->vals[i + a_size + b_size]); //w[n] = x(n) - a_1 * w[n-1] - a_2 * w[n -2]....
    }

    INT16S y = ctr->vals[a_size] * w;
    for (INT16U i = a_size + 1; i < a_size + b_size; ++i)
    {
        y = y + ctr->vals[i] * ctr->vals[i + b_size - 1]; //y = b0*w[n] + b1 * w[n-1] + b2 * w[n-2]...
    }

    for (INT16U i = a_size + b_size + w_size - 1; i > a_size + b_size; --i) //Update W[n-m] array
    {
        ctr->vals[i] = ctr->vals[i - 1];
    }
    ctr->vals[a_size + b_size] = w;


    return y;
}

/****************************** End Of Module *******************************/


