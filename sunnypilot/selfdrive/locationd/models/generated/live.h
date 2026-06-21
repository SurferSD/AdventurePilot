#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void live_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_9(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_12(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_35(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_32(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_33(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_H(double *in_vec, double *out_6551973308262930152);
void live_err_fun(double *nom_x, double *delta_x, double *out_5646152296846133802);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_7701379493643237642);
void live_H_mod_fun(double *state, double *out_8319047590358081503);
void live_f_fun(double *state, double dt, double *out_8255420781521079097);
void live_F_fun(double *state, double dt, double *out_6778889164445502072);
void live_h_4(double *state, double *unused, double *out_9158985544781006199);
void live_H_4(double *state, double *unused, double *out_2014686025803390378);
void live_h_9(double *state, double *unused, double *out_1308244237097282936);
void live_H_9(double *state, double *unused, double *out_2255875672432981023);
void live_h_10(double *state, double *unused, double *out_642147218131865389);
void live_H_10(double *state, double *unused, double *out_207023446991648910);
void live_h_12(double *state, double *unused, double *out_3104506656923796971);
void live_H_12(double *state, double *unused, double *out_7034142433835352173);
void live_h_35(double *state, double *unused, double *out_1778834612643108243);
void live_H_35(double *state, double *unused, double *out_5381348083175997754);
void live_h_32(double *state, double *unused, double *out_9190865124466407525);
void live_H_32(double *state, double *unused, double *out_1533516420518118602);
void live_h_13(double *state, double *unused, double *out_2254745892595379273);
void live_H_13(double *state, double *unused, double *out_8097881863751574557);
void live_h_14(double *state, double *unused, double *out_1308244237097282936);
void live_H_14(double *state, double *unused, double *out_2255875672432981023);
void live_h_33(double *state, double *unused, double *out_3872908584919559654);
void live_H_33(double *state, double *unused, double *out_8531905087814855358);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}