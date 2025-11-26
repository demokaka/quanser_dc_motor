/*
 * qube3_dc_lqr.c
 *
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 *
 * Code generation for model "qube3_dc_lqr".
 *
 * Model version              : 15.1
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Wed Nov 26 14:32:50 2025
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "qube3_dc_lqr.h"
#include "rtwtypes.h"
#include "qube3_dc_lqr_private.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "qube3_dc_lqr_dt.h"

/* Block signals (default storage) */
B_qube3_dc_lqr_T qube3_dc_lqr_B;

/* Block states (default storage) */
DW_qube3_dc_lqr_T qube3_dc_lqr_DW;

/* Real-time model */
static RT_MODEL_qube3_dc_lqr_T qube3_dc_lqr_M_;
RT_MODEL_qube3_dc_lqr_T *const qube3_dc_lqr_M = &qube3_dc_lqr_M_;

/* Model output function */
void qube3_dc_lqr_output(void)
{
  /* local block i/o variables */
  real_T rtb_motorcurrent;
  real_T rtb_HILReadTimebase_o3;
  boolean_T rtb_HILReadTimebase_o4;
  real_T rtb_TmpSignalConversionAtHILWri[3];
  real_T rtb_HILReadTimebase_o5;
  real_T rtb_encoder;

  /* S-Function (hil_read_timebase_block): '<S2>/HIL Read Timebase' */

  /* S-Function Block: qube3_dc_lqr/Qube-Servo - IO (QAL)/HIL Read Timebase (hil_read_timebase_block) */
  {
    t_error result;
    result = hil_task_read(qube3_dc_lqr_DW.HILReadTimebase_Task, 1,
      &qube3_dc_lqr_DW.HILReadTimebase_AnalogBuffer,
      &qube3_dc_lqr_DW.HILReadTimebase_EncoderBuffer[0],
      &qube3_dc_lqr_DW.HILReadTimebase_DigitalBuffer,
      &qube3_dc_lqr_DW.HILReadTimebase_OtherBuffer
      );
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(qube3_dc_lqr_M, _rt_error_message);
    } else {
      rtb_motorcurrent = qube3_dc_lqr_DW.HILReadTimebase_AnalogBuffer;
      rtb_encoder = qube3_dc_lqr_DW.HILReadTimebase_EncoderBuffer[0];
      rtb_HILReadTimebase_o3 = qube3_dc_lqr_DW.HILReadTimebase_EncoderBuffer[1];
      rtb_HILReadTimebase_o4 = qube3_dc_lqr_DW.HILReadTimebase_DigitalBuffer;
      rtb_HILReadTimebase_o5 = qube3_dc_lqr_DW.HILReadTimebase_OtherBuffer;
    }
  }

  /* Gain: '<S1>/Gain1' incorporates:
   *  Constant: '<Root>/theta ref (deg)'
   */
  qube3_dc_lqr_B.Gain1 = qube3_dc_lqr_P.Gain1_Gain *
    qube3_dc_lqr_P.thetarefdeg_Value;

  /* Constant: '<Root>/Constant' */
  qube3_dc_lqr_B.omega_refrads = qube3_dc_lqr_P.Constant_Value;

  /* Gain: '<Root>/counts to rad' */
  qube3_dc_lqr_B.countstorad = qube3_dc_lqr_P.countstorad_Gain * rtb_encoder;

  /* Gain: '<Root>/counts//s to rad//s' */
  qube3_dc_lqr_B.countsstorads = qube3_dc_lqr_P.countsstorads_Gain *
    rtb_HILReadTimebase_o5;

  /* Gain: '<Root>/Gain ' incorporates:
   *  Sum: '<Root>/Sum'
   */
  qube3_dc_lqr_B.Gain = (qube3_dc_lqr_B.Gain1 - qube3_dc_lqr_B.countstorad) *
    qube3_dc_lqr_P.K_lqr[0] + (qube3_dc_lqr_B.omega_refrads -
    qube3_dc_lqr_B.countsstorads) * qube3_dc_lqr_P.K_lqr[1];

  /* SignalConversion generated from: '<S2>/HIL Write' */
  rtb_TmpSignalConversionAtHILWri[0] = 0.0;
  rtb_TmpSignalConversionAtHILWri[1] = 0.0;
  rtb_TmpSignalConversionAtHILWri[2] = 0.0;

  /* S-Function (hil_write_block): '<S2>/HIL Write' */

  /* S-Function Block: qube3_dc_lqr/Qube-Servo - IO (QAL)/HIL Write (hil_write_block) */
  {
    t_error result;
    result = hil_write(qube3_dc_lqr_DW.HILInitialize_Card,
                       &qube3_dc_lqr_P.HILWrite_analog_channels, 1U,
                       NULL, 0U,
                       NULL, 0U,
                       qube3_dc_lqr_P.HILWrite_other_channels, 3U,
                       &qube3_dc_lqr_B.Gain,
                       NULL,
                       NULL,
                       &rtb_TmpSignalConversionAtHILWri[0]
                       );
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(qube3_dc_lqr_M, _rt_error_message);
    }
  }
}

