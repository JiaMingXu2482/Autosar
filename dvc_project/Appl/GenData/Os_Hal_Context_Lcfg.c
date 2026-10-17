/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Os
 *           Program: MSR_Vector_SLP4
 *          Customer: Harman International (China) Holdings Co., Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: FS32K148UAT0VLQR
 *    License Scope : The usage is restricted to CBD1800257_D01
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Hal_Context_Lcfg.c
 *   Generation Time: 2026-10-17 11:49:10
 *           Project: s32k_dvc - Version 1.0
 *          Delivery: CBD1800257_D01
 *      Tool Version: DaVinci Configurator  5.18.65 SP5
 *
 *
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0810, 0828, 0857 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779, MD_MSR_1.1_810, MD_MSR_1.1_828, MD_MSR_1.1_857 */

#define OS_HAL_CONTEXT_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Hal_Context_Lcfg.h"
#include "Os_Hal_Context.h"

/* Os kernel module dependencies */
#include "OsInt.h"
#include "Os_Core.h"
#include "Os_Hook_Lcfg.h"
#include "Os_Hook.h"
#include "Os_Ioc_Lcfg.h"
#include "Os_Isr_Lcfg.h"
#include "Os_Lcfg.h"
#include "Os_Stack_Lcfg.h"
#include "Os_Task_Lcfg.h"
#include "Os_Task.h"

/* Os hal dependencies */
#include "Os_Hal_Core.h"


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! HAL dynamic hook context data: Os_CoreInitHook_OsCore0 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_Os_CoreInitHook_OsCore0_Dyn;

/*! HAL dynamic hook context data: ErrorHook_OsCore0 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_ErrorHook_OsCore0_Dyn;

/*! HAL dynamic ISR2 level context data: Level1 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_Isr_Level1_Dyn;

/*! HAL dynamic task context data: IdleTask_OsCore0 */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_IdleTask_OsCore0_Dyn;

/*! HAL dynamic task context data: OsTask_10ms */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_10ms_Dyn;

/*! HAL dynamic task context data: OsTask_BSW */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_BSW_Dyn;

/*! HAL dynamic task context data: OsTask_Init */
VAR(Os_Hal_ContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsTask_Init_Dyn;

/*! HAL exception context data: OsCore0 */
VAR(Os_ExceptionContextType, OS_VAR_NOINIT) OsCfg_Hal_Context_OsCore0_ExceptionContext;

#define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! HAL hook context configuration data: Os_CoreInitHook_OsCore0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_Os_CoreInitHook_OsCore0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Init_Dyn)+1),  /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData*/
  /* .Control          = */ OS_HAL_CONTROL_PRIVILEGED | OS_HAL_CONTROL_MSP_USED,
  /* .Basepri          = */ (32uL),
  /* .Entry            = */ (uint32)&Os_HookWrapperOs_CoreInitHook,   /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapHookReturn,  /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Init_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_0306 */
  /* .StackRegionInfo  = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Init_Dyn) + 1)  /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData */
};

/*! HAL hook context configuration data: ErrorHook_OsCore0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_ErrorHook_OsCore0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Error_Dyn)+1),  /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData*/
  /* .Control          = */ OS_HAL_CONTROL_PRIVILEGED | OS_HAL_CONTROL_MSP_USED,
  /* .Basepri          = */ (32uL),
  /* .Entry            = */ (uint32)&Os_HookWrapperStatusHook,   /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapHookReturn,  /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Error_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_0306 */
  /* .StackRegionInfo  = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Error_Dyn) + 1)  /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData */
};

/*! HAL ISR2 context configuration data: CounterIsr_SystemTimer */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_CounterIsr_SystemTimer =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn)+1),   /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData*/
  /* .Control          = */ OS_HAL_CONTROL_PRIVILEGED | OS_HAL_CONTROL_MSP_USED,
  /* .Basepri          = */ 32uL,
  /* .Entry            = */ (uint32)&Os_Isr_Os_TimerPitIsr,   /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapIsrEpilogue,   /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_0306 */
  /* .StackRegionInfo  = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Isr_Core_Dyn) + 1)  /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData */
};

