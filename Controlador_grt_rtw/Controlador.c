/*
 * Controlador.c
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

#include "Controlador.h"
#include "rtwtypes.h"
#include <string.h>
#include "Controlador_private.h"

/* Block states (default storage) */
DW_Controlador_T Controlador_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Controlador_T Controlador_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Controlador_T Controlador_Y;

/* Real-time model */
static RT_MODEL_Controlador_T Controlador_M_;
RT_MODEL_Controlador_T *const Controlador_M = &Controlador_M_;

/* Model step function */
void Controlador_step(void)
{
  real_T rtb_DeadZone;
  real_T rtb_FilterCoefficient;
  real_T rtb_IntegralGain;
  real_T rtb_Sum;
  int8_T tmp;
  int8_T tmp_0;

  /* Outport: '<Root>/Señal de control' incorporates:
   *  DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn'
   */
  Controlador_Y.Sealdecontrol = Controlador_P.DiscreteTransferFcn_NumCoef *
    Controlador_DW.DiscreteTransferFcn_states;

  /* Sum: '<S1>/Sum' incorporates:
   *  Inport: '<Root>/Thrust set point (N)'
   *  Inport: '<Root>/Thust medido (N)'
   */
  rtb_IntegralGain = Controlador_U.ThrustsetpointN - Controlador_U.ThrustmedidoN;

  /* Gain: '<S42>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S34>/Filter'
   *  Gain: '<S32>/Derivative Gain'
   *  Sum: '<S34>/SumD'
   */
  rtb_FilterCoefficient = (Controlador_P.Controlador_kd_mask * rtb_IntegralGain
    - Controlador_DW.Filter_DSTATE) * Controlador_P.DiscretePIDController_N;

  /* Sum: '<S48>/Sum' incorporates:
   *  DiscreteIntegrator: '<S39>/Integrator'
   *  Gain: '<S44>/Proportional Gain'
   */
  rtb_Sum = (Controlador_P.Controlador_kp_mask * rtb_IntegralGain +
             Controlador_DW.Integrator_DSTATE) + rtb_FilterCoefficient;

  /* DeadZone: '<S31>/DeadZone' incorporates:
   *  Saturate: '<S46>/Saturation'
   */
  if (rtb_Sum > Controlador_P.DiscretePIDController_UpperSatu) {
    rtb_DeadZone = rtb_Sum - Controlador_P.DiscretePIDController_UpperSatu;
    rtb_Sum = Controlador_P.DiscretePIDController_UpperSatu;
  } else {
    if (rtb_Sum >= Controlador_P.DiscretePIDController_LowerSatu) {
      rtb_DeadZone = 0.0;
    } else {
      rtb_DeadZone = rtb_Sum - Controlador_P.DiscretePIDController_LowerSatu;
    }

    if (rtb_Sum < Controlador_P.DiscretePIDController_LowerSatu) {
      rtb_Sum = Controlador_P.DiscretePIDController_LowerSatu;
    }
  }

  /* End of DeadZone: '<S31>/DeadZone' */

  /* Gain: '<S36>/Integral Gain' */
  rtb_IntegralGain *= Controlador_P.Controlador_ki_mask;

  /* Update for DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn' incorporates:
   *  Saturate: '<S46>/Saturation'
   */
  Controlador_DW.DiscreteTransferFcn_states = (rtb_Sum -
    Controlador_P.DiscreteTransferFcn_DenCoef[1] *
    Controlador_DW.DiscreteTransferFcn_states) /
    Controlador_P.DiscreteTransferFcn_DenCoef[0];

  /* Switch: '<S29>/Switch1' incorporates:
   *  Constant: '<S29>/Clamping_zero'
   *  Constant: '<S29>/Constant'
   *  Constant: '<S29>/Constant2'
   *  RelationalOperator: '<S29>/fix for DT propagation issue'
   */
  if (rtb_DeadZone > Controlador_P.Clamping_zero_Value) {
    tmp = Controlador_P.Constant_Value;
  } else {
    tmp = Controlador_P.Constant2_Value;
  }

  /* Switch: '<S29>/Switch2' incorporates:
   *  Constant: '<S29>/Clamping_zero'
   *  Constant: '<S29>/Constant3'
   *  Constant: '<S29>/Constant4'
   *  RelationalOperator: '<S29>/fix for DT propagation issue1'
   */
  if (rtb_IntegralGain > Controlador_P.Clamping_zero_Value) {
    tmp_0 = Controlador_P.Constant3_Value;
  } else {
    tmp_0 = Controlador_P.Constant4_Value;
  }

  /* Switch: '<S29>/Switch' incorporates:
   *  Constant: '<S29>/Clamping_zero'
   *  Constant: '<S29>/Constant1'
   *  Logic: '<S29>/AND3'
   *  RelationalOperator: '<S29>/Equal1'
   *  RelationalOperator: '<S29>/Relational Operator'
   *  Switch: '<S29>/Switch1'
   *  Switch: '<S29>/Switch2'
   */
  if ((Controlador_P.Clamping_zero_Value != rtb_DeadZone) && (tmp == tmp_0)) {
    rtb_IntegralGain = Controlador_P.Constant1_Value;
  }

  /* Update for DiscreteIntegrator: '<S39>/Integrator' incorporates:
   *  Switch: '<S29>/Switch'
   */
  Controlador_DW.Integrator_DSTATE += Controlador_P.Integrator_gainval *
    rtb_IntegralGain;

  /* Update for DiscreteIntegrator: '<S34>/Filter' */
  Controlador_DW.Filter_DSTATE += Controlador_P.Filter_gainval *
    rtb_FilterCoefficient;

  /* Matfile logging */
  rt_UpdateTXYLogVars(Controlador_M->rtwLogInfo,
                      (&Controlador_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.01s, 0.0s] */
    if ((rtmGetTFinal(Controlador_M)!=-1) &&
        !((rtmGetTFinal(Controlador_M)-Controlador_M->Timing.taskTime0) >
          Controlador_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Controlador_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Controlador_M->Timing.clockTick0)) {
    ++Controlador_M->Timing.clockTickH0;
  }

  Controlador_M->Timing.taskTime0 = Controlador_M->Timing.clockTick0 *
    Controlador_M->Timing.stepSize0 + Controlador_M->Timing.clockTickH0 *
    Controlador_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Controlador_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Controlador_M, 0,
                sizeof(RT_MODEL_Controlador_T));
  rtmSetTFinal(Controlador_M, 10.0);
  Controlador_M->Timing.stepSize0 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    Controlador_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Controlador_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Controlador_M->rtwLogInfo, (NULL));
    rtliSetLogT(Controlador_M->rtwLogInfo, "");
    rtliSetLogX(Controlador_M->rtwLogInfo, "");
    rtliSetLogXFinal(Controlador_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Controlador_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Controlador_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(Controlador_M->rtwLogInfo, 0);
    rtliSetLogDecimation(Controlador_M->rtwLogInfo, 1);
    rtliSetLogY(Controlador_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Controlador_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Controlador_M->rtwLogInfo, (NULL));
  }

  /* states (dwork) */
  (void) memset((void *)&Controlador_DW, 0,
                sizeof(DW_Controlador_T));

  /* external inputs */
  (void)memset(&Controlador_U, 0, sizeof(ExtU_Controlador_T));

  /* external outputs */
  Controlador_Y.Sealdecontrol = 0.0;

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(Controlador_M->rtwLogInfo, 0.0, rtmGetTFinal
    (Controlador_M), Controlador_M->Timing.stepSize0, (&rtmGetErrorStatus
    (Controlador_M)));

  /* InitializeConditions for DiscreteTransferFcn: '<S1>/Discrete Transfer Fcn' */
  Controlador_DW.DiscreteTransferFcn_states =
    Controlador_P.DiscreteTransferFcn_InitialStat;

  /* InitializeConditions for DiscreteIntegrator: '<S39>/Integrator' */
  Controlador_DW.Integrator_DSTATE =
    Controlador_P.DiscretePIDController_Initial_j;

  /* InitializeConditions for DiscreteIntegrator: '<S34>/Filter' */
  Controlador_DW.Filter_DSTATE = Controlador_P.DiscretePIDController_InitialCo;
}

/* Model terminate function */
void Controlador_terminate(void)
{
  /* (no terminate code required) */
}
