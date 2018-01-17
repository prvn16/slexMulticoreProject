/*
 * slexMulticoreExample.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "slexMulticoreExample".
 *
 * Model version              : 1.278
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Wed Jan 17 07:21:29 2018
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Specified
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "slexMulticoreExample.h"
#include "slexMulticoreExample_private.h"

/* Tasks */
RT_MODEL_slexMulticoreExample_T task_M_[4];
RT_MODEL_slexMulticoreExample_T *task_M[4];

/* Exported block signals */
real_T U1;                             /* '<Root>/In1' */
real_T U2;                             /* '<Root>/In2' */
int8_T TicToc1;                        /* '<Root>/Fcn1' */
int8_T TicToc2;                        /* '<Root>/Fcn2' */

/* Block signals (auto storage) */
B_slexMulticoreExample_T slexMulticoreExample_B;

/* Block states (auto storage) */
DW_slexMulticoreExample_T slexMulticoreExample_DW;

/* Real-time model */
RT_MODEL_slexMulticoreExample_T slexMulticoreExample_M_;
RT_MODEL_slexMulticoreExample_T *const slexMulticoreExample_M =
  &slexMulticoreExample_M_;

/*   This function updates active task counters and model execution time. */
void AdvanceTaskCounters(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (slexMulticoreExample_M->Timing.TaskCounters.TID[1])++;
  if ((slexMulticoreExample_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.2s, 0.0s] */
    slexMulticoreExample_M->Timing.TaskCounters.TID[1] = 0;
  }

  (slexMulticoreExample_M->Timing.TaskCounters.TID[2])++;
  if ((slexMulticoreExample_M->Timing.TaskCounters.TID[2]) > 3) {/* Sample time: [0.4s, 0.0s] */
    slexMulticoreExample_M->Timing.TaskCounters.TID[2] = 0;
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
}

/* Output for Task: Core1_Task1 */
void Core1_Task1_output(void)          /* Sample time: [0.1s, 0.0s] */
{
  /* TaskTransBlk: '<Root>/TmpTaskTransAtFcn1Inport2' */
  slexMulticoreExample_B.TmpTaskTransAtFcn1Inport2 =
    slexMulticoreExample_DW.TmpTaskTransAtFcn3Outport1_buf_1[slexMulticoreExample_DW.fr_buf_1];
  slexMulticoreExample_DW.fr_buf_1 = 1 - slexMulticoreExample_DW.fr_buf_1;

  /* ModelReference: '<Root>/Fcn1' incorporates:
   *  Inport: '<Root>/In1'
   */
  slexMulticoreFcn1(&U1, &slexMulticoreExample_B.TmpTaskTransAtFcn1Inport2,
                    &TicToc1, &slexMulticoreExample_B.Fcn1_o2,
                    &(slexMulticoreExample_DW.Fcn1_InstanceData.rtb),
                    &(slexMulticoreExample_DW.Fcn1_InstanceData.rtdw));

  {
    int8_T wrBufIdx;

    /* RateTransition: '<Root>/TmpRTBAtFcn2Inport1' */
    rtw_win_mutex_wait(slexMulticoreExample_DW.TmpRTBAtFcn2Inport1_d0_SEMAPHORE);
    wrBufIdx = (int8_T)(slexMulticoreExample_DW.TmpRTBAtFcn2Inport1_LstBufWR + 1);
    if (wrBufIdx == 3) {
      wrBufIdx = 0;
    }

    if (wrBufIdx == slexMulticoreExample_DW.TmpRTBAtFcn2Inport1_RDBuf) {
      wrBufIdx++;
      if (wrBufIdx == 3) {
        wrBufIdx = 0;
      }
    }

    rtw_win_mutex_release
      (slexMulticoreExample_DW.TmpRTBAtFcn2Inport1_d0_SEMAPHORE);
    switch (wrBufIdx) {
     case 0:
      slexMulticoreExample_DW.TmpRTBAtFcn2Inport1_Buf0 =
        slexMulticoreExample_B.Fcn1_o2;
      break;

     case 1:
      slexMulticoreExample_DW.TmpRTBAtFcn2Inport1_Buf1 =
        slexMulticoreExample_B.Fcn1_o2;
      break;

     case 2:
      slexMulticoreExample_DW.TmpRTBAtFcn2Inport1_Buf2 =
        slexMulticoreExample_B.Fcn1_o2;
      break;
    }

    slexMulticoreExample_DW.TmpRTBAtFcn2Inport1_LstBufWR = wrBufIdx;

    /* End of RateTransition: '<Root>/TmpRTBAtFcn2Inport1' */
  }
}

/* Update for Task: Core1_Task1 */
void Core1_Task1_update(void)          /* Sample time: [0.1s, 0.0s] */
{
  /* Update for ModelReference: '<Root>/Fcn1' incorporates:
   *  Inport: '<Root>/In1'
   */
  slexMulticoreFcn1_Update(&(slexMulticoreExample_DW.Fcn1_InstanceData.rtb),
    &(slexMulticoreExample_DW.Fcn1_InstanceData.rtdw));
}

/* Output for Task: Core1_Task2 */
void Core1_Task2_output(void)          /* Sample time: [0.1s, 0.0s] */
{
  /* RateTransition: '<Root>/TmpRTBAtFcn3Inport1' */
  rtw_win_mutex_wait(slexMulticoreExample_DW.TmpRTBAtFcn3Inport1_d0_SEMAPHORE);
  slexMulticoreExample_DW.TmpRTBAtFcn3Inport1_RDBuf =
    slexMulticoreExample_DW.TmpRTBAtFcn3Inport1_LstBufWR;
  rtw_win_mutex_release(slexMulticoreExample_DW.TmpRTBAtFcn3Inport1_d0_SEMAPHORE);
  slexMulticoreExample_B.TmpRTBAtFcn3Inport1 =
    slexMulticoreExample_DW.TmpRTBAtFcn3Inport1_Buf[slexMulticoreExample_DW.TmpRTBAtFcn3Inport1_RDBuf];

  {
    boolean_T p;
    boolean_T p_p;

    /* MATLABSystem: '<Root>/Fcn3' incorporates:
     *  Inport: '<Root>/In2'
     */
    p = false;
    p_p = true;
    if (!(slexMulticoreExample_DW.obj.nIter == 1.0E+6)) {
      p_p = false;
    }

    if (p_p) {
      p = true;
    }

    if (!p) {
      slexMulticoreExample_DW.obj.nIter = 1.0E+6;
    }

    slexMulticoreExample_B.Fcn3 = slexMulticoreExample_B.TmpRTBAtFcn3Inport1 *
      U2;

    /* End of MATLABSystem: '<Root>/Fcn3' */

    /* TaskTransBlk: '<Root>/TmpTaskTransAtFcn3Outport1' */
    slexMulticoreExample_DW.TmpTaskTransAtFcn3Outport1_buf_1[slexMulticoreExample_DW.fw_buf_1]
      = slexMulticoreExample_B.Fcn3;
    slexMulticoreExample_DW.fw_buf_1 = 1 - slexMulticoreExample_DW.fw_buf_1;
  }

  {
    int8_T wrBufIdx;

    /* RateTransition: '<Root>/TmpRTBAtFcn2Inport2' */
    rtw_win_mutex_wait(slexMulticoreExample_DW.TmpRTBAtFcn2Inport2_d0_SEMAPHORE);
    wrBufIdx = (int8_T)(slexMulticoreExample_DW.TmpRTBAtFcn2Inport2_LstBufWR + 1);
    if (wrBufIdx == 3) {
      wrBufIdx = 0;
    }

    if (wrBufIdx == slexMulticoreExample_DW.TmpRTBAtFcn2Inport2_RDBuf) {
      wrBufIdx++;
      if (wrBufIdx == 3) {
        wrBufIdx = 0;
      }
    }

    rtw_win_mutex_release
      (slexMulticoreExample_DW.TmpRTBAtFcn2Inport2_d0_SEMAPHORE);
    switch (wrBufIdx) {
     case 0:
      slexMulticoreExample_DW.TmpRTBAtFcn2Inport2_Buf0 =
        slexMulticoreExample_B.Fcn3;
      break;

     case 1:
      slexMulticoreExample_DW.TmpRTBAtFcn2Inport2_Buf1 =
        slexMulticoreExample_B.Fcn3;
      break;

     case 2:
      slexMulticoreExample_DW.TmpRTBAtFcn2Inport2_Buf2 =
        slexMulticoreExample_B.Fcn3;
      break;
    }

    slexMulticoreExample_DW.TmpRTBAtFcn2Inport2_LstBufWR = wrBufIdx;

    /* End of RateTransition: '<Root>/TmpRTBAtFcn2Inport2' */
  }
}

/* Update for Task: Core1_Task2 */
void Core1_Task2_update(void)          /* Sample time: [0.1s, 0.0s] */
{
}

/* Output for Task: Core2_Task3 */
void Core2_Task3_output(void)          /* Sample time: [0.2s, 0.0s] */
{
  /* ModelReference: '<Root>/Fcn2' */
  slexMulticoreFcn2TID0(&slexMulticoreExample_B.Fcn2_o2,
                        &(slexMulticoreExample_DW.Fcn2_InstanceData.rtdw));

  /* RateTransition: '<Root>/TmpRTBAtFcn2Inport1' */
  rtw_win_mutex_wait(slexMulticoreExample_DW.TmpRTBAtFcn2Inport1_d0_SEMAPHORE);
  slexMulticoreExample_DW.TmpRTBAtFcn2Inport1_RDBuf =
    slexMulticoreExample_DW.TmpRTBAtFcn2Inport1_LstBufWR;
  rtw_win_mutex_release(slexMulticoreExample_DW.TmpRTBAtFcn2Inport1_d0_SEMAPHORE);
  switch (slexMulticoreExample_DW.TmpRTBAtFcn2Inport1_RDBuf) {
   case 0:
    slexMulticoreExample_B.TmpRTBAtFcn2Inport1 =
      slexMulticoreExample_DW.TmpRTBAtFcn2Inport1_Buf0;
    break;

   case 1:
    slexMulticoreExample_B.TmpRTBAtFcn2Inport1 =
      slexMulticoreExample_DW.TmpRTBAtFcn2Inport1_Buf1;
    break;

   case 2:
    slexMulticoreExample_B.TmpRTBAtFcn2Inport1 =
      slexMulticoreExample_DW.TmpRTBAtFcn2Inport1_Buf2;
    break;
  }

  /* End of RateTransition: '<Root>/TmpRTBAtFcn2Inport1' */

  /* RateTransition: '<Root>/TmpRTBAtFcn2Inport2' */
  rtw_win_mutex_wait(slexMulticoreExample_DW.TmpRTBAtFcn2Inport2_d0_SEMAPHORE);
  slexMulticoreExample_DW.TmpRTBAtFcn2Inport2_RDBuf =
    slexMulticoreExample_DW.TmpRTBAtFcn2Inport2_LstBufWR;
  rtw_win_mutex_release(slexMulticoreExample_DW.TmpRTBAtFcn2Inport2_d0_SEMAPHORE);
  switch (slexMulticoreExample_DW.TmpRTBAtFcn2Inport2_RDBuf) {
   case 0:
    slexMulticoreExample_B.TmpRTBAtFcn2Inport2 =
      slexMulticoreExample_DW.TmpRTBAtFcn2Inport2_Buf0;
    break;

   case 1:
    slexMulticoreExample_B.TmpRTBAtFcn2Inport2 =
      slexMulticoreExample_DW.TmpRTBAtFcn2Inport2_Buf1;
    break;

   case 2:
    slexMulticoreExample_B.TmpRTBAtFcn2Inport2 =
      slexMulticoreExample_DW.TmpRTBAtFcn2Inport2_Buf2;
    break;
  }

  /* End of RateTransition: '<Root>/TmpRTBAtFcn2Inport2' */
}

/* Update for Task: Core2_Task3 */
void Core2_Task3_update(void)          /* Sample time: [0.2s, 0.0s] */
{
  /* Update for ModelReference: '<Root>/Fcn2' */
  slexMulticoreFcn2_UpdateTID0(&slexMulticoreExample_B.TmpRTBAtFcn2Inport1,
    &slexMulticoreExample_B.TmpRTBAtFcn2Inport2,
    &(slexMulticoreExample_DW.Fcn2_InstanceData.rtdw));

  {
    int8_T wrBufIdx;

    /* Update for RateTransition: '<Root>/TmpRTBAtFcn3Inport1' */
    rtw_win_mutex_wait(slexMulticoreExample_DW.TmpRTBAtFcn3Inport1_d0_SEMAPHORE);
    wrBufIdx = (int8_T)(slexMulticoreExample_DW.TmpRTBAtFcn3Inport1_LstBufWR + 1);
    if (wrBufIdx == 3) {
      wrBufIdx = 0;
    }

    if (wrBufIdx == slexMulticoreExample_DW.TmpRTBAtFcn3Inport1_RDBuf) {
      wrBufIdx++;
      if (wrBufIdx == 3) {
        wrBufIdx = 0;
      }
    }

    rtw_win_mutex_release
      (slexMulticoreExample_DW.TmpRTBAtFcn3Inport1_d0_SEMAPHORE);
    slexMulticoreExample_DW.TmpRTBAtFcn3Inport1_Buf[wrBufIdx] =
      slexMulticoreExample_B.Fcn2_o2;
    slexMulticoreExample_DW.TmpRTBAtFcn3Inport1_LstBufWR = wrBufIdx;

    /* End of Update for RateTransition: '<Root>/TmpRTBAtFcn3Inport1' */
  }
}

/* Output for Task: Core2_Task4 */
void Core2_Task4_output(void)          /* Sample time: [0.4s, 0.0s] */
{
  /* ModelReference: '<Root>/Fcn2' */
  slexMulticoreFcn2TID1(&TicToc2,
                        &(slexMulticoreExample_DW.Fcn2_InstanceData.rtb),
                        &(slexMulticoreExample_DW.Fcn2_InstanceData.rtdw));
}

/* Update for Task: Core2_Task4 */
void Core2_Task4_update(void)          /* Sample time: [0.4s, 0.0s] */
{
  /* Update for ModelReference: '<Root>/Fcn2' */
  slexMulticoreFcn2_UpdateTID1(&(slexMulticoreExample_DW.Fcn2_InstanceData.rtb),
    &(slexMulticoreExample_DW.Fcn2_InstanceData.rtdw));
}

void slexMulticoreExample_output(int_T tid)
{
  switch (tid) {
   case 0 :
    Core1_Task1_output();
    break;

   case 1 :
    Core1_Task2_output();
    break;

   case 2 :
    Core2_Task3_output();
    break;

   case 3 :
    Core2_Task4_output();
    break;

   default :
    break;
  }
}

void slexMulticoreExample_update(int_T tid)
{
  switch (tid) {
   case 0 :
    Core1_Task1_update();
    break;

   case 2 :
    Core2_Task3_update();
    break;

   case 3 :
    Core2_Task4_update();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void slexMulticoreExample_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)slexMulticoreExample_M, 0,
                sizeof(RT_MODEL_slexMulticoreExample_T));
  (slexMulticoreExample_M)->Timing.TaskCounters.cLimit[0] = 1;
  (slexMulticoreExample_M)->Timing.TaskCounters.cLimit[1] = 2;
  (slexMulticoreExample_M)->Timing.TaskCounters.cLimit[2] = 4;

  /* block I/O */
  (void) memset(((void *) &slexMulticoreExample_B), 0,
                sizeof(B_slexMulticoreExample_T));

  /* exported global signals */
  TicToc1 = 0;
  TicToc2 = 0;

  /* states (dwork) */
  (void) memset((void *)&slexMulticoreExample_DW, 0,
                sizeof(DW_slexMulticoreExample_T));

  /* external inputs */
  U1 = 0.0;
  U2 = 0.0;

  {
    /* user code (registration function declaration) */
    int_T tIdx;
    for (tIdx = 0; tIdx < 4; tIdx++) {
      task_M[tIdx] = &task_M_[tIdx];

      /* initialize real-time model */
      (void) memset((void *) task_M[tIdx], 0,
                    sizeof(RT_MODEL_slexMulticoreExample_T));
      task_M[tIdx]->Timing.TaskCounters.cLimit[0] = 1;
      task_M[tIdx]->Timing.TaskCounters.cLimit[1] = 2;
      task_M[tIdx]->Timing.TaskCounters.cLimit[2] = 4;
    }
  }

  /* Model Initialize fcn for ModelReference Block: '<Root>/Fcn1' */
  slexMulticoreFcn1_initialize(rtmGetErrorStatusPointer(slexMulticoreExample_M),
    &(slexMulticoreExample_DW.Fcn1_InstanceData.rtm),
    &(slexMulticoreExample_DW.Fcn1_InstanceData.rtb),
    &(slexMulticoreExample_DW.Fcn1_InstanceData.rtdw));

  /* Model Initialize fcn for ModelReference Block: '<Root>/Fcn2' */
  slexMulticoreFcn2_initialize(rtmGetErrorStatusPointer(slexMulticoreExample_M),
    &(slexMulticoreExample_DW.Fcn2_InstanceData.rtm),
    &(slexMulticoreExample_DW.Fcn2_InstanceData.rtb),
    &(slexMulticoreExample_DW.Fcn2_InstanceData.rtdw));

  /* Start for atomic system: 'synthesized block' */

  /* Start for RateTransition: '<Root>/TmpRTBAtFcn3Inport1' */
  slexMulticoreExample_B.TmpRTBAtFcn3Inport1 = 0.0;
  rtw_win_mutex_create(&slexMulticoreExample_DW.TmpRTBAtFcn3Inport1_d0_SEMAPHORE);

  /* Start for atomic system: 'synthesized block' */

  /* Start for MATLABSystem: '<Root>/Fcn3' */
  slexMulticoreExample_DW.obj.isInitialized = 0;
  slexMulticoreExample_DW.objisempty = true;
  slexMulticoreExample_DW.obj.nIter = 1.0E+6;
  slexMulticoreExample_DW.obj.isInitialized = 1;

  /* Start for atomic system: 'synthesized block' */

  /* Start for RateTransition: '<Root>/TmpRTBAtFcn2Inport1' */
  slexMulticoreExample_B.TmpRTBAtFcn2Inport1 = 0.0;
  rtw_win_mutex_create(&slexMulticoreExample_DW.TmpRTBAtFcn2Inport1_d0_SEMAPHORE);

  /* Start for atomic system: 'synthesized block' */

  /* Start for RateTransition: '<Root>/TmpRTBAtFcn2Inport2' */
  slexMulticoreExample_B.TmpRTBAtFcn2Inport2 = 0.0;
  rtw_win_mutex_create(&slexMulticoreExample_DW.TmpRTBAtFcn2Inport2_d0_SEMAPHORE);

  /* System initialize for atomic system: 'synthesized block' */

  /* InitializeConditions for TaskTransBlk: '<Root>/TmpTaskTransAtFcn1Inport2' */
  slexMulticoreExample_DW.fr_buf_1 = 1;
  slexMulticoreExample_DW.TmpTaskTransAtFcn3Outport1_buf_1[1] = 0.0;

  /* SystemInitialize for ModelReference: '<Root>/Fcn1' incorporates:
   *  Inport: '<Root>/In1'
   */
  slexMulticoreFcn1_Init(&(slexMulticoreExample_DW.Fcn1_InstanceData.rtdw));

  /* System initialize for atomic system: 'synthesized block' */

  /* SystemInitialize for ModelReference: '<Root>/Fcn2' */
  slexMulticoreFcn2_Init(&(slexMulticoreExample_DW.Fcn2_InstanceData.rtdw));

  /* System initialize for atomic system: 'synthesized block' */

  /* InitializeConditions for RateTransition: '<Root>/TmpRTBAtFcn3Inport1' */
  slexMulticoreExample_DW.TmpRTBAtFcn3Inport1_Buf[0] = 0.0;

  /* System initialize for atomic system: 'synthesized block' */

  /* InitializeConditions for TaskTransBlk: '<Root>/TmpTaskTransAtFcn3Outport1' */
  slexMulticoreExample_DW.fw_buf_1 = 0;

  /* System initialize for atomic system: 'synthesized block' */

  /* InitializeConditions for RateTransition: '<Root>/TmpRTBAtFcn2Inport1' */
  slexMulticoreExample_DW.TmpRTBAtFcn2Inport1_Buf0 = 0.0;

  /* System initialize for atomic system: 'synthesized block' */

  /* InitializeConditions for RateTransition: '<Root>/TmpRTBAtFcn2Inport2' */
  slexMulticoreExample_DW.TmpRTBAtFcn2Inport2_Buf0 = 0.0;
}

/* Model terminate function */
void slexMulticoreExample_terminate(void)
{
  /* Termination for atomic system: 'synthesized block' */

  /* Terminate for RateTransition: '<Root>/TmpRTBAtFcn3Inport1' */
  rtw_win_mutex_close(slexMulticoreExample_DW.TmpRTBAtFcn3Inport1_d0_SEMAPHORE);

  /* Termination for atomic system: 'synthesized block' */

  /* Terminate for MATLABSystem: '<Root>/Fcn3' */
  if (slexMulticoreExample_DW.obj.isInitialized == 1) {
    slexMulticoreExample_DW.obj.isInitialized = 2;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Fcn3' */

  /* Termination for atomic system: 'synthesized block' */

  /* Terminate for RateTransition: '<Root>/TmpRTBAtFcn2Inport1' */
  rtw_win_mutex_close(slexMulticoreExample_DW.TmpRTBAtFcn2Inport1_d0_SEMAPHORE);

  /* Termination for atomic system: 'synthesized block' */

  /* Terminate for RateTransition: '<Root>/TmpRTBAtFcn2Inport2' */
  rtw_win_mutex_close(slexMulticoreExample_DW.TmpRTBAtFcn2Inport2_d0_SEMAPHORE);
}