/*! HAL task context configuration data: IdleTask_OsCore0 */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_IdleTask_OsCore0 =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio4294967295_Dyn)+1),   /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData*/
  /* .Control          = */ OS_HAL_CONTROL_PRIVILEGED | OS_HAL_CONTROL_MSP_USED,
  /* .Basepri          = */ (uint32)OS_HAL_TASK_LEVEL,
  /* .Entry            = */ (uint32)&Os_Task_Os_IdleTask,   /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,   /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Task_Prio4294967295_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_0306 */
  /* .StackRegionInfo  = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio4294967295_Dyn) + 1)  /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData */
};

/*! HAL task context configuration data: OsTask_10ms */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_10ms =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio2_Dyn)+1),   /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData*/
  /* .Control          = */ OS_HAL_CONTROL_PRIVILEGED | OS_HAL_CONTROL_MSP_USED,
  /* .Basepri          = */ (uint32)OS_HAL_TASK_LEVEL,
  /* .Entry            = */ (uint32)&Os_Task_OsTask_10ms,   /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,   /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Task_Prio2_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_0306 */
  /* .StackRegionInfo  = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio2_Dyn) + 1)  /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData */
};

/*! HAL task context configuration data: OsTask_BSW */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_BSW =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsTask_BSW_Dyn)+1),   /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData*/
  /* .Control          = */ OS_HAL_CONTROL_PRIVILEGED | OS_HAL_CONTROL_MSP_USED,
  /* .Basepri          = */ (uint32)OS_HAL_TASK_LEVEL,
  /* .Entry            = */ (uint32)&Os_Task_OsTask_BSW,   /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,   /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsTask_BSW_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_0306 */
  /* .StackRegionInfo  = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsTask_BSW_Dyn) + 1)  /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData */
};

/*! HAL task context configuration data: OsTask_Init */
CONST(Os_Hal_ContextConfigType, OS_CONST) OsCfg_Hal_Context_OsTask_Init =
{
  /* .StackEndAddr     = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio3_Dyn)+1),   /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData*/
  /* .Control          = */ OS_HAL_CONTROL_PRIVILEGED | OS_HAL_CONTROL_MSP_USED,
  /* .Basepri          = */ (uint32)OS_HAL_TASK_LEVEL,
  /* .Entry            = */ (uint32)&Os_Task_OsTask_Init,   /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .ReturnAddress    = */ (uint32)&Os_TrapTaskMissingTerminateTask,   /* PRQA S 0305, 0428 */ /* MD_Os_Hal_0305, MD_Os_Hal_0428 */
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Task_Prio3_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_0306 */
  /* .StackRegionInfo  = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Task_Prio3_Dyn) + 1)  /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData */
};

/*! HAL kernel stack configuration data: OsCore0_Kernel */
CONST(Os_Hal_ContextStackConfigType, OS_CONST) OsCfg_Hal_Stack_OsCore0_Kernel =
{
  /* .StackRegionEnd   = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Kernel_Dyn)+1),  /* OsCore0_Kernel */   /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData*/
  /* .StackRegionStart = */ (uint32)OS_STACK_GETLOWADDRESS(OsCfg_Stack_OsCore0_Kernel_Dyn),  /* PRQA S 0306 */ /* MD_Os_Hal_0306 */
  /* .StackRegionInfo  = */ (uint32)(OS_STACK_GETHIGHADDRESS(OsCfg_Stack_OsCore0_Kernel_Dyn) + 1)  /* PRQA S 0306, 0489 */ /* MD_Os_Hal_0306, MD_Os_Hal_0489_GenData */
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



#define OS_START_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*! Object reference table for HAL exception context. */
CONSTP2VAR(Os_ExceptionContextType, AUTOMATIC, OS_CONST)
  OsCfg_Hal_Context_ExceptionContextRef[OS_CFG_COREPHYSICALID_COUNT + 1] =
{
  &OsCfg_Hal_Context_OsCore0_ExceptionContext,
  NULL_PTR
};

#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Context_Lcfg.c
 *********************************************************************************************************************/
