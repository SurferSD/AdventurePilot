#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_5361244045644666122);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_8995639648578932435);
void pose_H_mod_fun(double *state, double *out_401548470790065973);
void pose_f_fun(double *state, double dt, double *out_8900446657124786632);
void pose_F_fun(double *state, double dt, double *out_8518082037714010112);
void pose_h_4(double *state, double *unused, double *out_340313044583703153);
void pose_H_4(double *state, double *unused, double *out_3448892390570509255);
void pose_h_10(double *state, double *unused, double *out_7998523049083505895);
void pose_H_10(double *state, double *unused, double *out_3744112959449252940);
void pose_h_13(double *state, double *unused, double *out_7266816994167798755);
void pose_H_13(double *state, double *unused, double *out_6661166215902842056);
void pose_h_14(double *state, double *unused, double *out_6080732506564879452);
void pose_H_14(double *state, double *unused, double *out_7412133246909993784);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}