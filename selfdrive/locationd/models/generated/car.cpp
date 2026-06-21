#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_2640428774147462467) {
   out_2640428774147462467[0] = delta_x[0] + nom_x[0];
   out_2640428774147462467[1] = delta_x[1] + nom_x[1];
   out_2640428774147462467[2] = delta_x[2] + nom_x[2];
   out_2640428774147462467[3] = delta_x[3] + nom_x[3];
   out_2640428774147462467[4] = delta_x[4] + nom_x[4];
   out_2640428774147462467[5] = delta_x[5] + nom_x[5];
   out_2640428774147462467[6] = delta_x[6] + nom_x[6];
   out_2640428774147462467[7] = delta_x[7] + nom_x[7];
   out_2640428774147462467[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_2999667536812604211) {
   out_2999667536812604211[0] = -nom_x[0] + true_x[0];
   out_2999667536812604211[1] = -nom_x[1] + true_x[1];
   out_2999667536812604211[2] = -nom_x[2] + true_x[2];
   out_2999667536812604211[3] = -nom_x[3] + true_x[3];
   out_2999667536812604211[4] = -nom_x[4] + true_x[4];
   out_2999667536812604211[5] = -nom_x[5] + true_x[5];
   out_2999667536812604211[6] = -nom_x[6] + true_x[6];
   out_2999667536812604211[7] = -nom_x[7] + true_x[7];
   out_2999667536812604211[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_770486692159578473) {
   out_770486692159578473[0] = 1.0;
   out_770486692159578473[1] = 0.0;
   out_770486692159578473[2] = 0.0;
   out_770486692159578473[3] = 0.0;
   out_770486692159578473[4] = 0.0;
   out_770486692159578473[5] = 0.0;
   out_770486692159578473[6] = 0.0;
   out_770486692159578473[7] = 0.0;
   out_770486692159578473[8] = 0.0;
   out_770486692159578473[9] = 0.0;
   out_770486692159578473[10] = 1.0;
   out_770486692159578473[11] = 0.0;
   out_770486692159578473[12] = 0.0;
   out_770486692159578473[13] = 0.0;
   out_770486692159578473[14] = 0.0;
   out_770486692159578473[15] = 0.0;
   out_770486692159578473[16] = 0.0;
   out_770486692159578473[17] = 0.0;
   out_770486692159578473[18] = 0.0;
   out_770486692159578473[19] = 0.0;
   out_770486692159578473[20] = 1.0;
   out_770486692159578473[21] = 0.0;
   out_770486692159578473[22] = 0.0;
   out_770486692159578473[23] = 0.0;
   out_770486692159578473[24] = 0.0;
   out_770486692159578473[25] = 0.0;
   out_770486692159578473[26] = 0.0;
   out_770486692159578473[27] = 0.0;
   out_770486692159578473[28] = 0.0;
   out_770486692159578473[29] = 0.0;
   out_770486692159578473[30] = 1.0;
   out_770486692159578473[31] = 0.0;
   out_770486692159578473[32] = 0.0;
   out_770486692159578473[33] = 0.0;
   out_770486692159578473[34] = 0.0;
   out_770486692159578473[35] = 0.0;
   out_770486692159578473[36] = 0.0;
   out_770486692159578473[37] = 0.0;
   out_770486692159578473[38] = 0.0;
   out_770486692159578473[39] = 0.0;
   out_770486692159578473[40] = 1.0;
   out_770486692159578473[41] = 0.0;
   out_770486692159578473[42] = 0.0;
   out_770486692159578473[43] = 0.0;
   out_770486692159578473[44] = 0.0;
   out_770486692159578473[45] = 0.0;
   out_770486692159578473[46] = 0.0;
   out_770486692159578473[47] = 0.0;
   out_770486692159578473[48] = 0.0;
   out_770486692159578473[49] = 0.0;
   out_770486692159578473[50] = 1.0;
   out_770486692159578473[51] = 0.0;
   out_770486692159578473[52] = 0.0;
   out_770486692159578473[53] = 0.0;
   out_770486692159578473[54] = 0.0;
   out_770486692159578473[55] = 0.0;
   out_770486692159578473[56] = 0.0;
   out_770486692159578473[57] = 0.0;
   out_770486692159578473[58] = 0.0;
   out_770486692159578473[59] = 0.0;
   out_770486692159578473[60] = 1.0;
   out_770486692159578473[61] = 0.0;
   out_770486692159578473[62] = 0.0;
   out_770486692159578473[63] = 0.0;
   out_770486692159578473[64] = 0.0;
   out_770486692159578473[65] = 0.0;
   out_770486692159578473[66] = 0.0;
   out_770486692159578473[67] = 0.0;
   out_770486692159578473[68] = 0.0;
   out_770486692159578473[69] = 0.0;
   out_770486692159578473[70] = 1.0;
   out_770486692159578473[71] = 0.0;
   out_770486692159578473[72] = 0.0;
   out_770486692159578473[73] = 0.0;
   out_770486692159578473[74] = 0.0;
   out_770486692159578473[75] = 0.0;
   out_770486692159578473[76] = 0.0;
   out_770486692159578473[77] = 0.0;
   out_770486692159578473[78] = 0.0;
   out_770486692159578473[79] = 0.0;
   out_770486692159578473[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_2588187187785096529) {
   out_2588187187785096529[0] = state[0];
   out_2588187187785096529[1] = state[1];
   out_2588187187785096529[2] = state[2];
   out_2588187187785096529[3] = state[3];
   out_2588187187785096529[4] = state[4];
   out_2588187187785096529[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_2588187187785096529[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_2588187187785096529[7] = state[7];
   out_2588187187785096529[8] = state[8];
}
void F_fun(double *state, double dt, double *out_5896136663256409001) {
   out_5896136663256409001[0] = 1;
   out_5896136663256409001[1] = 0;
   out_5896136663256409001[2] = 0;
   out_5896136663256409001[3] = 0;
   out_5896136663256409001[4] = 0;
   out_5896136663256409001[5] = 0;
   out_5896136663256409001[6] = 0;
   out_5896136663256409001[7] = 0;
   out_5896136663256409001[8] = 0;
   out_5896136663256409001[9] = 0;
   out_5896136663256409001[10] = 1;
   out_5896136663256409001[11] = 0;
   out_5896136663256409001[12] = 0;
   out_5896136663256409001[13] = 0;
   out_5896136663256409001[14] = 0;
   out_5896136663256409001[15] = 0;
   out_5896136663256409001[16] = 0;
   out_5896136663256409001[17] = 0;
   out_5896136663256409001[18] = 0;
   out_5896136663256409001[19] = 0;
   out_5896136663256409001[20] = 1;
   out_5896136663256409001[21] = 0;
   out_5896136663256409001[22] = 0;
   out_5896136663256409001[23] = 0;
   out_5896136663256409001[24] = 0;
   out_5896136663256409001[25] = 0;
   out_5896136663256409001[26] = 0;
   out_5896136663256409001[27] = 0;
   out_5896136663256409001[28] = 0;
   out_5896136663256409001[29] = 0;
   out_5896136663256409001[30] = 1;
   out_5896136663256409001[31] = 0;
   out_5896136663256409001[32] = 0;
   out_5896136663256409001[33] = 0;
   out_5896136663256409001[34] = 0;
   out_5896136663256409001[35] = 0;
   out_5896136663256409001[36] = 0;
   out_5896136663256409001[37] = 0;
   out_5896136663256409001[38] = 0;
   out_5896136663256409001[39] = 0;
   out_5896136663256409001[40] = 1;
   out_5896136663256409001[41] = 0;
   out_5896136663256409001[42] = 0;
   out_5896136663256409001[43] = 0;
   out_5896136663256409001[44] = 0;
   out_5896136663256409001[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_5896136663256409001[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_5896136663256409001[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_5896136663256409001[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_5896136663256409001[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_5896136663256409001[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_5896136663256409001[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_5896136663256409001[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_5896136663256409001[53] = -9.8100000000000005*dt;
   out_5896136663256409001[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_5896136663256409001[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_5896136663256409001[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5896136663256409001[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5896136663256409001[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_5896136663256409001[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_5896136663256409001[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_5896136663256409001[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5896136663256409001[62] = 0;
   out_5896136663256409001[63] = 0;
   out_5896136663256409001[64] = 0;
   out_5896136663256409001[65] = 0;
   out_5896136663256409001[66] = 0;
   out_5896136663256409001[67] = 0;
   out_5896136663256409001[68] = 0;
   out_5896136663256409001[69] = 0;
   out_5896136663256409001[70] = 1;
   out_5896136663256409001[71] = 0;
   out_5896136663256409001[72] = 0;
   out_5896136663256409001[73] = 0;
   out_5896136663256409001[74] = 0;
   out_5896136663256409001[75] = 0;
   out_5896136663256409001[76] = 0;
   out_5896136663256409001[77] = 0;
   out_5896136663256409001[78] = 0;
   out_5896136663256409001[79] = 0;
   out_5896136663256409001[80] = 1;
}
void h_25(double *state, double *unused, double *out_37035910800207699) {
   out_37035910800207699[0] = state[6];
}
void H_25(double *state, double *unused, double *out_265152249959281761) {
   out_265152249959281761[0] = 0;
   out_265152249959281761[1] = 0;
   out_265152249959281761[2] = 0;
   out_265152249959281761[3] = 0;
   out_265152249959281761[4] = 0;
   out_265152249959281761[5] = 0;
   out_265152249959281761[6] = 1;
   out_265152249959281761[7] = 0;
   out_265152249959281761[8] = 0;
}
void h_24(double *state, double *unused, double *out_451524429059313537) {
   out_451524429059313537[0] = state[4];
   out_451524429059313537[1] = state[5];
}
void H_24(double *state, double *unused, double *out_7153239383717645132) {
   out_7153239383717645132[0] = 0;
   out_7153239383717645132[1] = 0;
   out_7153239383717645132[2] = 0;
   out_7153239383717645132[3] = 0;
   out_7153239383717645132[4] = 1;
   out_7153239383717645132[5] = 0;
   out_7153239383717645132[6] = 0;
   out_7153239383717645132[7] = 0;
   out_7153239383717645132[8] = 0;
   out_7153239383717645132[9] = 0;
   out_7153239383717645132[10] = 0;
   out_7153239383717645132[11] = 0;
   out_7153239383717645132[12] = 0;
   out_7153239383717645132[13] = 0;
   out_7153239383717645132[14] = 1;
   out_7153239383717645132[15] = 0;
   out_7153239383717645132[16] = 0;
   out_7153239383717645132[17] = 0;
}
void h_30(double *state, double *unused, double *out_6925683045483371328) {
   out_6925683045483371328[0] = state[4];
}
void H_30(double *state, double *unused, double *out_394491197102521831) {
   out_394491197102521831[0] = 0;
   out_394491197102521831[1] = 0;
   out_394491197102521831[2] = 0;
   out_394491197102521831[3] = 0;
   out_394491197102521831[4] = 1;
   out_394491197102521831[5] = 0;
   out_394491197102521831[6] = 0;
   out_394491197102521831[7] = 0;
   out_394491197102521831[8] = 0;
}
void h_26(double *state, double *unused, double *out_2500517615785703846) {
   out_2500517615785703846[0] = state[7];
}
void H_26(double *state, double *unused, double *out_4006655568833337985) {
   out_4006655568833337985[0] = 0;
   out_4006655568833337985[1] = 0;
   out_4006655568833337985[2] = 0;
   out_4006655568833337985[3] = 0;
   out_4006655568833337985[4] = 0;
   out_4006655568833337985[5] = 0;
   out_4006655568833337985[6] = 0;
   out_4006655568833337985[7] = 1;
   out_4006655568833337985[8] = 0;
}
void h_27(double *state, double *unused, double *out_6283486968260381167) {
   out_6283486968260381167[0] = state[3];
}
void H_27(double *state, double *unused, double *out_2569254508902946742) {
   out_2569254508902946742[0] = 0;
   out_2569254508902946742[1] = 0;
   out_2569254508902946742[2] = 0;
   out_2569254508902946742[3] = 1;
   out_2569254508902946742[4] = 0;
   out_2569254508902946742[5] = 0;
   out_2569254508902946742[6] = 0;
   out_2569254508902946742[7] = 0;
   out_2569254508902946742[8] = 0;
}
void h_29(double *state, double *unused, double *out_7986435168816538305) {
   out_7986435168816538305[0] = state[1];
}
void H_29(double *state, double *unused, double *out_115740147211870353) {
   out_115740147211870353[0] = 0;
   out_115740147211870353[1] = 1;
   out_115740147211870353[2] = 0;
   out_115740147211870353[3] = 0;
   out_115740147211870353[4] = 0;
   out_115740147211870353[5] = 0;
   out_115740147211870353[6] = 0;
   out_115740147211870353[7] = 0;
   out_115740147211870353[8] = 0;
}
void h_28(double *state, double *unused, double *out_3903315595626162818) {
   out_3903315595626162818[0] = state[0];
}
void H_28(double *state, double *unused, double *out_2079370418777196604) {
   out_2079370418777196604[0] = 1;
   out_2079370418777196604[1] = 0;
   out_2079370418777196604[2] = 0;
   out_2079370418777196604[3] = 0;
   out_2079370418777196604[4] = 0;
   out_2079370418777196604[5] = 0;
   out_2079370418777196604[6] = 0;
   out_2079370418777196604[7] = 0;
   out_2079370418777196604[8] = 0;
}
void h_31(double *state, double *unused, double *out_1439000368950664667) {
   out_1439000368950664667[0] = state[8];
}
void H_31(double *state, double *unused, double *out_234506288082321333) {
   out_234506288082321333[0] = 0;
   out_234506288082321333[1] = 0;
   out_234506288082321333[2] = 0;
   out_234506288082321333[3] = 0;
   out_234506288082321333[4] = 0;
   out_234506288082321333[5] = 0;
   out_234506288082321333[6] = 0;
   out_234506288082321333[7] = 0;
   out_234506288082321333[8] = 1;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_2640428774147462467) {
  err_fun(nom_x, delta_x, out_2640428774147462467);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_2999667536812604211) {
  inv_err_fun(nom_x, true_x, out_2999667536812604211);
}
void car_H_mod_fun(double *state, double *out_770486692159578473) {
  H_mod_fun(state, out_770486692159578473);
}
void car_f_fun(double *state, double dt, double *out_2588187187785096529) {
  f_fun(state,  dt, out_2588187187785096529);
}
void car_F_fun(double *state, double dt, double *out_5896136663256409001) {
  F_fun(state,  dt, out_5896136663256409001);
}
void car_h_25(double *state, double *unused, double *out_37035910800207699) {
  h_25(state, unused, out_37035910800207699);
}
void car_H_25(double *state, double *unused, double *out_265152249959281761) {
  H_25(state, unused, out_265152249959281761);
}
void car_h_24(double *state, double *unused, double *out_451524429059313537) {
  h_24(state, unused, out_451524429059313537);
}
void car_H_24(double *state, double *unused, double *out_7153239383717645132) {
  H_24(state, unused, out_7153239383717645132);
}
void car_h_30(double *state, double *unused, double *out_6925683045483371328) {
  h_30(state, unused, out_6925683045483371328);
}
void car_H_30(double *state, double *unused, double *out_394491197102521831) {
  H_30(state, unused, out_394491197102521831);
}
void car_h_26(double *state, double *unused, double *out_2500517615785703846) {
  h_26(state, unused, out_2500517615785703846);
}
void car_H_26(double *state, double *unused, double *out_4006655568833337985) {
  H_26(state, unused, out_4006655568833337985);
}
void car_h_27(double *state, double *unused, double *out_6283486968260381167) {
  h_27(state, unused, out_6283486968260381167);
}
void car_H_27(double *state, double *unused, double *out_2569254508902946742) {
  H_27(state, unused, out_2569254508902946742);
}
void car_h_29(double *state, double *unused, double *out_7986435168816538305) {
  h_29(state, unused, out_7986435168816538305);
}
void car_H_29(double *state, double *unused, double *out_115740147211870353) {
  H_29(state, unused, out_115740147211870353);
}
void car_h_28(double *state, double *unused, double *out_3903315595626162818) {
  h_28(state, unused, out_3903315595626162818);
}
void car_H_28(double *state, double *unused, double *out_2079370418777196604) {
  H_28(state, unused, out_2079370418777196604);
}
void car_h_31(double *state, double *unused, double *out_1439000368950664667) {
  h_31(state, unused, out_1439000368950664667);
}
void car_H_31(double *state, double *unused, double *out_234506288082321333) {
  H_31(state, unused, out_234506288082321333);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
