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
void live_H(double *in_vec, double *out_3006896087495758141);
void live_err_fun(double *nom_x, double *delta_x, double *out_5268339192127001686);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_1334090663346056850);
void live_H_mod_fun(double *state, double *out_680857234219406518);
void live_f_fun(double *state, double dt, double *out_4490991915098634764);
void live_F_fun(double *state, double dt, double *out_932400815757755706);
void live_h_4(double *state, double *unused, double *out_843740498994983045);
void live_H_4(double *state, double *unused, double *out_3410567791843551733);
void live_h_9(double *state, double *unused, double *out_5060598127802924978);
void live_H_9(double *state, double *unused, double *out_3651757438473142378);
void live_h_10(double *state, double *unused, double *out_200019392468926383);
void live_H_10(double *state, double *unused, double *out_4627301739102033240);
void live_h_12(double *state, double *unused, double *out_1313091002527575728);
void live_H_12(double *state, double *unused, double *out_4031666816891145400);
void live_h_35(double *state, double *unused, double *out_8197017839518763228);
void live_H_35(double *state, double *unused, double *out_6777229849216159109);
void live_h_32(double *state, double *unused, double *out_4121897211438798065);
void live_H_32(double *state, double *unused, double *out_8885856060074974914);
void live_h_13(double *state, double *unused, double *out_546862960083111833);
void live_H_13(double *state, double *unused, double *out_2652315771118229892);
void live_h_14(double *state, double *unused, double *out_5060598127802924978);
void live_H_14(double *state, double *unused, double *out_3651757438473142378);
void live_h_33(double *state, double *unused, double *out_7848185056816485040);
void live_H_33(double *state, double *unused, double *out_8518957219854534903);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}