/* Model update function */
void qube3_dc_lqr_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++qube3_dc_lqr_M->Timing.clockTick0)) {
    ++qube3_dc_lqr_M->Timing.clockTickH0;
  }

  qube3_dc_lqr_M->Timing.t[0] = qube3_dc_lqr_M->Timing.clockTick0 *
    qube3_dc_lqr_M->Timing.stepSize0 + qube3_dc_lqr_M->Timing.clockTickH0 *
    qube3_dc_lqr_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void qube3_dc_lqr_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<S2>/HIL Initialize' */

  /* S-Function Block: qube3_dc_lqr/Qube-Servo - IO (QAL)/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qube_servo3_usb", "0@tcpip://localhost:18922",
                      &qube3_dc_lqr_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(qube3_dc_lqr_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(qube3_dc_lqr_DW.HILInitialize_Card,
      "deadband_compensation=0.3;pwm_en=0;enc0_velocity=3.0;enc1_velocity=3.0;min_diode_compensation=0.3;max_diode_compensation=1.5",
      125);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(qube3_dc_lqr_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(qube3_dc_lqr_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(qube3_dc_lqr_M, _rt_error_message);
      return;
    }

    if ((qube3_dc_lqr_P.HILInitialize_AIPStart && !is_switching) ||
        (qube3_dc_lqr_P.HILInitialize_AIPEnter && is_switching)) {
      result = hil_set_analog_input_ranges(qube3_dc_lqr_DW.HILInitialize_Card,
        &qube3_dc_lqr_P.HILInitialize_AIChannels, 1U,
        &qube3_dc_lqr_P.HILInitialize_AILow,
        &qube3_dc_lqr_P.HILInitialize_AIHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(qube3_dc_lqr_M, _rt_error_message);
        return;
      }
    }

    if ((qube3_dc_lqr_P.HILInitialize_AOPStart && !is_switching) ||
        (qube3_dc_lqr_P.HILInitialize_AOPEnter && is_switching)) {
      result = hil_set_analog_output_ranges(qube3_dc_lqr_DW.HILInitialize_Card,
        &qube3_dc_lqr_P.HILInitialize_AOChannels, 1U,
        &qube3_dc_lqr_P.HILInitialize_AOLow,
        &qube3_dc_lqr_P.HILInitialize_AOHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(qube3_dc_lqr_M, _rt_error_message);
        return;
      }
    }

    if ((qube3_dc_lqr_P.HILInitialize_AOStart && !is_switching) ||
        (qube3_dc_lqr_P.HILInitialize_AOEnter && is_switching)) {
      result = hil_write_analog(qube3_dc_lqr_DW.HILInitialize_Card,
        &qube3_dc_lqr_P.HILInitialize_AOChannels, 1U,
        &qube3_dc_lqr_P.HILInitialize_AOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(qube3_dc_lqr_M, _rt_error_message);
        return;
      }
    }

    if (qube3_dc_lqr_P.HILInitialize_AOReset) {
      result = hil_watchdog_set_analog_expiration_state
        (qube3_dc_lqr_DW.HILInitialize_Card,
         &qube3_dc_lqr_P.HILInitialize_AOChannels, 1U,
         &qube3_dc_lqr_P.HILInitialize_AOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(qube3_dc_lqr_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions(qube3_dc_lqr_DW.HILInitialize_Card, NULL,
      0U, &qube3_dc_lqr_P.HILInitialize_DOChannels, 1U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(qube3_dc_lqr_M, _rt_error_message);
      return;
    }

    if ((qube3_dc_lqr_P.HILInitialize_DOStart && !is_switching) ||
        (qube3_dc_lqr_P.HILInitialize_DOEnter && is_switching)) {
      result = hil_write_digital(qube3_dc_lqr_DW.HILInitialize_Card,
        &qube3_dc_lqr_P.HILInitialize_DOChannels, 1U, (t_boolean *)
        &qube3_dc_lqr_P.HILInitialize_DOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(qube3_dc_lqr_M, _rt_error_message);
        return;
      }
    }

    if (qube3_dc_lqr_P.HILInitialize_DOReset) {
      result = hil_watchdog_set_digital_expiration_state
        (qube3_dc_lqr_DW.HILInitialize_Card,
         &qube3_dc_lqr_P.HILInitialize_DOChannels, 1U, (const t_digital_state *)
         &qube3_dc_lqr_P.HILInitialize_DOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(qube3_dc_lqr_M, _rt_error_message);
        return;
      }
    }

    if ((qube3_dc_lqr_P.HILInitialize_EIPStart && !is_switching) ||
        (qube3_dc_lqr_P.HILInitialize_EIPEnter && is_switching)) {
      qube3_dc_lqr_DW.HILInitialize_QuadratureModes[0] =
        qube3_dc_lqr_P.HILInitialize_EIQuadrature;
      qube3_dc_lqr_DW.HILInitialize_QuadratureModes[1] =
        qube3_dc_lqr_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode
        (qube3_dc_lqr_DW.HILInitialize_Card,
         qube3_dc_lqr_P.HILInitialize_EIChannels, 2U, (t_encoder_quadrature_mode
          *) &qube3_dc_lqr_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(qube3_dc_lqr_M, _rt_error_message);
        return;
      }
    }

    if ((qube3_dc_lqr_P.HILInitialize_EIStart && !is_switching) ||
        (qube3_dc_lqr_P.HILInitialize_EIEnter && is_switching)) {
      qube3_dc_lqr_DW.HILInitialize_InitialEICounts[0] =
        qube3_dc_lqr_P.HILInitialize_EIInitial;
      qube3_dc_lqr_DW.HILInitialize_InitialEICounts[1] =
        qube3_dc_lqr_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts(qube3_dc_lqr_DW.HILInitialize_Card,
        qube3_dc_lqr_P.HILInitialize_EIChannels, 2U,
        &qube3_dc_lqr_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(qube3_dc_lqr_M, _rt_error_message);
        return;
      }
    }

    if ((qube3_dc_lqr_P.HILInitialize_OOStart && !is_switching) ||
        (qube3_dc_lqr_P.HILInitialize_OOEnter && is_switching)) {
      result = hil_write_other(qube3_dc_lqr_DW.HILInitialize_Card,
        qube3_dc_lqr_P.HILInitialize_OOChannels, 3U,
        qube3_dc_lqr_P.HILInitialize_OOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(qube3_dc_lqr_M, _rt_error_message);
        return;
      }
    }

    if (qube3_dc_lqr_P.HILInitialize_OOReset) {
      result = hil_watchdog_set_other_expiration_state
        (qube3_dc_lqr_DW.HILInitialize_Card,
         qube3_dc_lqr_P.HILInitialize_OOChannels, 3U,
         qube3_dc_lqr_P.HILInitialize_OOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(qube3_dc_lqr_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_timebase_block): '<S2>/HIL Read Timebase' */

  /* S-Function Block: qube3_dc_lqr/Qube-Servo - IO (QAL)/HIL Read Timebase (hil_read_timebase_block) */
  {
    t_error result;
    result = hil_task_create_reader(qube3_dc_lqr_DW.HILInitialize_Card,
      qube3_dc_lqr_P.HILReadTimebase_SamplesInBuffer,
      &qube3_dc_lqr_P.HILReadTimebase_AnalogChannels, 1U,
      qube3_dc_lqr_P.HILReadTimebase_EncoderChannels, 2U,
      &qube3_dc_lqr_P.HILReadTimebase_DigitalChannels, 1U,
      &qube3_dc_lqr_P.HILReadTimebase_OtherChannels, 1U,
      &qube3_dc_lqr_DW.HILReadTimebase_Task);
    if (result >= 0) {
      result = hil_task_set_buffer_overflow_mode
        (qube3_dc_lqr_DW.HILReadTimebase_Task, (t_buffer_overflow_mode)
         (qube3_dc_lqr_P.HILReadTimebase_OverflowMode - 1));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(qube3_dc_lqr_M, _rt_error_message);
    }
  }
}

