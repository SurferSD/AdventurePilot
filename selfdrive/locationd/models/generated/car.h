#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_2640428774147462467);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_2999667536812604211);
void car_H_mod_fun(double *state, double *out_770486692159578473);
void car_f_fun(double *state, double dt, double *out_2588187187785096529);
void car_F_fun(double *state, double dt, double *out_5896136663256409001);
void car_h_25(double *state, double *unused, double *out_37035910800207699);
void car_H_25(double *state, double *unused, double *out_265152249959281761);
void car_h_24(double *state, double *unused, double *out_451524429059313537);
void car_H_24(double *state, double *unused, double *out_7153239383717645132);
void car_h_30(double *state, double *unused, double *out_6925683045483371328);
void car_H_30(double *state, double *unused, double *out_394491197102521831);
void car_h_26(double *state, double *unused, double *out_2500517615785703846);
void car_H_26(double *state, double *unused, double *out_4006655568833337985);
void car_h_27(double *state, double *unused, double *out_6283486968260381167);
void car_H_27(double *state, double *unused, double *out_2569254508902946742);
void car_h_29(double *state, double *unused, double *out_7986435168816538305);
void car_H_29(double *state, double *unused, double *out_115740147211870353);
void car_h_28(double *state, double *unused, double *out_3903315595626162818);
void car_H_28(double *state, double *unused, double *out_2079370418777196604);
void car_h_31(double *state, double *unused, double *out_1439000368950664667);
void car_H_31(double *state, double *unused, double *out_234506288082321333);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}