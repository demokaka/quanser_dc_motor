/*
 * generic_nlp_ocp_solver_simulink_block.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "generic_nlp_ocp_solver_simulink_block".
 *
 * Model version              : 18.4
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Wed Nov 26 19:20:19 2025
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "generic_nlp_ocp_solver_simulink_block.h"
#include "rtwtypes.h"
#include <math.h>
#include "generic_nlp_ocp_solver_simulink_block_private.h"
#include <string.h>
#include "generic_nlp_ocp_solver_simulink_block_dt.h"

const real_T generic_nlp_ocp_solver_simulink_block_RGND = 0.0;/* real_T ground */

/* Block signals (default storage) */
B_generic_nlp_ocp_solver_simulink_block_T
  generic_nlp_ocp_solver_simulink_block_B;

/* Block states (default storage) */
DW_generic_nlp_ocp_solver_simulink_block_T
  generic_nlp_ocp_solver_simulink_block_DW;

/* Real-time model */
static RT_MODEL_generic_nlp_ocp_solver_simulink_block_T
  generic_nlp_ocp_solver_simulink_block_M_;
RT_MODEL_generic_nlp_ocp_solver_simulink_block_T *const
  generic_nlp_ocp_solver_simulink_block_M =
  &generic_nlp_ocp_solver_simulink_block_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(generic_nlp_ocp_solver_simulink_block_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(generic_nlp_ocp_solver_simulink_block_M, 2);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 2 */
  if (generic_nlp_ocp_solver_simulink_block_M->Timing.TaskCounters.TID[1] == 0)
  {
    generic_nlp_ocp_solver_simulink_block_M->Timing.RateInteraction.TID1_2 =
      (generic_nlp_ocp_solver_simulink_block_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    generic_nlp_ocp_solver_simulink_block_M->Timing.perTaskSampleHits[5] =
      generic_nlp_ocp_solver_simulink_block_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (generic_nlp_ocp_solver_simulink_block_M->Timing.TaskCounters.TID[2])++;
  if ((generic_nlp_ocp_solver_simulink_block_M->Timing.TaskCounters.TID[2]) >
      499) {                           /* Sample time: [1.0s, 0.0s] */
    generic_nlp_ocp_solver_simulink_block_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/* Model output function for TID0 */
void generic_nlp_ocp_solver_simulink_block_output0(void) /* Sample time: [0.0s, 0.0s] */
{
  {                                    /* Sample time: [0.0s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Sin: '<Root>/Sine Wave' */
  generic_nlp_ocp_solver_simulink_block_B.SineWave = sin
    (generic_nlp_ocp_solver_simulink_block_P.SineWave_Freq *
     generic_nlp_ocp_solver_simulink_block_M->Timing.t[0] +
     generic_nlp_ocp_solver_simulink_block_P.SineWave_Phase) *
    generic_nlp_ocp_solver_simulink_block_P.SineWave_Amp +
    generic_nlp_ocp_solver_simulink_block_P.SineWave_Bias;

  /* RateTransition generated from: '<Root>/generic_nlp_ocp_solver' */
  if (generic_nlp_ocp_solver_simulink_block_M->Timing.RateInteraction.TID1_2) {
    generic_nlp_ocp_solver_simulink_block_DW.TmpRTBAtgeneric_nlp_ocp_solverI =
      generic_nlp_ocp_solver_simulink_block_B.SineWave;
  }

  /* End of RateTransition generated from: '<Root>/generic_nlp_ocp_solver' */
}

/* Model update function for TID0 */
void generic_nlp_ocp_solver_simulink_block_update0(void) /* Sample time: [0.0s, 0.0s] */
{
  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++generic_nlp_ocp_solver_simulink_block_M->Timing.clockTick0)) {
    ++generic_nlp_ocp_solver_simulink_block_M->Timing.clockTickH0;
  }

  generic_nlp_ocp_solver_simulink_block_M->Timing.t[0] =
    generic_nlp_ocp_solver_simulink_block_M->Timing.clockTick0 *
    generic_nlp_ocp_solver_simulink_block_M->Timing.stepSize0 +
    generic_nlp_ocp_solver_simulink_block_M->Timing.clockTickH0 *
    generic_nlp_ocp_solver_simulink_block_M->Timing.stepSize0 * 4294967296.0;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++generic_nlp_ocp_solver_simulink_block_M->Timing.clockTick1)) {
    ++generic_nlp_ocp_solver_simulink_block_M->Timing.clockTickH1;
  }

  generic_nlp_ocp_solver_simulink_block_M->Timing.t[1] =
    generic_nlp_ocp_solver_simulink_block_M->Timing.clockTick1 *
    generic_nlp_ocp_solver_simulink_block_M->Timing.stepSize1 +
    generic_nlp_ocp_solver_simulink_block_M->Timing.clockTickH1 *
    generic_nlp_ocp_solver_simulink_block_M->Timing.stepSize1 * 4294967296.0;
}

/* Model output function for TID2 */
void generic_nlp_ocp_solver_simulink_block_output2(void) /* Sample time: [1.0s, 0.0s] */
{
  /* RateTransition generated from: '<Root>/generic_nlp_ocp_solver' */
  generic_nlp_ocp_solver_simulink_block_B.TmpRTBAtgeneric_nlp_ocp_solverI =
    generic_nlp_ocp_solver_simulink_block_DW.TmpRTBAtgeneric_nlp_ocp_solverI;

  /* S-Function (acados_solver_sfunction_generic_nlp): '<Root>/generic_nlp_ocp_solver' */

  /* Level2 S-Function Block: '<Root>/generic_nlp_ocp_solver' (acados_solver_sfunction_generic_nlp) */
  {
    SimStruct *rts = generic_nlp_ocp_solver_simulink_block_M->childSfunctions[0];
    sfcnOutputs(rts,2);
  }
}

/* Model update function for TID2 */
void generic_nlp_ocp_solver_simulink_block_update2(void) /* Sample time: [1.0s, 0.0s] */
{
  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++generic_nlp_ocp_solver_simulink_block_M->Timing.clockTick2)) {
    ++generic_nlp_ocp_solver_simulink_block_M->Timing.clockTickH2;
  }

  generic_nlp_ocp_solver_simulink_block_M->Timing.t[2] =
    generic_nlp_ocp_solver_simulink_block_M->Timing.clockTick2 *
    generic_nlp_ocp_solver_simulink_block_M->Timing.stepSize2 +
    generic_nlp_ocp_solver_simulink_block_M->Timing.clockTickH2 *
    generic_nlp_ocp_solver_simulink_block_M->Timing.stepSize2 * 4294967296.0;
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void generic_nlp_ocp_solver_simulink_block_output(int_T tid)
{
  switch (tid) {
   case 0 :
    generic_nlp_ocp_solver_simulink_block_output0();
    break;

   case 2 :
    generic_nlp_ocp_solver_simulink_block_output2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void generic_nlp_ocp_solver_simulink_block_update(int_T tid)
{
  switch (tid) {
   case 0 :
    generic_nlp_ocp_solver_simulink_block_update0();
    break;

   case 2 :
    generic_nlp_ocp_solver_simulink_block_update2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void generic_nlp_ocp_solver_simulink_block_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: generic_nlp_ocp_solver_simulink_block/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("qube_servo3_usb", "0@tcpip://localhost:18922",
                      &generic_nlp_ocp_solver_simulink_block_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(generic_nlp_ocp_solver_simulink_block_M,
                        _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (generic_nlp_ocp_solver_simulink_block_DW.HILInitialize_Card,
       "deadband_compensation=0.3;pwm_en=0;enc0_velocity=3.0;enc1_velocity=3.0;min_diode_compensation=0.3;max_diode_compensation=1.5",
       125);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(generic_nlp_ocp_solver_simulink_block_M,
                        _rt_error_message);
      return;
    }

    result = hil_watchdog_clear
      (generic_nlp_ocp_solver_simulink_block_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(generic_nlp_ocp_solver_simulink_block_M,
                        _rt_error_message);
      return;
    }

    if ((generic_nlp_ocp_solver_simulink_block_P.HILInitialize_AIPStart &&
         !is_switching) ||
        (generic_nlp_ocp_solver_simulink_block_P.HILInitialize_AIPEnter &&
         is_switching)) {
      result = hil_set_analog_input_ranges
        (generic_nlp_ocp_solver_simulink_block_DW.HILInitialize_Card,
         &generic_nlp_ocp_solver_simulink_block_P.HILInitialize_AIChannels, 1U,
         &generic_nlp_ocp_solver_simulink_block_P.HILInitialize_AILow,
         &generic_nlp_ocp_solver_simulink_block_P.HILInitialize_AIHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(generic_nlp_ocp_solver_simulink_block_M,
                          _rt_error_message);
        return;
      }
    }

    if ((generic_nlp_ocp_solver_simulink_block_P.HILInitialize_AOPStart &&
         !is_switching) ||
        (generic_nlp_ocp_solver_simulink_block_P.HILInitialize_AOPEnter &&
         is_switching)) {
      result = hil_set_analog_output_ranges
        (generic_nlp_ocp_solver_simulink_block_DW.HILInitialize_Card,
         &generic_nlp_ocp_solver_simulink_block_P.HILInitialize_AOChannels, 1U,
         &generic_nlp_ocp_solver_simulink_block_P.HILInitialize_AOLow,
         &generic_nlp_ocp_solver_simulink_block_P.HILInitialize_AOHigh);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(generic_nlp_ocp_solver_simulink_block_M,
                          _rt_error_message);
        return;
      }
    }

    if ((generic_nlp_ocp_solver_simulink_block_P.HILInitialize_AOStart &&
         !is_switching) ||
        (generic_nlp_ocp_solver_simulink_block_P.HILInitialize_AOEnter &&
         is_switching)) {
      result = hil_write_analog
        (generic_nlp_ocp_solver_simulink_block_DW.HILInitialize_Card,
         &generic_nlp_ocp_solver_simulink_block_P.HILInitialize_AOChannels, 1U,
         &generic_nlp_ocp_solver_simulink_block_P.HILInitialize_AOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(generic_nlp_ocp_solver_simulink_block_M,
                          _rt_error_message);
        return;
      }
    }

    if (generic_nlp_ocp_solver_simulink_block_P.HILInitialize_AOReset) {
      result = hil_watchdog_set_analog_expiration_state
        (generic_nlp_ocp_solver_simulink_block_DW.HILInitialize_Card,
         &generic_nlp_ocp_solver_simulink_block_P.HILInitialize_AOChannels, 1U,
         &generic_nlp_ocp_solver_simulink_block_P.HILInitialize_AOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(generic_nlp_ocp_solver_simulink_block_M,
                          _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions
      (generic_nlp_ocp_solver_simulink_block_DW.HILInitialize_Card, NULL, 0U,
       &generic_nlp_ocp_solver_simulink_block_P.HILInitialize_DOChannels, 1U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(generic_nlp_ocp_solver_simulink_block_M,
                        _rt_error_message);
      return;
    }

    if ((generic_nlp_ocp_solver_simulink_block_P.HILInitialize_DOStart &&
         !is_switching) ||
        (generic_nlp_ocp_solver_simulink_block_P.HILInitialize_DOEnter &&
         is_switching)) {
      result = hil_write_digital
        (generic_nlp_ocp_solver_simulink_block_DW.HILInitialize_Card,
         &generic_nlp_ocp_solver_simulink_block_P.HILInitialize_DOChannels, 1U,
         (t_boolean *)
         &generic_nlp_ocp_solver_simulink_block_P.HILInitialize_DOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(generic_nlp_ocp_solver_simulink_block_M,
                          _rt_error_message);
        return;
      }
    }

    if (generic_nlp_ocp_solver_simulink_block_P.HILInitialize_DOReset) {
      result = hil_watchdog_set_digital_expiration_state
        (generic_nlp_ocp_solver_simulink_block_DW.HILInitialize_Card,
         &generic_nlp_ocp_solver_simulink_block_P.HILInitialize_DOChannels, 1U,
         (const t_digital_state *)
         &generic_nlp_ocp_solver_simulink_block_P.HILInitialize_DOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(generic_nlp_ocp_solver_simulink_block_M,
                          _rt_error_message);
        return;
      }
    }

    if ((generic_nlp_ocp_solver_simulink_block_P.HILInitialize_EIPStart &&
         !is_switching) ||
        (generic_nlp_ocp_solver_simulink_block_P.HILInitialize_EIPEnter &&
         is_switching)) {
      generic_nlp_ocp_solver_simulink_block_DW.HILInitialize_QuadratureModes[0] =
        generic_nlp_ocp_solver_simulink_block_P.HILInitialize_EIQuadrature;
      generic_nlp_ocp_solver_simulink_block_DW.HILInitialize_QuadratureModes[1] =
        generic_nlp_ocp_solver_simulink_block_P.HILInitialize_EIQuadrature;
      result = hil_set_encoder_quadrature_mode
        (generic_nlp_ocp_solver_simulink_block_DW.HILInitialize_Card,
         generic_nlp_ocp_solver_simulink_block_P.HILInitialize_EIChannels, 2U,
         (t_encoder_quadrature_mode *)
         &generic_nlp_ocp_solver_simulink_block_DW.HILInitialize_QuadratureModes[
         0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(generic_nlp_ocp_solver_simulink_block_M,
                          _rt_error_message);
        return;
      }
    }

    if ((generic_nlp_ocp_solver_simulink_block_P.HILInitialize_EIStart &&
         !is_switching) ||
        (generic_nlp_ocp_solver_simulink_block_P.HILInitialize_EIEnter &&
         is_switching)) {
      generic_nlp_ocp_solver_simulink_block_DW.HILInitialize_InitialEICounts[0] =
        generic_nlp_ocp_solver_simulink_block_P.HILInitialize_EIInitial;
      generic_nlp_ocp_solver_simulink_block_DW.HILInitialize_InitialEICounts[1] =
        generic_nlp_ocp_solver_simulink_block_P.HILInitialize_EIInitial;
      result = hil_set_encoder_counts
        (generic_nlp_ocp_solver_simulink_block_DW.HILInitialize_Card,
         generic_nlp_ocp_solver_simulink_block_P.HILInitialize_EIChannels, 2U,
         &generic_nlp_ocp_solver_simulink_block_DW.HILInitialize_InitialEICounts[
         0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(generic_nlp_ocp_solver_simulink_block_M,
                          _rt_error_message);
        return;
      }
    }

    if ((generic_nlp_ocp_solver_simulink_block_P.HILInitialize_OOStart &&
         !is_switching) ||
        (generic_nlp_ocp_solver_simulink_block_P.HILInitialize_OOEnter &&
         is_switching)) {
      result = hil_write_other
        (generic_nlp_ocp_solver_simulink_block_DW.HILInitialize_Card,
         generic_nlp_ocp_solver_simulink_block_P.HILInitialize_OOChannels, 3U,
         generic_nlp_ocp_solver_simulink_block_P.HILInitialize_OOInitial);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(generic_nlp_ocp_solver_simulink_block_M,
                          _rt_error_message);
        return;
      }
    }

    if (generic_nlp_ocp_solver_simulink_block_P.HILInitialize_OOReset) {
      result = hil_watchdog_set_other_expiration_state
        (generic_nlp_ocp_solver_simulink_block_DW.HILInitialize_Card,
         generic_nlp_ocp_solver_simulink_block_P.HILInitialize_OOChannels, 3U,
         generic_nlp_ocp_solver_simulink_block_P.HILInitialize_OOWatchdog);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(generic_nlp_ocp_solver_simulink_block_M,
                          _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (acados_solver_sfunction_generic_nlp): '<Root>/generic_nlp_ocp_solver' */
  /* Level2 S-Function Block: '<Root>/generic_nlp_ocp_solver' (acados_solver_sfunction_generic_nlp) */
  {
    SimStruct *rts = generic_nlp_ocp_solver_simulink_block_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }
}

/* Model terminate function */
void generic_nlp_ocp_solver_simulink_block_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: generic_nlp_ocp_solver_simulink_block/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_digital_outputs = 0;
    t_uint32 num_final_other_outputs = 0;
    hil_task_stop_all
      (generic_nlp_ocp_solver_simulink_block_DW.HILInitialize_Card);
    hil_monitor_stop_all
      (generic_nlp_ocp_solver_simulink_block_DW.HILInitialize_Card);
    is_switching = false;
    if ((generic_nlp_ocp_solver_simulink_block_P.HILInitialize_AOTerminate &&
         !is_switching) ||
        (generic_nlp_ocp_solver_simulink_block_P.HILInitialize_AOExit &&
         is_switching)) {
      num_final_analog_outputs = 1U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((generic_nlp_ocp_solver_simulink_block_P.HILInitialize_DOTerminate &&
         !is_switching) ||
        (generic_nlp_ocp_solver_simulink_block_P.HILInitialize_DOExit &&
         is_switching)) {
      num_final_digital_outputs = 1U;
    } else {
      num_final_digital_outputs = 0;
    }

    if ((generic_nlp_ocp_solver_simulink_block_P.HILInitialize_OOTerminate &&
         !is_switching) ||
        (generic_nlp_ocp_solver_simulink_block_P.HILInitialize_OOExit &&
         is_switching)) {
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
      result = hil_write
        (generic_nlp_ocp_solver_simulink_block_DW.HILInitialize_Card
         , &generic_nlp_ocp_solver_simulink_block_P.HILInitialize_AOChannels,
         num_final_analog_outputs
         , NULL, 0
         , &generic_nlp_ocp_solver_simulink_block_P.HILInitialize_DOChannels,
         num_final_digital_outputs
         , generic_nlp_ocp_solver_simulink_block_P.HILInitialize_OOChannels,
         num_final_other_outputs
         , &generic_nlp_ocp_solver_simulink_block_P.HILInitialize_AOFinal
         , NULL
         , (t_boolean *)
         &generic_nlp_ocp_solver_simulink_block_P.HILInitialize_DOFinal
         , generic_nlp_ocp_solver_simulink_block_P.HILInitialize_OOFinal
         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog
            (generic_nlp_ocp_solver_simulink_block_DW.HILInitialize_Card,
             &generic_nlp_ocp_solver_simulink_block_P.HILInitialize_AOChannels,
             num_final_analog_outputs,
             &generic_nlp_ocp_solver_simulink_block_P.HILInitialize_AOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_digital_outputs > 0) {
          local_result = hil_write_digital
            (generic_nlp_ocp_solver_simulink_block_DW.HILInitialize_Card,
             &generic_nlp_ocp_solver_simulink_block_P.HILInitialize_DOChannels,
             num_final_digital_outputs, (t_boolean *)
             &generic_nlp_ocp_solver_simulink_block_P.HILInitialize_DOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_other_outputs > 0) {
          local_result = hil_write_other
            (generic_nlp_ocp_solver_simulink_block_DW.HILInitialize_Card,
             generic_nlp_ocp_solver_simulink_block_P.HILInitialize_OOChannels,
             num_final_other_outputs,
             generic_nlp_ocp_solver_simulink_block_P.HILInitialize_OOFinal);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(generic_nlp_ocp_solver_simulink_block_M,
                            _rt_error_message);
        }
      }
    }

    hil_task_delete_all
      (generic_nlp_ocp_solver_simulink_block_DW.HILInitialize_Card);
    hil_monitor_delete_all
      (generic_nlp_ocp_solver_simulink_block_DW.HILInitialize_Card);
    hil_close(generic_nlp_ocp_solver_simulink_block_DW.HILInitialize_Card);
    generic_nlp_ocp_solver_simulink_block_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for S-Function (acados_solver_sfunction_generic_nlp): '<Root>/generic_nlp_ocp_solver' */
  /* Level2 S-Function Block: '<Root>/generic_nlp_ocp_solver' (acados_solver_sfunction_generic_nlp) */
  {
    SimStruct *rts = generic_nlp_ocp_solver_simulink_block_M->childSfunctions[0];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  if (tid == 1)
    tid = 0;
  generic_nlp_ocp_solver_simulink_block_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  generic_nlp_ocp_solver_simulink_block_update(tid);
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
  generic_nlp_ocp_solver_simulink_block_initialize();
}

void MdlTerminate(void)
{
  generic_nlp_ocp_solver_simulink_block_terminate();
}

/* Registration function */
RT_MODEL_generic_nlp_ocp_solver_simulink_block_T
  *generic_nlp_ocp_solver_simulink_block(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)generic_nlp_ocp_solver_simulink_block_M, 0,
                sizeof(RT_MODEL_generic_nlp_ocp_solver_simulink_block_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&generic_nlp_ocp_solver_simulink_block_M->solverInfo,
                          &generic_nlp_ocp_solver_simulink_block_M->Timing.simTimeStep);
    rtsiSetTPtr(&generic_nlp_ocp_solver_simulink_block_M->solverInfo,
                &rtmGetTPtr(generic_nlp_ocp_solver_simulink_block_M));
    rtsiSetStepSizePtr(&generic_nlp_ocp_solver_simulink_block_M->solverInfo,
                       &generic_nlp_ocp_solver_simulink_block_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&generic_nlp_ocp_solver_simulink_block_M->solverInfo,
                          (&rtmGetErrorStatus
      (generic_nlp_ocp_solver_simulink_block_M)));
    rtsiSetRTModelPtr(&generic_nlp_ocp_solver_simulink_block_M->solverInfo,
                      generic_nlp_ocp_solver_simulink_block_M);
  }

  rtsiSetSimTimeStep(&generic_nlp_ocp_solver_simulink_block_M->solverInfo,
                     MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange
    (&generic_nlp_ocp_solver_simulink_block_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&generic_nlp_ocp_solver_simulink_block_M->solverInfo,
    false);
  rtsiSetSolverName(&generic_nlp_ocp_solver_simulink_block_M->solverInfo,
                    "FixedStepDiscrete");
  generic_nlp_ocp_solver_simulink_block_M->solverInfoPtr =
    (&generic_nlp_ocp_solver_simulink_block_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      generic_nlp_ocp_solver_simulink_block_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    generic_nlp_ocp_solver_simulink_block_M->Timing.sampleTimeTaskIDPtr =
      (&mdlTsMap[0]);
    generic_nlp_ocp_solver_simulink_block_M->Timing.sampleTimes =
      (&generic_nlp_ocp_solver_simulink_block_M->Timing.sampleTimesArray[0]);
    generic_nlp_ocp_solver_simulink_block_M->Timing.offsetTimes =
      (&generic_nlp_ocp_solver_simulink_block_M->Timing.offsetTimesArray[0]);

    /* task periods */
    generic_nlp_ocp_solver_simulink_block_M->Timing.sampleTimes[0] = (0.0);
    generic_nlp_ocp_solver_simulink_block_M->Timing.sampleTimes[1] = (0.002);
    generic_nlp_ocp_solver_simulink_block_M->Timing.sampleTimes[2] = (1.0);

    /* task offsets */
    generic_nlp_ocp_solver_simulink_block_M->Timing.offsetTimes[0] = (0.0);
    generic_nlp_ocp_solver_simulink_block_M->Timing.offsetTimes[1] = (0.0);
    generic_nlp_ocp_solver_simulink_block_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(generic_nlp_ocp_solver_simulink_block_M,
             &generic_nlp_ocp_solver_simulink_block_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits =
      generic_nlp_ocp_solver_simulink_block_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      generic_nlp_ocp_solver_simulink_block_M->Timing.perTaskSampleHitsArray;
    generic_nlp_ocp_solver_simulink_block_M->Timing.perTaskSampleHits =
      (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    generic_nlp_ocp_solver_simulink_block_M->Timing.sampleHits =
      (&mdlSampleHits[0]);
  }

  rtmSetTFinal(generic_nlp_ocp_solver_simulink_block_M, -1);
  generic_nlp_ocp_solver_simulink_block_M->Timing.stepSize0 = 0.002;
  generic_nlp_ocp_solver_simulink_block_M->Timing.stepSize1 = 0.002;
  generic_nlp_ocp_solver_simulink_block_M->Timing.stepSize2 = 1.0;

  /* External mode info */
  generic_nlp_ocp_solver_simulink_block_M->Sizes.checksums[0] = (3061271915U);
  generic_nlp_ocp_solver_simulink_block_M->Sizes.checksums[1] = (2212849395U);
  generic_nlp_ocp_solver_simulink_block_M->Sizes.checksums[2] = (2364064394U);
  generic_nlp_ocp_solver_simulink_block_M->Sizes.checksums[3] = (4013746062U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    generic_nlp_ocp_solver_simulink_block_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr
      (generic_nlp_ocp_solver_simulink_block_M->extModeInfo,
       &generic_nlp_ocp_solver_simulink_block_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(generic_nlp_ocp_solver_simulink_block_M->extModeInfo,
                        generic_nlp_ocp_solver_simulink_block_M->Sizes.checksums);
    rteiSetTPtr(generic_nlp_ocp_solver_simulink_block_M->extModeInfo, rtmGetTPtr
                (generic_nlp_ocp_solver_simulink_block_M));
  }

  generic_nlp_ocp_solver_simulink_block_M->solverInfoPtr =
    (&generic_nlp_ocp_solver_simulink_block_M->solverInfo);
  generic_nlp_ocp_solver_simulink_block_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&generic_nlp_ocp_solver_simulink_block_M->solverInfo,
                       0.002);
  rtsiSetSolverMode(&generic_nlp_ocp_solver_simulink_block_M->solverInfo,
                    SOLVER_MODE_MULTITASKING);

  /* block I/O */
  generic_nlp_ocp_solver_simulink_block_M->blockIO = ((void *)
    &generic_nlp_ocp_solver_simulink_block_B);
  (void) memset(((void *) &generic_nlp_ocp_solver_simulink_block_B), 0,
                sizeof(B_generic_nlp_ocp_solver_simulink_block_T));

  /* parameters */
  generic_nlp_ocp_solver_simulink_block_M->defaultParam = ((real_T *)
    &generic_nlp_ocp_solver_simulink_block_P);

  /* states (dwork) */
  generic_nlp_ocp_solver_simulink_block_M->dwork = ((void *)
    &generic_nlp_ocp_solver_simulink_block_DW);
  (void) memset((void *)&generic_nlp_ocp_solver_simulink_block_DW, 0,
                sizeof(DW_generic_nlp_ocp_solver_simulink_block_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    generic_nlp_ocp_solver_simulink_block_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 20;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo =
      &generic_nlp_ocp_solver_simulink_block_M->NonInlinedSFcns.sfcnInfo;
    generic_nlp_ocp_solver_simulink_block_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus
      (generic_nlp_ocp_solver_simulink_block_M)));
    generic_nlp_ocp_solver_simulink_block_M->Sizes.numSampTimes = (3);
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &generic_nlp_ocp_solver_simulink_block_M->Sizes.numSampTimes);
    generic_nlp_ocp_solver_simulink_block_M->NonInlinedSFcns.taskTimePtrs[0] = (
      &rtmGetTPtr(generic_nlp_ocp_solver_simulink_block_M)[0]);
    generic_nlp_ocp_solver_simulink_block_M->NonInlinedSFcns.taskTimePtrs[1] = (
      &rtmGetTPtr(generic_nlp_ocp_solver_simulink_block_M)[1]);
    generic_nlp_ocp_solver_simulink_block_M->NonInlinedSFcns.taskTimePtrs[2] = (
      &rtmGetTPtr(generic_nlp_ocp_solver_simulink_block_M)[2]);
    rtssSetTPtrPtr(sfcnInfo,
                   generic_nlp_ocp_solver_simulink_block_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart
                     (generic_nlp_ocp_solver_simulink_block_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal
                     (generic_nlp_ocp_solver_simulink_block_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (generic_nlp_ocp_solver_simulink_block_M));
    rtssSetStepSizePtr(sfcnInfo,
                       &generic_nlp_ocp_solver_simulink_block_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested
      (generic_nlp_ocp_solver_simulink_block_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &generic_nlp_ocp_solver_simulink_block_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &generic_nlp_ocp_solver_simulink_block_M->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &generic_nlp_ocp_solver_simulink_block_M->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo,
                         &generic_nlp_ocp_solver_simulink_block_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &generic_nlp_ocp_solver_simulink_block_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo,
                      &generic_nlp_ocp_solver_simulink_block_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo,
                         &generic_nlp_ocp_solver_simulink_block_M->solverInfoPtr);
  }

  generic_nlp_ocp_solver_simulink_block_M->Sizes.numSFcns = (1);

  /* register each child */
  {
    (void) memset((void *)
                  &generic_nlp_ocp_solver_simulink_block_M->NonInlinedSFcns.childSFunctions
                  [0], 0,
                  1*sizeof(SimStruct));
    generic_nlp_ocp_solver_simulink_block_M->childSfunctions =
      (&generic_nlp_ocp_solver_simulink_block_M->NonInlinedSFcns.childSFunctionPtrs
       [0]);
    generic_nlp_ocp_solver_simulink_block_M->childSfunctions[0] =
      (&generic_nlp_ocp_solver_simulink_block_M->
       NonInlinedSFcns.childSFunctions[0]);

    /* Level2 S-Function Block: generic_nlp_ocp_solver_simulink_block/<Root>/generic_nlp_ocp_solver (acados_solver_sfunction_generic_nlp) */
    {
      SimStruct *rts = generic_nlp_ocp_solver_simulink_block_M->childSfunctions
        [0];

      /* timing info */
      time_T *sfcnPeriod =
        generic_nlp_ocp_solver_simulink_block_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset =
        generic_nlp_ocp_solver_simulink_block_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap =
        generic_nlp_ocp_solver_simulink_block_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &generic_nlp_ocp_solver_simulink_block_M->NonInlinedSFcns.blkInfo2
                         [0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &generic_nlp_ocp_solver_simulink_block_M->NonInlinedSFcns.inputOutputPortInfo2
        [0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, generic_nlp_ocp_solver_simulink_block_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &generic_nlp_ocp_solver_simulink_block_M->NonInlinedSFcns.methods2
                           [0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &generic_nlp_ocp_solver_simulink_block_M->NonInlinedSFcns.methods3
                           [0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &generic_nlp_ocp_solver_simulink_block_M->NonInlinedSFcns.methods4
                           [0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &generic_nlp_ocp_solver_simulink_block_M->NonInlinedSFcns.statesInfo2
                         [0]);
        ssSetPeriodicStatesInfo(rts,
          &generic_nlp_ocp_solver_simulink_block_M->NonInlinedSFcns.periodicStatesInfo
          [0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &generic_nlp_ocp_solver_simulink_block_M->NonInlinedSFcns.Sfcn0.inputPortInfo
          [0]);
        ssSetPortInfoForInputs(rts,
          &generic_nlp_ocp_solver_simulink_block_M->NonInlinedSFcns.Sfcn0.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &generic_nlp_ocp_solver_simulink_block_M->NonInlinedSFcns.Sfcn0.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &generic_nlp_ocp_solver_simulink_block_M->NonInlinedSFcns.Sfcn0.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &generic_nlp_ocp_solver_simulink_block_M->NonInlinedSFcns.Sfcn0.UPtrs0;
          sfcnUPtrs[0] =
            &generic_nlp_ocp_solver_simulink_block_B.TmpRTBAtgeneric_nlp_ocp_solverI;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &generic_nlp_ocp_solver_simulink_block_M->NonInlinedSFcns.Sfcn0.UPtrs1;
          sfcnUPtrs[0] = ((const real_T*)
                          &generic_nlp_ocp_solver_simulink_block_RGND);
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidthAsInt(rts, 1, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &generic_nlp_ocp_solver_simulink_block_M->NonInlinedSFcns.Sfcn0.outputPortInfo
          [0]);
        ssSetPortInfoForOutputs(rts,
          &generic_nlp_ocp_solver_simulink_block_M->NonInlinedSFcns.Sfcn0.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 6);
        _ssSetPortInfo2ForOutputUnits(rts,
          &generic_nlp_ocp_solver_simulink_block_M->NonInlinedSFcns.Sfcn0.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        ssSetOutputPortUnit(rts, 1, 0);
        ssSetOutputPortUnit(rts, 2, 0);
        ssSetOutputPortUnit(rts, 3, 0);
        ssSetOutputPortUnit(rts, 4, 0);
        ssSetOutputPortUnit(rts, 5, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &generic_nlp_ocp_solver_simulink_block_M->NonInlinedSFcns.Sfcn0.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 1, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 2, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 3, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 4, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 5, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            generic_nlp_ocp_solver_simulink_block_B.generic_nlp_ocp_solver_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidthAsInt(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            &generic_nlp_ocp_solver_simulink_block_B.generic_nlp_ocp_solver_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidthAsInt(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *)
            &generic_nlp_ocp_solver_simulink_block_B.generic_nlp_ocp_solver_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidthAsInt(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *)
            &generic_nlp_ocp_solver_simulink_block_B.generic_nlp_ocp_solver_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidthAsInt(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *)
            &generic_nlp_ocp_solver_simulink_block_B.generic_nlp_ocp_solver_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidthAsInt(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((real_T *)
            &generic_nlp_ocp_solver_simulink_block_B.generic_nlp_ocp_solver_o6));
        }
      }

      /* path info */
      ssSetModelName(rts, "generic_nlp_ocp_solver");
      ssSetPath(rts,
                "generic_nlp_ocp_solver_simulink_block/generic_nlp_ocp_solver");
      ssSetRTModel(rts,generic_nlp_ocp_solver_simulink_block_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* registration */
      acados_solver_sfunction_generic_nlp(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 1.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 2;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 0);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 0);
      _ssSetOutputPortConnected(rts, 2, 0);
      _ssSetOutputPortConnected(rts, 3, 0);
      _ssSetOutputPortConnected(rts, 4, 0);
      _ssSetOutputPortConnected(rts, 5, 0);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);
      _ssSetOutputPortBeingMerged(rts, 3, 0);
      _ssSetOutputPortBeingMerged(rts, 4, 0);
      _ssSetOutputPortBeingMerged(rts, 5, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }
  }

  /* Initialize Sizes */
  generic_nlp_ocp_solver_simulink_block_M->Sizes.numContStates = (0);/* Number of continuous states */
  generic_nlp_ocp_solver_simulink_block_M->Sizes.numY = (0);/* Number of model outputs */
  generic_nlp_ocp_solver_simulink_block_M->Sizes.numU = (0);/* Number of model inputs */
  generic_nlp_ocp_solver_simulink_block_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  generic_nlp_ocp_solver_simulink_block_M->Sizes.numSampTimes = (3);/* Number of sample times */
  generic_nlp_ocp_solver_simulink_block_M->Sizes.numBlocks = (5);/* Number of blocks */
  generic_nlp_ocp_solver_simulink_block_M->Sizes.numBlockIO = (8);/* Number of block outputs */
  generic_nlp_ocp_solver_simulink_block_M->Sizes.numBlockPrms = (80);/* Sum of parameter "widths" */
  return generic_nlp_ocp_solver_simulink_block_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