/* Model terminate function */
void qube3_dc_lqr_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<S2>/HIL Initialize' */

  /* S-Function Block: qube3_dc_lqr/Qube-Servo - IO (QAL)/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all(qube3_dc_lqr_DW.HILInitialize_Card);
    hil_monitor_stop_all(qube3_dc_lqr_DW.HILInitialize_Card);
    is_switching = false;
    if ((qube3_dc_lqr_P.HILInitialize_AOTerminate && !is_switching) ||
        (qube3_dc_lqr_P.HILInitialize_AOExit && is_switching)) {
      num_final_analog_outputs = 1U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((qube3_dc_lqr_P.HILInitialize_DOTerminate && !is_switching) ||
        (qube3_dc_lqr_P.HILInitialize_DOExit && is_switching)) {
      num_final_digital_outputs = 1U;
    } else {
      num_final_digital_outputs = 0;
    }

    if ((qube3_dc_lqr_P.HILInitialize_OOTerminate && !is_switching) ||
        (qube3_dc_lqr_P.HILInitialize_OOExit && is_switching)) {
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
      result = hil_write(qube3_dc_lqr_DW.HILInitialize_Card
                         , &qube3_dc_lqr_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , NULL, 0
                         , &qube3_dc_lqr_P.HILInitialize_DOChannels,
                         num_final_digital_outputs
                         , qube3_dc_lqr_P.HILInitialize_OOChannels,
                         num_final_other_outputs
                         , &qube3_dc_lqr_P.HILInitialize_AOFinal
                         , NULL
                         , (t_boolean *) &qube3_dc_lqr_P.HILInitialize_DOFinal
                         , qube3_dc_lqr_P.HILInitialize_OOFinal
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(qube3_dc_lqr_DW.HILInitialize_Card,
            &qube3_dc_lqr_P.HILInitialize_AOChannels, num_final_analog_outputs,
            &qube3_dc_lqr_P.HILInitialize_AOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital(qube3_dc_lqr_DW.HILInitialize_Card,
            &qube3_dc_lqr_P.HILInitialize_DOChannels, num_final_digital_outputs,
            (t_boolean *) &qube3_dc_lqr_P.HILInitialize_DOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other(qube3_dc_lqr_DW.HILInitialize_Card,
            qube3_dc_lqr_P.HILInitialize_OOChannels, num_final_other_outputs,
            qube3_dc_lqr_P.HILInitialize_OOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(qube3_dc_lqr_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(qube3_dc_lqr_DW.HILInitialize_Card);
    hil_monitor_delete_all(qube3_dc_lqr_DW.HILInitialize_Card);
    hil_close(qube3_dc_lqr_DW.HILInitialize_Card);
    qube3_dc_lqr_DW.HILInitialize_Card = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  qube3_dc_lqr_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  qube3_dc_lqr_update();
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
  qube3_dc_lqr_initialize();
}

void MdlTerminate(void)
{
  qube3_dc_lqr_terminate();
}

/* Registration function */
RT_MODEL_qube3_dc_lqr_T *qube3_dc_lqr(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)qube3_dc_lqr_M, 0,
                sizeof(RT_MODEL_qube3_dc_lqr_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = qube3_dc_lqr_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "qube3_dc_lqr_M points to
       static memory which is guaranteed to be non-NULL" */
    qube3_dc_lqr_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    qube3_dc_lqr_M->Timing.sampleTimes =
      (&qube3_dc_lqr_M->Timing.sampleTimesArray[0]);
    qube3_dc_lqr_M->Timing.offsetTimes =
      (&qube3_dc_lqr_M->Timing.offsetTimesArray[0]);

    /* task periods */
    qube3_dc_lqr_M->Timing.sampleTimes[0] = (0.02);

    /* task offsets */
    qube3_dc_lqr_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(qube3_dc_lqr_M, &qube3_dc_lqr_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = qube3_dc_lqr_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    qube3_dc_lqr_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(qube3_dc_lqr_M, -1);
  qube3_dc_lqr_M->Timing.stepSize0 = 0.02;

  /* External mode info */
  qube3_dc_lqr_M->Sizes.checksums[0] = (769989840U);
  qube3_dc_lqr_M->Sizes.checksums[1] = (3574898910U);
  qube3_dc_lqr_M->Sizes.checksums[2] = (4036151020U);
  qube3_dc_lqr_M->Sizes.checksums[3] = (979110648U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    qube3_dc_lqr_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(qube3_dc_lqr_M->extModeInfo,
      &qube3_dc_lqr_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(qube3_dc_lqr_M->extModeInfo,
                        qube3_dc_lqr_M->Sizes.checksums);
    rteiSetTPtr(qube3_dc_lqr_M->extModeInfo, rtmGetTPtr(qube3_dc_lqr_M));
  }

  qube3_dc_lqr_M->solverInfoPtr = (&qube3_dc_lqr_M->solverInfo);
  qube3_dc_lqr_M->Timing.stepSize = (0.02);
  rtsiSetFixedStepSize(&qube3_dc_lqr_M->solverInfo, 0.02);
  rtsiSetSolverMode(&qube3_dc_lqr_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  qube3_dc_lqr_M->blockIO = ((void *) &qube3_dc_lqr_B);
  (void) memset(((void *) &qube3_dc_lqr_B), 0,
                sizeof(B_qube3_dc_lqr_T));

  /* parameters */
  qube3_dc_lqr_M->defaultParam = ((real_T *)&qube3_dc_lqr_P);

  /* states (dwork) */
  qube3_dc_lqr_M->dwork = ((void *) &qube3_dc_lqr_DW);
  (void) memset((void *)&qube3_dc_lqr_DW, 0,
                sizeof(DW_qube3_dc_lqr_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    qube3_dc_lqr_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 22;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  qube3_dc_lqr_M->Sizes.numContStates = (0);/* Number of continuous states */
  qube3_dc_lqr_M->Sizes.numY = (0);    /* Number of model outputs */
  qube3_dc_lqr_M->Sizes.numU = (0);    /* Number of model inputs */
  qube3_dc_lqr_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  qube3_dc_lqr_M->Sizes.numSampTimes = (1);/* Number of sample times */
  qube3_dc_lqr_M->Sizes.numBlocks = (15);/* Number of blocks */
  qube3_dc_lqr_M->Sizes.numBlockIO = (5);/* Number of block outputs */
  qube3_dc_lqr_M->Sizes.numBlockPrms = (97);/* Sum of parameter "widths" */
  return qube3_dc_lqr_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
