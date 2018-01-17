/*
 * Code generation for system model 'slexMulticoreFcn2'
 * For more details, see corresponding source file slexMulticoreFcn2.c
 *
 */

#ifndef RTW_HEADER_slexMulticoreFcn2_h_
#define RTW_HEADER_slexMulticoreFcn2_h_
#include <math.h>
#include <string.h>
#ifndef slexMulticoreFcn2_COMMON_INCLUDES_
# define slexMulticoreFcn2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* slexMulticoreFcn2_COMMON_INCLUDES_ */

#include "slexMulticoreFcn2_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Block signals for model 'slexMulticoreFcn2' */
typedef struct {
  int8_T Gain;                         /* '<Root>/Gain' */
} B_slexMulticoreFcn2_c_T;

/* Block states (auto storage) for model 'slexMulticoreFcn2' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<Root>/Unit Delay' */
  real_T Memory_PreviousInput;         /* '<S1>/Memory' */
  int8_T Delay_DSTATE;                 /* '<Root>/Delay' */
} DW_slexMulticoreFcn2_f_T;

/* Real-time Model Data Structure */
struct tag_RTM_slexMulticoreFcn2_T {
  const char_T **errorStatus;
};

typedef struct {
  B_slexMulticoreFcn2_c_T rtb;
  DW_slexMulticoreFcn2_f_T rtdw;
  RT_MODEL_slexMulticoreFcn2_T rtm;
} MdlrefDW_slexMulticoreFcn2_T;

/* Model reference registration function */
extern void slexMulticoreFcn2_initialize(const char_T **rt_errorStatus,
  RT_MODEL_slexMulticoreFcn2_T *const slexMulticoreFcn2_M,
  B_slexMulticoreFcn2_c_T *localB, DW_slexMulticoreFcn2_f_T *localDW);
extern void slexMulticoreFcn2_Init(DW_slexMulticoreFcn2_f_T *localDW);
extern void slexMulticoreFcn2_Reset(DW_slexMulticoreFcn2_f_T *localDW);
extern void slexMulticoreFcn2_UpdateTID0(const real_T *rtu_u1, const real_T
  *rtu_u2, DW_slexMulticoreFcn2_f_T *localDW);
extern void slexMulticoreFcn2_UpdateTID1(B_slexMulticoreFcn2_c_T *localB,
  DW_slexMulticoreFcn2_f_T *localDW);
extern void slexMulticoreFcn2TID0(real_T *rty_Subtracter,
  DW_slexMulticoreFcn2_f_T *localDW);
extern void slexMulticoreFcn2TID1(int8_T *rty_TicToc, B_slexMulticoreFcn2_c_T
  *localB, DW_slexMulticoreFcn2_f_T *localDW);

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
 * '<Root>' : 'slexMulticoreFcn2'
 * '<S1>'   : 'slexMulticoreFcn2/For Iterator Subsystem'
 */
#endif                                 /* RTW_HEADER_slexMulticoreFcn2_h_ */
