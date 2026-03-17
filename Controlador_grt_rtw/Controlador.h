/*
 * Controlador.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Controlador".
 *
 * Model version              : 1.13
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Tue Mar 17 20:26:27 2026
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Controlador_h_
#define Controlador_h_
#ifndef Controlador_COMMON_INCLUDES_
#define Controlador_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "rt_nonfinite.h"
#include "math.h"
#endif                                 /* Controlador_COMMON_INCLUDES_ */

#include "Controlador_types.h"
#include <float.h>
#include <string.h>
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTransferFcn_states;   /* '<S1>/Discrete Transfer Fcn' */
  real_T Integrator_DSTATE;            /* '<S39>/Integrator' */
  real_T Filter_DSTATE;                /* '<S34>/Filter' */
} DW_Controlador_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T ThrustsetpointN;              /* '<Root>/Thrust set point (N)' */
  real_T ThrustmedidoN;                /* '<Root>/Thust medido (N)' */
} ExtU_Controlador_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Sealdecontrol;                /* '<Root>/Se�al de control' */
} ExtY_Controlador_T;

/* Parameters (default storage) */
struct P_Controlador_T_ {
  real_T DiscretePIDController_InitialCo;
                              /* Mask Parameter: DiscretePIDController_InitialCo
                               * Referenced by: '<S34>/Filter'
                               */
  real_T DiscretePIDController_Initial_j;
                              /* Mask Parameter: DiscretePIDController_Initial_j
                               * Referenced by: '<S39>/Integrator'
                               */
  real_T DiscretePIDController_LowerSatu;
                              /* Mask Parameter: DiscretePIDController_LowerSatu
                               * Referenced by:
                               *   '<S46>/Saturation'
                               *   '<S31>/DeadZone'
                               */
  real_T DiscretePIDController_N;     /* Mask Parameter: DiscretePIDController_N
                                       * Referenced by: '<S42>/Filter Coefficient'
                                       */
  real_T DiscretePIDController_UpperSatu;
                              /* Mask Parameter: DiscretePIDController_UpperSatu
                               * Referenced by:
                               *   '<S46>/Saturation'
                               *   '<S31>/DeadZone'
                               */
  real_T Controlador_kd_mask;          /* Mask Parameter: Controlador_kd_mask
                                        * Referenced by: '<S32>/Derivative Gain'
                                        */
  real_T Controlador_ki_mask;          /* Mask Parameter: Controlador_ki_mask
                                        * Referenced by: '<S36>/Integral Gain'
                                        */
  real_T Controlador_kp_mask;          /* Mask Parameter: Controlador_kp_mask
                                        * Referenced by: '<S44>/Proportional Gain'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S29>/Constant1'
                                        */
  real_T DiscreteTransferFcn_NumCoef;  /* Expression: [num]
                                        * Referenced by: '<S1>/Discrete Transfer Fcn'
                                        */
  real_T DiscreteTransferFcn_DenCoef[2];/* Expression: [den1 den2]
                                         * Referenced by: '<S1>/Discrete Transfer Fcn'
                                         */
  real_T DiscreteTransferFcn_InitialStat;/* Expression: 0
                                          * Referenced by: '<S1>/Discrete Transfer Fcn'
                                          */
  real_T Clamping_zero_Value;          /* Expression: 0
                                        * Referenced by: '<S29>/Clamping_zero'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S39>/Integrator'
                                        */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S34>/Filter'
                                        */
  int8_T Constant_Value;               /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S29>/Constant'
                                        */
  int8_T Constant2_Value;              /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<S29>/Constant2'
                                        */
  int8_T Constant3_Value;              /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S29>/Constant3'
                                        */
  int8_T Constant4_Value;              /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S29>/Constant4'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Controlador_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_Controlador_T Controlador_P;

/* Block states (default storage) */
extern DW_Controlador_T Controlador_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Controlador_T Controlador_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Controlador_T Controlador_Y;

/* Model entry point functions */
extern void Controlador_initialize(void);
extern void Controlador_step(void);
extern void Controlador_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Controlador_T *const Controlador_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('Turbine_JAM/Controlador')    - opens subsystem Turbine_JAM/Controlador
 * hilite_system('Turbine_JAM/Controlador/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Turbine_JAM'
 * '<S1>'   : 'Turbine_JAM/Controlador'
 * '<S2>'   : 'Turbine_JAM/Controlador/Discrete PID Controller'
 * '<S3>'   : 'Turbine_JAM/Controlador/Discrete PID Controller/Anti-windup'
 * '<S4>'   : 'Turbine_JAM/Controlador/Discrete PID Controller/D Gain'
 * '<S5>'   : 'Turbine_JAM/Controlador/Discrete PID Controller/External Derivative'
 * '<S6>'   : 'Turbine_JAM/Controlador/Discrete PID Controller/Filter'
 * '<S7>'   : 'Turbine_JAM/Controlador/Discrete PID Controller/Filter ICs'
 * '<S8>'   : 'Turbine_JAM/Controlador/Discrete PID Controller/I Gain'
 * '<S9>'   : 'Turbine_JAM/Controlador/Discrete PID Controller/Ideal P Gain'
 * '<S10>'  : 'Turbine_JAM/Controlador/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S11>'  : 'Turbine_JAM/Controlador/Discrete PID Controller/Integrator'
 * '<S12>'  : 'Turbine_JAM/Controlador/Discrete PID Controller/Integrator ICs'
 * '<S13>'  : 'Turbine_JAM/Controlador/Discrete PID Controller/N Copy'
 * '<S14>'  : 'Turbine_JAM/Controlador/Discrete PID Controller/N Gain'
 * '<S15>'  : 'Turbine_JAM/Controlador/Discrete PID Controller/P Copy'
 * '<S16>'  : 'Turbine_JAM/Controlador/Discrete PID Controller/Parallel P Gain'
 * '<S17>'  : 'Turbine_JAM/Controlador/Discrete PID Controller/Reset Signal'
 * '<S18>'  : 'Turbine_JAM/Controlador/Discrete PID Controller/Saturation'
 * '<S19>'  : 'Turbine_JAM/Controlador/Discrete PID Controller/Saturation Fdbk'
 * '<S20>'  : 'Turbine_JAM/Controlador/Discrete PID Controller/Sum'
 * '<S21>'  : 'Turbine_JAM/Controlador/Discrete PID Controller/Sum Fdbk'
 * '<S22>'  : 'Turbine_JAM/Controlador/Discrete PID Controller/Tracking Mode'
 * '<S23>'  : 'Turbine_JAM/Controlador/Discrete PID Controller/Tracking Mode Sum'
 * '<S24>'  : 'Turbine_JAM/Controlador/Discrete PID Controller/Tsamp - Integral'
 * '<S25>'  : 'Turbine_JAM/Controlador/Discrete PID Controller/Tsamp - Ngain'
 * '<S26>'  : 'Turbine_JAM/Controlador/Discrete PID Controller/postSat Signal'
 * '<S27>'  : 'Turbine_JAM/Controlador/Discrete PID Controller/preInt Signal'
 * '<S28>'  : 'Turbine_JAM/Controlador/Discrete PID Controller/preSat Signal'
 * '<S29>'  : 'Turbine_JAM/Controlador/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S30>'  : 'Turbine_JAM/Controlador/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S31>'  : 'Turbine_JAM/Controlador/Discrete PID Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S32>'  : 'Turbine_JAM/Controlador/Discrete PID Controller/D Gain/Internal Parameters'
 * '<S33>'  : 'Turbine_JAM/Controlador/Discrete PID Controller/External Derivative/Error'
 * '<S34>'  : 'Turbine_JAM/Controlador/Discrete PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S35>'  : 'Turbine_JAM/Controlador/Discrete PID Controller/Filter ICs/Internal IC - Filter'
 * '<S36>'  : 'Turbine_JAM/Controlador/Discrete PID Controller/I Gain/Internal Parameters'
 * '<S37>'  : 'Turbine_JAM/Controlador/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S38>'  : 'Turbine_JAM/Controlador/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S39>'  : 'Turbine_JAM/Controlador/Discrete PID Controller/Integrator/Discrete'
 * '<S40>'  : 'Turbine_JAM/Controlador/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S41>'  : 'Turbine_JAM/Controlador/Discrete PID Controller/N Copy/Disabled'
 * '<S42>'  : 'Turbine_JAM/Controlador/Discrete PID Controller/N Gain/Internal Parameters'
 * '<S43>'  : 'Turbine_JAM/Controlador/Discrete PID Controller/P Copy/Disabled'
 * '<S44>'  : 'Turbine_JAM/Controlador/Discrete PID Controller/Parallel P Gain/Internal Parameters'
 * '<S45>'  : 'Turbine_JAM/Controlador/Discrete PID Controller/Reset Signal/Disabled'
 * '<S46>'  : 'Turbine_JAM/Controlador/Discrete PID Controller/Saturation/Enabled'
 * '<S47>'  : 'Turbine_JAM/Controlador/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S48>'  : 'Turbine_JAM/Controlador/Discrete PID Controller/Sum/Sum_PID'
 * '<S49>'  : 'Turbine_JAM/Controlador/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S50>'  : 'Turbine_JAM/Controlador/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S51>'  : 'Turbine_JAM/Controlador/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S52>'  : 'Turbine_JAM/Controlador/Discrete PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S53>'  : 'Turbine_JAM/Controlador/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S54>'  : 'Turbine_JAM/Controlador/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S55>'  : 'Turbine_JAM/Controlador/Discrete PID Controller/preInt Signal/Internal PreInt'
 * '<S56>'  : 'Turbine_JAM/Controlador/Discrete PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 
