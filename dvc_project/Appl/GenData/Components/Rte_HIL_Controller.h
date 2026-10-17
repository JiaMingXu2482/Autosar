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
 *          File:  Rte_HIL_Controller.h
 *        Config:  s32k_dvc.dpa
 *   ECU-Project:  S32K144
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800257
 *
 *   Description:  Application header file for SW-C <HIL_Controller>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_HIL_CONTROLLER_H
# define _RTE_HIL_CONTROLLER_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_HIL_Controller_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

#  include "Com.h"


# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_P_HIL_Cmd_Fault (0U)
#  define Rte_InitValue_P_HIL_Cmd_Heartbeat (0U)
#  define Rte_InitValue_P_HIL_Cmd_Pcon (0U)
#  define Rte_InitValue_P_HIL_Cmd_Throttle (0U)
#  define Rte_InitValue_R_HIL_Vx_Cnt (0U)
#  define Rte_InitValue_R_HIL_Vx_Vx (0)
# endif


# define RTE_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_HIL_Controller_P_HIL_Cmd_Fault(uint8 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_HIL_Controller_P_HIL_Cmd_Heartbeat(uint8 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_HIL_Controller_P_HIL_Cmd_Pcon(uint16 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_HIL_Controller_P_HIL_Cmd_Throttle(uint16 data); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_R_HIL_Vx_Cnt Rte_Read_HIL_Controller_R_HIL_Vx_Cnt
#  define Rte_Read_HIL_Controller_R_HIL_Vx_Cnt(data) (Com_ReceiveSignal(ComConf_ComSignal_Cnt_oHIL_Vx_oCAN00_5a9efcf4_Rx, (data))) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_R_HIL_Vx_Vx Rte_Read_HIL_Controller_R_HIL_Vx_Vx
#  define Rte_Read_HIL_Controller_R_HIL_Vx_Vx(data) (Com_ReceiveSignal(ComConf_ComSignal_Vx_oHIL_Vx_oCAN00_8d662997_Rx, (data))) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_P_HIL_Cmd_Fault Rte_Write_HIL_Controller_P_HIL_Cmd_Fault
#  define Rte_Write_P_HIL_Cmd_Heartbeat Rte_Write_HIL_Controller_P_HIL_Cmd_Heartbeat
#  define Rte_Write_P_HIL_Cmd_Pcon Rte_Write_HIL_Controller_P_HIL_Cmd_Pcon
#  define Rte_Write_P_HIL_Cmd_Throttle Rte_Write_HIL_Controller_P_HIL_Cmd_Throttle


# endif /* !defined(RTE_CORE) */


# define HIL_Controller_START_SEC_CODE
# include "HIL_Controller_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_Run_HIL_PI_10ms HIL_Controller_Run10ms
# endif

FUNC(void, HIL_Controller_CODE) HIL_Controller_Run10ms(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define HIL_Controller_STOP_SEC_CODE
# include "HIL_Controller_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_HIL_CONTROLLER_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
