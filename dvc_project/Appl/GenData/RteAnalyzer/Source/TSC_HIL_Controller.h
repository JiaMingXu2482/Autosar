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
 *          File:  TSC_HIL_Controller.h
 *        Config:  s32k_dvc.dpa
 *   ECU-Project:  S32K144
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800257
 *
 *   Description:  Header of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/


/** Sender receiver - explicit read services */
Std_ReturnType TSC_HIL_Controller_Rte_Read_R_HIL_Vx_Cnt(uint16 *data);
Std_ReturnType TSC_HIL_Controller_Rte_Read_R_HIL_Vx_Vx(sint16 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_HIL_Controller_Rte_Write_P_HIL_Cmd_Fault(uint8 data);
Std_ReturnType TSC_HIL_Controller_Rte_Write_P_HIL_Cmd_Heartbeat(uint8 data);
Std_ReturnType TSC_HIL_Controller_Rte_Write_P_HIL_Cmd_Pcon(uint16 data);
Std_ReturnType TSC_HIL_Controller_Rte_Write_P_HIL_Cmd_Throttle(uint16 data);




