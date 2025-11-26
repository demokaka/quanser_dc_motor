/*
 * qube3_dc_mpc_private.h
 *
 * Classroom License -- for classroom instructional use only.  Not for
 * government, commercial, academic research, or other organizational use.
 *
 * Code generation for model "qube3_dc_mpc".
 *
 * Model version              : 15.4
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Wed Nov 26 14:26:52 2025
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_qube3_dc_mpc_private_h_
#define RTW_HEADER_qube3_dc_mpc_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "qube3_dc_mpc_types.h"
#include "qube3_dc_mpc.h"

/* A global buffer for storing error messages (defined in quanser_common library) */
EXTERN char _rt_error_message[512];
extern void mpc_solver_wrapper(SimStruct *rts);

#endif                                 /* RTW_HEADER_qube3_dc_mpc_private_h_ */
