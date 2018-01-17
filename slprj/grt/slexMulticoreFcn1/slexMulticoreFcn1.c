/*
 * Code generation for system model 'slexMulticoreFcn1'
 *
 * Model                      : slexMulticoreFcn1
 * Model version              : 1.263
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Wed Jan 17 07:21:05 2018
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "slexMulticoreFcn1.h"
#include "slexMulticoreFcn1_private.h"

/* System initialize for referenced model: 'slexMulticoreFcn1' */
void slexMulticoreFcn1_Init(DW_slexMulticoreFcn1_f_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<Root>/Delay' */
  localDW->Delay_DSTATE = 1;

  /* SystemInitialize for Iterator SubSystem: '<Root>/For Iterator Subsystem' */
  /* InitializeConditions for Memory: '<S1>/Memory' */
  localDW->Memory_PreviousInput = 0.0;

  /* End of SystemInitialize for SubSystem: '<Root>/For Iterator Subsystem' */
}

/* System reset for referenced model: 'slexMulticoreFcn1' */
void slexMulticoreFcn1_Reset(DW_slexMulticoreFcn1_f_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<Root>/Delay' */
  localDW->Delay_DSTATE = 1;
}

/* Outputs for referenced model: 'slexMulticoreFcn1' */
void slexMulticoreFcn1(const real_T *rtu_U1, const real_T *rtu_U2, int8_T
  *rty_TicToc1, real_T *rty_Adder, B_slexMulticoreFcn1_c_T *localB,
  DW_slexMulticoreFcn1_f_T *localDW)
{
  int32_T s1_iter;

  /* UnitDelay: '<Root>/Delay' */
  *rty_TicToc1 = localDW->Delay_DSTATE;

  /* Gain: '<Root>/Gain' */
  localB->Gain = (int8_T)(((-128) * *rty_TicToc1) >> 7);

  /* Sum: '<Root>/Add' */
  *rty_Adder = *rtu_U1 + *rtu_U2;

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

/* Update for referenced model: 'slexMulticoreFcn1' */
void slexMulticoreFcn1_Update(B_slexMulticoreFcn1_c_T *localB,
  DW_slexMulticoreFcn1_f_T *localDW)
{
  /* Update for UnitDelay: '<Root>/Delay' */
  localDW->Delay_DSTATE = localB->Gain;
}

/* Model initialize function */
void slexMulticoreFcn1_initialize(const char_T **rt_errorStatus,
  RT_MODEL_slexMulticoreFcn1_T *const slexMulticoreFcn1_M,
  B_slexMulticoreFcn1_c_T *localB, DW_slexMulticoreFcn1_f_T *localDW)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(slexMulticoreFcn1_M, rt_errorStatus);

  /* block I/O */
  (void) memset(((void *) localB), 0,
                sizeof(B_slexMulticoreFcn1_c_T));

  /* states (dwork) */
  (void) memset((void *)localDW, 0,
                sizeof(DW_slexMulticoreFcn1_f_T));
}
