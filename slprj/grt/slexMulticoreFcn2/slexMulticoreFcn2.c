/*
 * Code generation for system model 'slexMulticoreFcn2'
 *
 * Model                      : slexMulticoreFcn2
 * Model version              : 1.270
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Wed Jan 17 07:21:15 2018
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "slexMulticoreFcn2.h"
#include "slexMulticoreFcn2_private.h"

/* System initialize for referenced model: 'slexMulticoreFcn2' */
void slexMulticoreFcn2_Init(DW_slexMulticoreFcn2_f_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<Root>/Delay' */
  localDW->Delay_DSTATE = 1;

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
  localDW->UnitDelay_DSTATE = 0.0;

  /* SystemInitialize for Iterator SubSystem: '<Root>/For Iterator Subsystem' */
  /* InitializeConditions for Memory: '<S1>/Memory' */
  localDW->Memory_PreviousInput = 0.0;

  /* End of SystemInitialize for SubSystem: '<Root>/For Iterator Subsystem' */
}

/* System reset for referenced model: 'slexMulticoreFcn2' */
void slexMulticoreFcn2_Reset(DW_slexMulticoreFcn2_f_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<Root>/Delay' */
  localDW->Delay_DSTATE = 1;

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
  localDW->UnitDelay_DSTATE = 0.0;
}

/* Outputs for referenced model: 'slexMulticoreFcn2' */
void slexMulticoreFcn2TID0(real_T *rty_Subtracter, DW_slexMulticoreFcn2_f_T
  *localDW)
{
  int32_T s1_iter;

  /* UnitDelay: '<Root>/Unit Delay' */
  *rty_Subtracter = localDW->UnitDelay_DSTATE;

  /* Outputs for Iterator SubSystem: '<Root>/For Iterator Subsystem' incorporates:
   *  ForIterator: '<S1>/For Iterator'
   */
  for (s1_iter = 1; s1_iter <= 1000000; s1_iter++) {
    /* Update for Memory: '<S1>/Memory' incorporates:
     *  Product: '<S1>/Divide'
     *  Sum: '<S1>/Sum'
     *  Trigonometry: '<S1>/Trigonometric Function'
     *  Trigonometry: '<S1>/Trigonometric Function1'
     */
    localDW->Memory_PreviousInput -= sin(localDW->Memory_PreviousInput) / cos
      (localDW->Memory_PreviousInput);
  }

  /* End of Outputs for SubSystem: '<Root>/For Iterator Subsystem' */
}

/* Outputs for referenced model: 'slexMulticoreFcn2' */
void slexMulticoreFcn2TID1(int8_T *rty_TicToc, B_slexMulticoreFcn2_c_T *localB,
  DW_slexMulticoreFcn2_f_T *localDW)
{
  /* UnitDelay: '<Root>/Delay' */
  *rty_TicToc = localDW->Delay_DSTATE;

  /* Gain: '<Root>/Gain' */
  localB->Gain = (int8_T)(((-128) * *rty_TicToc) >> 7);
}

/* Update for referenced model: 'slexMulticoreFcn2' */
void slexMulticoreFcn2_UpdateTID0(const real_T *rtu_u1, const real_T *rtu_u2,
  DW_slexMulticoreFcn2_f_T *localDW)
{
  /* Update for UnitDelay: '<Root>/Unit Delay' incorporates:
   *  Sum: '<Root>/Subtract'
   */
  localDW->UnitDelay_DSTATE = *rtu_u1 - *rtu_u2;
}

/* Update for referenced model: 'slexMulticoreFcn2' */
void slexMulticoreFcn2_UpdateTID1(B_slexMulticoreFcn2_c_T *localB,
  DW_slexMulticoreFcn2_f_T *localDW)
{
  /* Update for UnitDelay: '<Root>/Delay' */
  localDW->Delay_DSTATE = localB->Gain;
}

/* Model initialize function */
void slexMulticoreFcn2_initialize(const char_T **rt_errorStatus,
  RT_MODEL_slexMulticoreFcn2_T *const slexMulticoreFcn2_M,
  B_slexMulticoreFcn2_c_T *localB, DW_slexMulticoreFcn2_f_T *localDW)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(slexMulticoreFcn2_M, rt_errorStatus);

  /* block I/O */
  (void) memset(((void *) localB), 0,
                sizeof(B_slexMulticoreFcn2_c_T));

  /* states (dwork) */
  (void) memset((void *)localDW, 0,
                sizeof(DW_slexMulticoreFcn2_f_T));
}
