/*
 * qube3_dc_ss_model.c
 *
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 *
 * Code generation for model "qube3_dc_ss_model".
 *
 * Model version              : 15.4
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Wed Nov 26 14:12:59 2025
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "qube3_dc_ss_model.h"
#include "rtwtypes.h"
#include "qube3_dc_ss_model_private.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "qube3_dc_ss_model_dt.h"

const real_T qube3_dc_ss_model_RGND = 0.0;/* real_T ground */

/* Block signals (default storage) */
B_qube3_dc_ss_model_T qube3_dc_ss_model_B;

/* Continuous states */
X_qube3_dc_ss_model_T qube3_dc_ss_model_X;

/* Block states (default storage) */
DW_qube3_dc_ss_model_T qube3_dc_ss_model_DW;

/* Real-time model */
static RT_MODEL_qube3_dc_ss_model_T qube3_dc_ss_model_M_;
RT_MODEL_qube3_dc_ss_model_T *const qube3_dc_ss_model_M = &qube3_dc_ss_model_M_;

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  qube3_dc_ss_model_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void qube3_dc_ss_model_output(void)
{
  /* local block i/o variables */
  real_T rtb_motorcurrent;
  real_T rtb_encoder;
  real_T rtb_HILReadTimebase_o3;
  boolean_T rtb_HILReadTimebase_o4;
  real_T rtb_HILReadTimebase_o5;
  real_T tmp;
  real_T tmp_0;
  if (rtmIsMajorTimeStep(qube3_dc_ss_model_M)) {
    /* set solver stop time */
    if (!(qube3_dc_ss_model_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&qube3_dc_ss_model_M->solverInfo,
                            ((qube3_dc_ss_model_M->Timing.clockTickH0 + 1) *
        qube3_dc_ss_model_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&qube3_dc_ss_model_M->solverInfo,
                            ((qube3_dc_ss_model_M->Timing.clockTick0 + 1) *
        qube3_dc_ss_model_M->Timing.stepSize0 +
        qube3_dc_ss_model_M->Timing.clockTickH0 *
        qube3_dc_ss_model_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(qube3_dc_ss_model_M)) {
    qube3_dc_ss_model_M->Timing.t[0] = rtsiGetT(&qube3_dc_ss_model_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(qube3_dc_ss_model_M)) {
    /* S-Function (hil_read_timebase_block): '<S1>/HIL Read Timebase' */

    /* S-Function Block: qube3_dc_ss_model/Qube-Servo - IO (QAL)/HIL Read Timebase (hil_read_timebase_block) */
    {
      t_error result;
      result = hil_task_read(qube3_dc_ss_model_DW.HILReadTimebase_Task, 1,
        &qube3_dc_ss_model_DW.HILReadTimebase_AnalogBuffer,
        &qube3_dc_ss_model_DW.HILReadTimebase_EncoderBuffer[0],
        &qube3_dc_ss_model_DW.HILReadTimebase_DigitalBuffer,
        &qube3_dc_ss_model_DW.HILReadTimebase_OtherBuffer
        );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(qube3_dc_ss_model_M, _rt_error_message);
      } else {
        rtb_motorcurrent = qube3_dc_ss_model_DW.HILReadTimebase_AnalogBuffer;
        rtb_encoder = qube3_dc_ss_model_DW.HILReadTimebase_EncoderBuffer[0];
        rtb_HILReadTimebase_o3 =
          qube3_dc_ss_model_DW.HILReadTimebase_EncoderBuffer[1];
        rtb_HILReadTimebase_o4 =
          qube3_dc_ss_model_DW.HILReadTimebase_DigitalBuffer;
        rtb_HILReadTimebase_o5 =
          qube3_dc_ss_model_DW.HILReadTimebase_OtherBuffer;
      }
    }
  }

  /* Step: '<Root>/Step' incorporates:
   *  Step: '<Root>/Step1'
   */
  tmp_0 = qube3_dc_ss_model_M->Timing.t[0];
  if (tmp_0 < qube3_dc_ss_model_P.Step_Time) {
    tmp = qube3_dc_ss_model_P.Step_Y0;
  } else {
    tmp = qube3_dc_ss_model_P.Step_YFinal;
  }

  /* Step: '<Root>/Step1' */
  if (tmp_0 < qube3_dc_ss_model_P.Step1_Time) {
    tmp_0 = qube3_dc_ss_model_P.Step1_Y0;
  } else {
    tmp_0 = qube3_dc_ss_model_P.Step1_YFinal;
  }

  /* Sum: '<Root>/Sum' incorporates:
   *  Gain: '<Root>/Gain'
   *  Step: '<Root>/Step'
   *  Step: '<Root>/Step1'
   */
  qube3_dc_ss_model_B.Sum = qube3_dc_ss_model_P.Gain_Gain * tmp_0 + tmp;
  if (rtmIsMajorTimeStep(qube3_dc_ss_model_M)) {
    /* S-Function (hil_write_block): '<S1>/HIL Write' */

    /* S-Function Block: qube3_dc_ss_model/Qube-Servo - IO (QAL)/HIL Write (hil_write_block) */
    {
      t_error result;
      result = hil_write(qube3_dc_ss_model_DW.HILInitialize_Card,
                         &qube3_dc_ss_model_P.HILWrite_analog_channels, 1U,
                         NULL, 0U,
                         NULL, 0U,
                         &qube3_dc_ss_model_P.HILWrite_other_channels, 1U,
                         &qube3_dc_ss_model_B.Sum,
                         NULL,
                         NULL,
                         ((const real_T*) &qube3_dc_ss_model_RGND)
                         );
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(qube3_dc_ss_model_M, _rt_error_message);
      }
    }

    /* Gain: '<Root>/counts//s to rad//s' */
    qube3_dc_ss_model_B.omegarads = qube3_dc_ss_model_P.countsstorads_Gain *
      rtb_HILReadTimebase_o5;
  }

  /* StateSpace: '<Root>/State-Space1' */
  qube3_dc_ss_model_B.StateSpace1[0] = qube3_dc_ss_model_P.C1[0] *
    qube3_dc_ss_model_X.StateSpace1_CSTATE[0] +
    qube3_dc_ss_model_X.StateSpace1_CSTATE[1] * qube3_dc_ss_model_P.C1[2];
  qube3_dc_ss_model_B.StateSpace1[1] = qube3_dc_ss_model_X.StateSpace1_CSTATE[0]
    * qube3_dc_ss_model_P.C1[1] + qube3_dc_ss_model_X.StateSpace1_CSTATE[1] *
    qube3_dc_ss_model_P.C1[3];
  if (rtmIsMajorTimeStep(qube3_dc_ss_model_M)) {
  }
}

/* Model update function */
void qube3_dc_ss_model_update(void)
{
  if (rtmIsMajorTimeStep(qube3_dc_ss_model_M)) {
    rt_ertODEUpdateContinuousStates(&qube3_dc_ss_model_M->solverInfo);
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
  if (!(++qube3_dc_ss_model_M->Timing.clockTick0)) {
    ++qube3_dc_ss_model_M->Timing.clockTickH0;
  }

  qube3_dc_ss_model_M->Timing.t[0] = rtsiGetSolverStopTime
    (&qube3_dc_ss_model_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.002s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++qube3_dc_ss_model_M->Timing.clockTick1)) {
      ++qube3_dc_ss_model_M->Timing.clockTickH1;
    }

    qube3_dc_ss_model_M->Timing.t[1] = qube3_dc_ss_model_M->Timing.clockTick1 *
      qube3_dc_ss_model_M->Timing.stepSize1 +
      qube3_dc_ss_model_M->Timing.clockTickH1 *
      qube3_dc_ss_model_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void qube3_dc_ss_model_derivatives(void)
{
  XDot_qube3_dc_ss_model_T *_rtXdot;
  _rtXdot = ((XDot_qube3_dc_ss_model_T *) qube3_dc_ss_model_M->derivs);

  /* Derivatives for StateSpace: '<Root>/State-Space1' */
  _rtXdot->StateSpace1_CSTATE[0] = (qube3_dc_ss_model_P.A1[0] *
    qube3_dc_ss_model_X.StateSpace1_CSTATE[0] +
    qube3_dc_ss_model_X.StateSpace1_CSTATE[1] * qube3_dc_ss_model_P.A1[2]) +
    qube3_dc_ss_model_P.B1[0] * qube3_dc_ss_model_B.Sum;
  _rtXdot->StateSpace1_CSTATE[1] = (qube3_dc_ss_model_X.StateSpace1_CSTATE[0] *
    qube3_dc_ss_model_P.A1[1] + qube3_dc_ss_model_X.StateSpace1_CSTATE[1] *
    qube3_dc_ss_model_P.A1[3]) + qube3_dc_ss_model_P.B1[1] *
    qube3_dc_ss_model_B.Sum;
}

/* Model initialize function */
void qube3_dc_ss_model_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<S1>/HIL Initialize' */

  /* S-Function Block: qube3_dc_ss_model/Qube-Servo - IO (QAL)/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qube_servo3_usb", "0@tcpip://localhost:18922",
                      &qube3_dc_ss_model_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(qube3_dc_ss_model_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (qube3_dc_ss_model_DW.HILInitialize_Card,
       "deadband_compensation=0.3;pwm_en=0;enc0_velocity=3.0;enc1_velocity=3.0;min_diode_compensation=0.3;max_diode_compensation=1.5",
       125);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(qube3_dc_ss_model_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(qube3_dc_ss_model_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(qube3_dc_ss_model_M, _rt_error_message);
      return;
    }

    if ((qube3_dc_ss_model_P.HILInitialize_AIPStart && !is_switching) ||
        (qube3_dc_ss_model_P.HILInitialize_AIPEnter && is_switching)) {
      result = hil_set_analog_input_ranges
        (qube3_dc_ss_model_DW.HILInitialize_Card,
         &qube3_dc_ss_model_P.HILInitialize_AIChannels, 1U,
         &qube3_dc_ss_model_P.HILInitialize_AILow,
         &qube3_dc_ss_model_P.HILInitialize_AIHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(qube3_dc_ss_model_M, _rt_error_message);
        return;
      }
    }

    if ((qube3_dc_ss_model_P.HILInitialize_AOPStart && !is_switching) ||
        (qube3_dc_ss_model_P.HILInitialize_AOPEnter && is_switching)) {
      result = hil_set_analog_output_ranges
        (qube3_dc_ss_model_DW.HILInitialize_Card,
         &qube3_dc_ss_model_P.HILInitialize_AOChannels, 1U,
         &qube3_dc_ss_model_P.HILInitialize_AOLow,
         &qube3_dc_ss_model_P.HILInitialize_AOHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(qube3_dc_ss_model_M, _rt_error_message);
        return;
      }
    }

    if ((qube3_dc_ss_model_P.HILInitialize_AOStart && !is_switching) ||
        (qube3_dc_ss_model_P.HILInitialize_AOEnter && is_switching)) {
      result = hil_write_analog(qube3_dc_ss_model_DW.HILInitialize_Card,
        &qube3_dc_ss_model_P.HILInitialize_AOChannels, 1U,
        &qube3_dc_ss_model_P.HILInitialize_AOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(qube3_dc_ss_model_M, _rt_error_message);
        return;
      }
    }

    if (qube3_dc_ss_model_P.HILInitialize_AOReset) {
      result = hil_watchdog_set_analog_expiration_state
        (qube3_dc_ss_model_DW.HILInitialize_Card,
         &qube3_dc_ss_model_P.HILInitialize_AOChannels, 1U,
         &qube3_dc_ss_model_P.HILInitialize_AOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(qube3_dc_ss_model_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions(qube3_dc_ss_model_DW.HILInitialize_Card,
      NULL, 0U, &qube3_dc_ss_model_P.HILInitialize_DOChannels, 1U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(qube3_dc_ss_model_M, _rt_error_message);
      return;
    }

    if ((qube3_dc_ss_model_P.HILInitialize_DOStart && !is_switching) ||
        (qube3_dc_ss_model_P.HILInitialize_DOEnter && is_switching)) {
      result = hil_write_digital(qube3_dc_ss_model_DW.HILInitialize_Card,
        &qube3_dc_ss_model_P.HILInitialize_DOChannels, 1U, (t_boolean *)
        &qube3_dc_ss_model_P.HILInitialize_DOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(qube3_dc_ss_model_M, _rt_error_message);
        return;
      }
    }

    if (qube3_dc_ss_model_P.HILInitialize_DOReset) {
      result = hil_watchdog_set_digital_expiration_state
        (qube3_dc_ss_model_DW.HILInitialize_Card,
         &qube3_dc_ss_model_P.HILInitialize_DOChannels, 1U, (const
          t_digital_state *) &qube3_dc_ss_model_P.HILInitialize_DOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(qube3_dc_ss_model_M, _rt_error_message);
        return;
      }
    }

    if ((qube3_dc_ss_model_P.HILInitialize_EIPStart && !is_switching) ||
        (qube3_dc_ss_model_P.HILInitialize_EIPEnter && is_switching)) {
      qube3_dc_ss_model_DW.HILInitialize_QuadratureModes[0] =
        qube3_dc_ss_model_P.HILInitialize_EIQuadrature;
      qube3_dc_ss_model_DW.HILInitialize_QuadratureModes[1] =
        qube3_dc_ss_model_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode
        (qube3_dc_ss_model_DW.HILInitialize_Card,
         qube3_dc_ss_model_P.HILInitialize_EIChannels, 2U,
         (t_encoder_quadrature_mode *)
         &qube3_dc_ss_model_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(qube3_dc_ss_model_M, _rt_error_message);
        return;
      }
    }

    if ((qube3_dc_ss_model_P.HILInitialize_EIStart && !is_switching) ||
        (qube3_dc_ss_model_P.HILInitialize_EIEnter && is_switching)) {
      qube3_dc_ss_model_DW.HILInitialize_InitialEICounts[0] =
        qube3_dc_ss_model_P.HILInitialize_EIInitial;
      qube3_dc_ss_model_DW.HILInitialize_InitialEICounts[1] =
        qube3_dc_ss_model_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(qube3_dc_ss_model_DW.HILInitialize_Card,
        qube3_dc_ss_model_P.HILInitialize_EIChannels, 2U,
        &qube3_dc_ss_model_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(qube3_dc_ss_model_M, _rt_error_message);
        return;
      }
    }

    if ((qube3_dc_ss_model_P.HILInitialize_OOStart && !is_switching) ||
        (qube3_dc_ss_model_P.HILInitialize_OOEnter && is_switching)) {
      result = hil_write_other(qube3_dc_ss_model_DW.HILInitialize_Card,
        qube3_dc_ss_model_P.HILInitialize_OOChannels, 3U,
        qube3_dc_ss_model_P.HILInitialize_OOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(qube3_dc_ss_model_M, _rt_error_message);
        return;
      }
    }

    if (qube3_dc_ss_model_P.HILInitialize_OOReset) {
      result = hil_watchdog_set_other_expiration_state
        (qube3_dc_ss_model_DW.HILInitialize_Card,
         qube3_dc_ss_model_P.HILInitialize_OOChannels, 3U,
         qube3_dc_ss_model_P.HILInitialize_OOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(qube3_dc_ss_model_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_timebase_block): '<S1>/HIL Read Timebase' */

  /* S-Function Block: qube3_dc_ss_model/Qube-Servo - IO (QAL)/HIL Read Timebase (hil_read_timebase_block) */
  {
    t_error result;
    result = hil_task_create_reader(qube3_dc_ss_model_DW.HILInitialize_Card,
      qube3_dc_ss_model_P.HILReadTimebase_SamplesInBuffer,
      &qube3_dc_ss_model_P.HILReadTimebase_AnalogChannels, 1U,
      qube3_dc_ss_model_P.HILReadTimebase_EncoderChannels, 2U,
      &qube3_dc_ss_model_P.HILReadTimebase_DigitalChannels, 1U,
      &qube3_dc_ss_model_P.HILReadTimebase_OtherChannels, 1U,
      &qube3_dc_ss_model_DW.HILReadTimebase_Task);
    if (result >= 0) {
      result = hil_task_set_buffer_overflow_mode
        (qube3_dc_ss_model_DW.HILReadTimebase_Task, (t_buffer_overflow_mode)
         (qube3_dc_ss_model_P.HILReadTimebase_OverflowMode - 1));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(qube3_dc_ss_model_M, _rt_error_message);
    }
  }

  /* InitializeConditions for StateSpace: '<Root>/State-Space1' */
  qube3_dc_ss_model_X.StateSpace1_CSTATE[0] =
    qube3_dc_ss_model_P.StateSpace1_InitialCondition;
  qube3_dc_ss_model_X.StateSpace1_CSTATE[1] =
    qube3_dc_ss_model_P.StateSpace1_InitialCondition;
}

/* Model terminate function */
void qube3_dc_ss_model_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S1>/HIL Initialize' */

  /* S-Function Block: qube3_dc_ss_model/Qube-Servo - IO (QAL)/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(qube3_dc_ss_model_DW.HILInitialize_Card);
    hil_monitor_stop_all(qube3_dc_ss_model_DW.HILInitialize_Card);
    is_switching = false;
    if ((qube3_dc_ss_model_P.HILInitialize_AOTerminate && !is_switching) ||
        (qube3_dc_ss_model_P.HILInitialize_AOExit && is_switching)) {
      num_final_analog_outputs = 1U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((qube3_dc_ss_model_P.HILInitialize_DOTerminate && !is_switching) ||
        (qube3_dc_ss_model_P.HILInitialize_DOExit && is_switching)) {
      num_final_digital_outputs = 1U;
    } else {
      num_final_digital_outputs = 0;
    }

    if ((qube3_dc_ss_model_P.HILInitialize_OOTerminate && !is_switching) ||
        (qube3_dc_ss_model_P.HILInitialize_OOExit && is_switching)) {
      num_final_other_outputs = 3U;
    } else {
      num_final_other_outputs = 0;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_digital_outputs > 0
        || num_final_other_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(qube3_dc_ss_model_DW.HILInitialize_Card
                         , &qube3_dc_ss_model_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , NULL, 0
                         , &qube3_dc_ss_model_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         , qube3_dc_ss_model_P.HILInitialize_OOChannels,
                         num_final_other_outputs
                         , &qube3_dc_ss_model_P.HILInitialize_AOFinal
                         , NULL
                         , (t_boolean *)
                         &qube3_dc_ss_model_P.HILInitialize_DOFinal
                         , qube3_dc_ss_model_P.HILInitialize_OOFinal
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog
            (qube3_dc_ss_model_DW.HILInitialize_Card,
             &qube3_dc_ss_model_P.HILInitialize_AOChannels,
             num_final_analog_outputs,
             &qube3_dc_ss_model_P.HILInitialize_AOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital
            (qube3_dc_ss_model_DW.HILInitialize_Card,
             &qube3_dc_ss_model_P.HILInitialize_DOChannels,
             num_final_digital_outputs, (t_boolean *)
             &qube3_dc_ss_model_P.HILInitialize_DOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other(qube3_dc_ss_model_DW.HILInitialize_Card,
            qube3_dc_ss_model_P.HILInitialize_OOChannels,
            num_final_other_outputs, qube3_dc_ss_model_P.HILInitialize_OOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(qube3_dc_ss_model_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(qube3_dc_ss_model_DW.HILInitialize_Card);
    hil_monitor_delete_all(qube3_dc_ss_model_DW.HILInitialize_Card);
    hil_close(qube3_dc_ss_model_DW.HILInitialize_Card);
    qube3_dc_ss_model_DW.HILInitialize_Card = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  qube3_dc_ss_model_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  qube3_dc_ss_model_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  qube3_dc_ss_model_initialize();
}

void MdlTerminate(void)
{
  qube3_dc_ss_model_terminate();
}

/* Registration function */
RT_MODEL_qube3_dc_ss_model_T *qube3_dc_ss_model(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)qube3_dc_ss_model_M, 0,
                sizeof(RT_MODEL_qube3_dc_ss_model_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&qube3_dc_ss_model_M->solverInfo,
                          &qube3_dc_ss_model_M->Timing.simTimeStep);
    rtsiSetTPtr(&qube3_dc_ss_model_M->solverInfo, &rtmGetTPtr
                (qube3_dc_ss_model_M));
    rtsiSetStepSizePtr(&qube3_dc_ss_model_M->solverInfo,
                       &qube3_dc_ss_model_M->Timing.stepSize0);
    rtsiSetdXPtr(&qube3_dc_ss_model_M->solverInfo, &qube3_dc_ss_model_M->derivs);
    rtsiSetContStatesPtr(&qube3_dc_ss_model_M->solverInfo, (real_T **)
                         &qube3_dc_ss_model_M->contStates);
    rtsiSetNumContStatesPtr(&qube3_dc_ss_model_M->solverInfo,
      &qube3_dc_ss_model_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&qube3_dc_ss_model_M->solverInfo,
      &qube3_dc_ss_model_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&qube3_dc_ss_model_M->solverInfo,
      &qube3_dc_ss_model_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&qube3_dc_ss_model_M->solverInfo,
      &qube3_dc_ss_model_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&qube3_dc_ss_model_M->solverInfo, (&rtmGetErrorStatus
      (qube3_dc_ss_model_M)));
    rtsiSetRTModelPtr(&qube3_dc_ss_model_M->solverInfo, qube3_dc_ss_model_M);
  }

  rtsiSetSimTimeStep(&qube3_dc_ss_model_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&qube3_dc_ss_model_M->solverInfo, false);
  qube3_dc_ss_model_M->intgData.f[0] = qube3_dc_ss_model_M->odeF[0];
  qube3_dc_ss_model_M->contStates = ((real_T *) &qube3_dc_ss_model_X);
  rtsiSetSolverData(&qube3_dc_ss_model_M->solverInfo, (void *)
                    &qube3_dc_ss_model_M->intgData);
  rtsiSetSolverName(&qube3_dc_ss_model_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = qube3_dc_ss_model_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "qube3_dc_ss_model_M points to
       static memory which is guaranteed to be non-NULL" */
    qube3_dc_ss_model_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    qube3_dc_ss_model_M->Timing.sampleTimes =
      (&qube3_dc_ss_model_M->Timing.sampleTimesArray[0]);
    qube3_dc_ss_model_M->Timing.offsetTimes =
      (&qube3_dc_ss_model_M->Timing.offsetTimesArray[0]);

    /* task periods */
    qube3_dc_ss_model_M->Timing.sampleTimes[0] = (0.0);
    qube3_dc_ss_model_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    qube3_dc_ss_model_M->Timing.offsetTimes[0] = (0.0);
    qube3_dc_ss_model_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(qube3_dc_ss_model_M, &qube3_dc_ss_model_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = qube3_dc_ss_model_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    qube3_dc_ss_model_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(qube3_dc_ss_model_M, 10.0);
  qube3_dc_ss_model_M->Timing.stepSize0 = 0.002;
  qube3_dc_ss_model_M->Timing.stepSize1 = 0.002;

  /* External mode info */
  qube3_dc_ss_model_M->Sizes.checksums[0] = (4151559588U);
  qube3_dc_ss_model_M->Sizes.checksums[1] = (911755183U);
  qube3_dc_ss_model_M->Sizes.checksums[2] = (67412708U);
  qube3_dc_ss_model_M->Sizes.checksums[3] = (303936518U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    qube3_dc_ss_model_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(qube3_dc_ss_model_M->extModeInfo,
      &qube3_dc_ss_model_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(qube3_dc_ss_model_M->extModeInfo,
                        qube3_dc_ss_model_M->Sizes.checksums);
    rteiSetTPtr(qube3_dc_ss_model_M->extModeInfo, rtmGetTPtr(qube3_dc_ss_model_M));
  }

  qube3_dc_ss_model_M->solverInfoPtr = (&qube3_dc_ss_model_M->solverInfo);
  qube3_dc_ss_model_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&qube3_dc_ss_model_M->solverInfo, 0.002);
  rtsiSetSolverMode(&qube3_dc_ss_model_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  qube3_dc_ss_model_M->blockIO = ((void *) &qube3_dc_ss_model_B);
  (void) memset(((void *) &qube3_dc_ss_model_B), 0,
                sizeof(B_qube3_dc_ss_model_T));

  /* parameters */
  qube3_dc_ss_model_M->defaultParam = ((real_T *)&qube3_dc_ss_model_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &qube3_dc_ss_model_X;
    qube3_dc_ss_model_M->contStates = (x);
    (void) memset((void *)&qube3_dc_ss_model_X, 0,
                  sizeof(X_qube3_dc_ss_model_T));
  }

  /* states (dwork) */
  qube3_dc_ss_model_M->dwork = ((void *) &qube3_dc_ss_model_DW);
  (void) memset((void *)&qube3_dc_ss_model_DW, 0,
                sizeof(DW_qube3_dc_ss_model_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    qube3_dc_ss_model_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 22;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  qube3_dc_ss_model_M->Sizes.numContStates = (2);/* Number of continuous states */
  qube3_dc_ss_model_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  qube3_dc_ss_model_M->Sizes.numY = (0);/* Number of model outputs */
  qube3_dc_ss_model_M->Sizes.numU = (0);/* Number of model inputs */
  qube3_dc_ss_model_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  qube3_dc_ss_model_M->Sizes.numSampTimes = (2);/* Number of sample times */
  qube3_dc_ss_model_M->Sizes.numBlocks = (11);/* Number of blocks */
  qube3_dc_ss_model_M->Sizes.numBlockIO = (3);/* Number of block outputs */
  qube3_dc_ss_model_M->Sizes.numBlockPrms = (107);/* Sum of parameter "widths" */
  return qube3_dc_ss_model_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
