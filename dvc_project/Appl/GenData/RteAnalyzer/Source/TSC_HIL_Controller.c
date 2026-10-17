/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  TSC_HIL_Controller.c
 *        Config:  s32k_dvc.dpa
 *   ECU-Project:  S32K144
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800257
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_HIL_Controller.h"
#include "TSC_HIL_Controller.h"








Std_ReturnType TSC_HIL_Controller_Rte_Read_R_HIL_Vx_Cnt(uint16 *data)
{
  return Rte_Read_R_HIL_Vx_Cnt(data);
}

Std_ReturnType TSC_HIL_Controller_Rte_Read_R_HIL_Vx_Vx(sint16 *data)
{
  return Rte_Read_R_HIL_Vx_Vx(data);
}




Std_ReturnType TSC_HIL_Controller_Rte_Write_P_HIL_Cmd_Fault(uint8 data)
{
  return Rte_Write_P_HIL_Cmd_Fault(data);
}

Std_ReturnType TSC_HIL_Controller_Rte_Write_P_HIL_Cmd_Heartbeat(uint8 data)
{
  return Rte_Write_P_HIL_Cmd_Heartbeat(data);
}

Std_ReturnType TSC_HIL_Controller_Rte_Write_P_HIL_Cmd_Pcon(uint16 data)
{
  return Rte_Write_P_HIL_Cmd_Pcon(data);
}

Std_ReturnType TSC_HIL_Controller_Rte_Write_P_HIL_Cmd_Throttle(uint16 data)
{
  return Rte_Write_P_HIL_Cmd_Throttle(data);
}





     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */







     /* HIL_Controller */
      /* HIL_Controller */



