#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_4596150727177448991);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_5311469374371571464);
void pose_H_mod_fun(double *state, double *out_8767003866676733322);
void pose_f_fun(double *state, double dt, double *out_2459657190356119743);
void pose_F_fun(double *state, double dt, double *out_6577442919905546465);
void pose_h_4(double *state, double *unused, double *out_7087470237745846386);
void pose_H_4(double *state, double *unused, double *out_8925579204978105687);
void pose_h_10(double *state, double *unused, double *out_6226154528069596479);
void pose_H_10(double *state, double *unused, double *out_4349080714290348357);
void pose_h_13(double *state, double *unused, double *out_5823501144179669569);
void pose_H_13(double *state, double *unused, double *out_1314947996661404758);
void pose_h_14(double *state, double *unused, double *out_184671168520898278);
void pose_H_14(double *state, double *unused, double *out_4962338348638621158);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}