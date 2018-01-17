/*
 * Code generation for system model 'slexMulticoreFcn1'
 * For more details, see corresponding source file slexMulticoreFcn1.c
 *
 */

#ifndef RTW_HEADER_slexMulticoreFcn1_h_
#define RTW_HEADER_slexMulticoreFcn1_h_
#include <math.h>
#include <string.h>
#ifndef slexMulticoreFcn1_COMMON_INCLUDES_
# define slexMulticoreFcn1_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* slexMulticoreFcn1_COMMON_INCLUDES_ */

#include "slexMulticoreFcn1_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Block signals for model 'slexMulticoreFcn1' */
typedef struct {
  int8_T Gain;                         /* '<Root>/Gain' */
} B_slexMulticoreFcn1_c_T;

/* Block states (auto storage) for model 'slexMulticoreFcn1' */
typedef struct {
  real_T Memory_PreviousInput;         /* '<S1>/Memory' */
  int8_T Delay_DSTATE;                 /* '<Root>/Delay' */
} DW_slexMulticoreFcn1_f_T;

/* Real-time Model Data Structure */
struct tag_RTM_slexMulticoreFcn1_T {
  const char_T **errorStatus;
};

typedef struct {
  B_slexMulticoreFcn1_c_T rtb;
  DW_slexMulticoreFcn1_f_T rtdw;
  RT_MODEL_slexMulticoreFcn1_T rtm;
} MdlrefDW_slexMulticoreFcn1_T;

/* Model reference registration function */
extern void slexMulticoreFcn1_initialize(const char_T **rt_errorStatus,
  RT_MODEL_slexMulticoreFcn1_T *const slexMulticoreFcn1_M,
  B_slexMulticoreFcn1_c_T *localB, DW_slexMulticoreFcn1_f_T *localDW);
extern void slexMulticoreFcn1_Init(DW_slexMulticoreFcn1_f_T *localDW);
extern void slexMulticoreFcn1_Reset(DW_slexMulticoreFcn1_f_T *localDW);
extern void slexMulticoreFcn1_Update(B_slexMulticoreFcn1_c_T *localB,
  DW_slexMulticoreFcn1_f_T *localDW);
extern void slexMulticoreFcn1(const real_T *rtu_U1, const real_T *rtu_U2, int8_T
  *rty_TicToc1, real_T *rty_Adder, B_slexMulticoreFcn1_c_T *localB,
  DW_slexMulticoreFcn1_f_T *localDW);

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
 * '<Root>' : 'slexMulticoreFcn1'
 * '<S1>'   : 'slexMulticoreFcn1/For Iterator Subsystem'
 */
#endif                                 /* RTW_HEADER_slexMulticoreFcn1_h_ */
