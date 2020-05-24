
/***************************** Include files *******************************/
#include "regulering.h"
/*****************************    Defines    *******************************/
#define REG_PI 3.14159
/*****************************   Constants   *******************************/

/*****************************   Variables   *******************************/
INT16U M1_Current_Radians_Binary_To_PWM = 0;
INT16U M2_Current_Radians_Binary_To_PWM = 0;

FP64 diriiM1_val = 0.0;
FP64 diriiM2_val = 0.0;
INT16U temp_Queue_Holder = 0;

// Controllers (transfer function coefficients)
FP64 a1[2] = {2, 1};
FP64 b1[3] = {2, 1, 0};

FP64 a2[2] = {2, 1};
FP64 b2[3] = {2, 1, 0};

FP64 temp_M1_ref = 0;
FP64 temp_M2_ref = 0;

FP64 encoder2RadM1 = 0;
FP64 encoder2RadM2 = 0;
  
/*****************************   Functions   *******************************/
void reg_Task(void *p)
{
  struct controller* ctrM1 = addController(a1, 2, b1, 3);
  struct controller* ctrM2 = addController(a2, 2, b2, 3);

  while(1)
  {
    /*
    --------------------------Regulator In and Outputs----------------------------
    Regulator Input in Radians
    Regulator Output in Volt from 0 to 12 degrees, need to be converted to PWM duty cycle of xx bits
    --------------------------------Motor Limits----------------------------------
    M1 has a range of +- 85 degrees ( 170 degrees --> encoder 510)
    M2 has a range of 360 degrees ( 360 degrees --> encoder 1080)
    --------------------------------Protocol--------------------------------------
    TIVA: 8-1-1-"1"-1   (PWM)(MotorSel)(MotorRetning)("EnableHbro")(SPI toggle bit)
    FPGA: 11-1-1-1-1  (Enkoder 1080grader)(MotorSel)(MotorRetning)(HomeSw1)(HomeSw2)
    */
  vTaskSuspend( NULL ); // Suspend the task itself
  // Allways suspend this task, SPI will resume it once it is run every 10ms
  // This way it will only run once every 10ms as it should since sampling time T is 10ms.
  /*
  ----- DEFINITION in FreeRTOS -----
  xTaskToSuspend 	Handle to the task being suspended. Passing a NULL handle will cause the calling task to be suspended.
  */

  //--------------------------------Motor 1 Regulation--------------------------
  temp_Queue_Holder = 0; // Reset value
                         // Motor 1 is already chosen by default
  xQueuePeek(Q_NEWPOSM1, &temp_M1_ref, 0);
  temp_M1_ref = temp_M1_ref*REG_PI/180;
  encoder2RadM1 = (get_encodervalue(M1)/3)*REG_PI/180; // temp_M1_ref - encoder2RadM1
  diriiM1_val = runController( ctrM1 , temp_M1_ref - encoder2RadM1 ); // Use the reference value relative to the current value for the controller
  if(diriiM1_val > 0.0)
  {
    //  ---- Sæt TX M2 Motor retning til 0;
    temp_Queue_Holder |= 0x0004; // 0000 0000 0000 0100
  }
  M1_Current_Radians_Binary_To_PWM = (int) (abs(diriiM1_val) / (12/256)); //Conversion of the floating point value to int
   // Also it is converted to an aboslute INT value because we use positive bit value for the PWM and use Motor retning to determine retningen.

   //  ---- Sæt TX Encoder value for M2----
  M1_Current_Radians_Binary_To_PWM = (M1_Current_Radians_Binary_To_PWM << 4);
  temp_Queue_Holder |= M1_Current_Radians_Binary_To_PWM;

  // Send to the queue that SPI uses.
  xQueueOverwrite( Q_SPIDATATXM1, &temp_Queue_Holder );

  //--------------------------------Motor 2 Regulation--------------------------
  temp_Queue_Holder = 0; // Reset value
  temp_Queue_Holder |= 0x0008; // Choose Motor 2
  xQueuePeek(Q_NEWPOSM2, &temp_M2_ref, 0);
  temp_M2_ref = temp_M2_ref*REG_PI/180;
  encoder2RadM2 = (get_encodervalue(M2)/3)*REG_PI/180;
  diriiM2_val = runController( ctrM2 , temp_M2_ref - encoder2RadM2 );
  if(diriiM2_val > 0.0)
  {
    //  ---- Sæt TX M2 Motor retning til 0;
    temp_Queue_Holder |= 0x0004; // 0000 0000 0000 0100
  }
  M2_Current_Radians_Binary_To_PWM = (int) (abs(diriiM2_val) / (12/256)); //Conversion of the floating point value to int
   // Also it is converted to an aboslute INT value because we use positive bit value for the PWM and use Motor retning to determine retningen.

   //  ---- Sæt TX Encoder value for M2----
  M2_Current_Radians_Binary_To_PWM = (M2_Current_Radians_Binary_To_PWM << 4);
  temp_Queue_Holder |= M2_Current_Radians_Binary_To_PWM;

  // Send to the queue that SPI uses.
  xQueueOverwrite( Q_SPIDATATXM2, &temp_Queue_Holder );

 }

}

/****************************** End Of Module *******************************/
