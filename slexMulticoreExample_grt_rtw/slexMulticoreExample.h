/*
 * slexMulticoreExample.h
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

#ifndef RTW_HEADER_slexMulticoreExample_h_
#define RTW_HEADER_slexMulticoreExample_h_
#include <string.h>
#include <stddef.h>
#ifndef slexMulticoreExample_COMMON_INCLUDES_
# define slexMulticoreExample_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* slexMulticoreExample_COMMON_INCLUDES_ */

#include "slexMulticoreExample_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Child system includes */
#include "slexMulticoreFcn2.h"
#include "slexMulticoreFcn1.h"
#include "rtw_windows.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmCounterLimit
# define rtmCounterLimit(rtm, idx)     ((rtm)->Timing.TaskCounters.cLimit[(idx)])
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetErrorStatusPointer
# define rtmGetErrorStatusPointer(rtm) ((const char_T **)(&((rtm)->errorStatus)))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T Fcn3;                         /* '<Root>/Fcn3' */
  real_T TmpTaskTransAtFcn3Outport1;   /* '<Root>/Fcn3' */
  real_T TmpTaskTransAtFcn1Inport2;
  real_T Fcn1_o2;                      /* '<Root>/Fcn1' */
  real_T Fcn2_o2;                      /* '<Root>/Fcn2' */
  real_T TmpRTBAtFcn3Inport1;          /* '<Root>/Fcn2' */
  real_T TmpRTBAtFcn2Inport1;          /* '<Root>/Fcn1' */
  real_T TmpRTBAtFcn2Inport2;          /* '<Root>/Fcn3' */
} B_slexMulticoreExample_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  slexMulticoreFcn3_slexMulticoreExample_T obj;/* '<Root>/Fcn3' */
  real_T TmpTaskTransAtFcn3Outport1_buf_1[2];/* synthesized block */
  real_T TmpRTBAtFcn3Inport1_Buf[3];   /* synthesized block */
  real_T TmpRTBAtFcn2Inport1_Buf0;     /* synthesized block */
  real_T TmpRTBAtFcn2Inport1_Buf1;     /* synthesized block */
  real_T TmpRTBAtFcn2Inport1_Buf2;     /* synthesized block */
  real_T TmpRTBAtFcn2Inport2_Buf0;     /* synthesized block */
  real_T TmpRTBAtFcn2Inport2_Buf1;     /* synthesized block */
  real_T TmpRTBAtFcn2Inport2_Buf2;     /* synthesized block */
  void* TmpRTBAtFcn3Inport1_d0_SEMAPHORE;/* synthesized block */
  void* TmpRTBAtFcn2Inport1_d0_SEMAPHORE;/* synthesized block */
  void* TmpRTBAtFcn2Inport2_d0_SEMAPHORE;/* synthesized block */
  int_T fw_buf_1;                      /* synthesized block */
  int_T fr_buf_1;                      /* synthesized block */
  int8_T TmpRTBAtFcn3Inport1_LstBufWR; /* synthesized block */
  int8_T TmpRTBAtFcn3Inport1_RDBuf;    /* synthesized block */
  int8_T TmpRTBAtFcn2Inport1_LstBufWR; /* synthesized block */
  int8_T TmpRTBAtFcn2Inport1_RDBuf;    /* synthesized block */
  int8_T TmpRTBAtFcn2Inport2_LstBufWR; /* synthesized block */
  int8_T TmpRTBAtFcn2Inport2_RDBuf;    /* synthesized block */
  boolean_T objisempty;                /* '<Root>/Fcn3' */
  MdlrefDW_slexMulticoreFcn1_T Fcn1_InstanceData;/* '<Root>/Fcn1' */
  MdlrefDW_slexMulticoreFcn2_T Fcn2_InstanceData;/* '<Root>/Fcn2' */
} DW_slexMulticoreExample_T;

/* Real-time Model Data Structure */
struct tag_RTM_slexMulticoreExample_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint32_T TID[3];
      uint32_T cLimit[3];
    } TaskCounters;
  } Timing;
};

/* Block signals (auto storage) */
extern B_slexMulticoreExample_T slexMulticoreExample_B;

/* Block states (auto storage) */
extern DW_slexMulticoreExample_T slexMulticoreExample_DW;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real_T U1;                      /* '<Root>/In1' */
extern real_T U2;                      /* '<Root>/In2' */
extern int8_T TicToc1;                 /* '<Root>/Fcn1' */
extern int8_T TicToc2;                 /* '<Root>/Fcn2' */
extern void slexMulticoreExample_output(int_T tid);
extern void slexMulticoreExample_update(int_T tid);
extern void AdvanceTaskCounters(void);

/* Model entry point functions */
extern void slexMulticoreExample_initialize(void);
extern void slexMulticoreExample_terminate(void);

/* Real-time Model object */
extern RT_MODEL_slexMulticoreExample_T *const slexMulticoreExample_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'slexMulticoreExample'
 */
#endif                                 /* RTW_HEADER_slexMulticoreExample_h_ */
