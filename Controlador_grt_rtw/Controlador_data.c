/*
 * Controlador_data.c
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

/* Block parameters (default storage) */
P_Controlador_T Controlador_P = {
  /* Mask Parameter: DiscretePIDController_InitialCo
   * Referenced by: '<S34>/Filter'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController_Initial_j
   * Referenced by: '<S39>/Integrator'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController_LowerSatu
   * Referenced by:
   *   '<S46>/Saturation'
   *   '<S31>/DeadZone'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController_N
   * Referenced by: '<S42>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: DiscretePIDController_UpperSatu
   * Referenced by:
   *   '<S46>/Saturation'
   *   '<S31>/DeadZone'
   */
  1.0,

  /* Mask Parameter: Controlador_kd_mask
   * Referenced by: '<S32>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: Controlador_ki_mask
   * Referenced by: '<S36>/Integral Gain'
   */
  0.005,

  /* Mask Parameter: Controlador_kp_mask
   * Referenced by: '<S44>/Proportional Gain'
   */
  0.001,

  /* Expression: 0
   * Referenced by: '<S29>/Constant1'
   */
  0.0,

  /* Expression: [num]
   * Referenced by: '<S1>/Discrete Transfer Fcn'
   */
  0.01961,

  /* Expression: [den1 den2]
   * Referenced by: '<S1>/Discrete Transfer Fcn'
   */
  { 1.0, -0.9804 },

  /* Expression: 0
   * Referenced by: '<S1>/Discrete Transfer Fcn'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S29>/Clamping_zero'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S39>/Integrator'
   */
  0.01,

  /* Computed Parameter: Filter_gainval
   * Referenced by: '<S34>/Filter'
   */
  0.01,

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S29>/Constant'
   */
  1,

  /* Computed Parameter: Constant2_Value
   * Referenced by: '<S29>/Constant2'
   */
  -1,

  /* Computed Parameter: Constant3_Value
   * Referenced by: '<S29>/Constant3'
   */
  1,

  /* Computed Parameter: Constant4_Value
   * Referenced by: '<S29>/Constant4'
   */
  -1
};
