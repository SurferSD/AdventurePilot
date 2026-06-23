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
void car_err_fun(double *nom_x, double *delta_x, double *out_1438650671028872411);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_118897991165749859);
void car_H_mod_fun(double *state, double *out_3538938183658621936);
void car_f_fun(double *state, double dt, double *out_8041848752120563302);
void car_F_fun(double *state, double dt, double *out_6101074590669493556);
void car_h_25(double *state, double *unused, double *out_2324703226181244870);
void car_H_25(double *state, double *unused, double *out_6986467857077069875);
void car_h_24(double *state, double *unused, double *out_978298744582143813);
void car_H_24(double *state, double *unused, double *out_3428542258274746739);
void car_h_30(double *state, double *unused, double *out_6054409232538113613);
void car_H_30(double *state, double *unused, double *out_4468134898569821248);
void car_h_26(double *state, double *unused, double *out_6907250809830605548);
void car_H_26(double *state, double *unused, double *out_7718772897758425517);
void car_h_27(double *state, double *unused, double *out_6789243415897228804);
void car_H_27(double *state, double *unused, double *out_2244540827385878031);
void car_h_29(double *state, double *unused, double *out_4172337729268054975);
void car_H_29(double *state, double *unused, double *out_3957903554255429064);
void car_h_28(double *state, double *unused, double *out_2231299996543247638);
void car_H_28(double *state, double *unused, double *out_9040302571324959638);
void car_h_31(double *state, double *unused, double *out_4027651426737402008);
void car_H_31(double *state, double *unused, double *out_7092564795525074041);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}