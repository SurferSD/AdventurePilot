#include "pose.h"

namespace {
#define DIM 18
#define EDIM 18
#define MEDIM 18
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_4 = 7.814727903251177;
const static double MAHA_THRESH_10 = 7.814727903251177;
const static double MAHA_THRESH_13 = 7.814727903251177;
const static double MAHA_THRESH_14 = 7.814727903251177;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_4596150727177448991) {
   out_4596150727177448991[0] = delta_x[0] + nom_x[0];
   out_4596150727177448991[1] = delta_x[1] + nom_x[1];
   out_4596150727177448991[2] = delta_x[2] + nom_x[2];
   out_4596150727177448991[3] = delta_x[3] + nom_x[3];
   out_4596150727177448991[4] = delta_x[4] + nom_x[4];
   out_4596150727177448991[5] = delta_x[5] + nom_x[5];
   out_4596150727177448991[6] = delta_x[6] + nom_x[6];
   out_4596150727177448991[7] = delta_x[7] + nom_x[7];
   out_4596150727177448991[8] = delta_x[8] + nom_x[8];
   out_4596150727177448991[9] = delta_x[9] + nom_x[9];
   out_4596150727177448991[10] = delta_x[10] + nom_x[10];
   out_4596150727177448991[11] = delta_x[11] + nom_x[11];
   out_4596150727177448991[12] = delta_x[12] + nom_x[12];
   out_4596150727177448991[13] = delta_x[13] + nom_x[13];
   out_4596150727177448991[14] = delta_x[14] + nom_x[14];
   out_4596150727177448991[15] = delta_x[15] + nom_x[15];
   out_4596150727177448991[16] = delta_x[16] + nom_x[16];
   out_4596150727177448991[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_5311469374371571464) {
   out_5311469374371571464[0] = -nom_x[0] + true_x[0];
   out_5311469374371571464[1] = -nom_x[1] + true_x[1];
   out_5311469374371571464[2] = -nom_x[2] + true_x[2];
   out_5311469374371571464[3] = -nom_x[3] + true_x[3];
   out_5311469374371571464[4] = -nom_x[4] + true_x[4];
   out_5311469374371571464[5] = -nom_x[5] + true_x[5];
   out_5311469374371571464[6] = -nom_x[6] + true_x[6];
   out_5311469374371571464[7] = -nom_x[7] + true_x[7];
   out_5311469374371571464[8] = -nom_x[8] + true_x[8];
   out_5311469374371571464[9] = -nom_x[9] + true_x[9];
   out_5311469374371571464[10] = -nom_x[10] + true_x[10];
   out_5311469374371571464[11] = -nom_x[11] + true_x[11];
   out_5311469374371571464[12] = -nom_x[12] + true_x[12];
   out_5311469374371571464[13] = -nom_x[13] + true_x[13];
   out_5311469374371571464[14] = -nom_x[14] + true_x[14];
   out_5311469374371571464[15] = -nom_x[15] + true_x[15];
   out_5311469374371571464[16] = -nom_x[16] + true_x[16];
   out_5311469374371571464[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_8767003866676733322) {
   out_8767003866676733322[0] = 1.0;
   out_8767003866676733322[1] = 0.0;
   out_8767003866676733322[2] = 0.0;
   out_8767003866676733322[3] = 0.0;
   out_8767003866676733322[4] = 0.0;
   out_8767003866676733322[5] = 0.0;
   out_8767003866676733322[6] = 0.0;
   out_8767003866676733322[7] = 0.0;
   out_8767003866676733322[8] = 0.0;
   out_8767003866676733322[9] = 0.0;
   out_8767003866676733322[10] = 0.0;
   out_8767003866676733322[11] = 0.0;
   out_8767003866676733322[12] = 0.0;
   out_8767003866676733322[13] = 0.0;
   out_8767003866676733322[14] = 0.0;
   out_8767003866676733322[15] = 0.0;
   out_8767003866676733322[16] = 0.0;
   out_8767003866676733322[17] = 0.0;
   out_8767003866676733322[18] = 0.0;
   out_8767003866676733322[19] = 1.0;
   out_8767003866676733322[20] = 0.0;
   out_8767003866676733322[21] = 0.0;
   out_8767003866676733322[22] = 0.0;
   out_8767003866676733322[23] = 0.0;
   out_8767003866676733322[24] = 0.0;
   out_8767003866676733322[25] = 0.0;
   out_8767003866676733322[26] = 0.0;
   out_8767003866676733322[27] = 0.0;
   out_8767003866676733322[28] = 0.0;
   out_8767003866676733322[29] = 0.0;
   out_8767003866676733322[30] = 0.0;
   out_8767003866676733322[31] = 0.0;
   out_8767003866676733322[32] = 0.0;
   out_8767003866676733322[33] = 0.0;
   out_8767003866676733322[34] = 0.0;
   out_8767003866676733322[35] = 0.0;
   out_8767003866676733322[36] = 0.0;
   out_8767003866676733322[37] = 0.0;
   out_8767003866676733322[38] = 1.0;
   out_8767003866676733322[39] = 0.0;
   out_8767003866676733322[40] = 0.0;
   out_8767003866676733322[41] = 0.0;
   out_8767003866676733322[42] = 0.0;
   out_8767003866676733322[43] = 0.0;
   out_8767003866676733322[44] = 0.0;
   out_8767003866676733322[45] = 0.0;
   out_8767003866676733322[46] = 0.0;
   out_8767003866676733322[47] = 0.0;
   out_8767003866676733322[48] = 0.0;
   out_8767003866676733322[49] = 0.0;
   out_8767003866676733322[50] = 0.0;
   out_8767003866676733322[51] = 0.0;
   out_8767003866676733322[52] = 0.0;
   out_8767003866676733322[53] = 0.0;
   out_8767003866676733322[54] = 0.0;
   out_8767003866676733322[55] = 0.0;
   out_8767003866676733322[56] = 0.0;
   out_8767003866676733322[57] = 1.0;
   out_8767003866676733322[58] = 0.0;
   out_8767003866676733322[59] = 0.0;
   out_8767003866676733322[60] = 0.0;
   out_8767003866676733322[61] = 0.0;
   out_8767003866676733322[62] = 0.0;
   out_8767003866676733322[63] = 0.0;
   out_8767003866676733322[64] = 0.0;
   out_8767003866676733322[65] = 0.0;
   out_8767003866676733322[66] = 0.0;
   out_8767003866676733322[67] = 0.0;
   out_8767003866676733322[68] = 0.0;
   out_8767003866676733322[69] = 0.0;
   out_8767003866676733322[70] = 0.0;
   out_8767003866676733322[71] = 0.0;
   out_8767003866676733322[72] = 0.0;
   out_8767003866676733322[73] = 0.0;
   out_8767003866676733322[74] = 0.0;
   out_8767003866676733322[75] = 0.0;
   out_8767003866676733322[76] = 1.0;
   out_8767003866676733322[77] = 0.0;
   out_8767003866676733322[78] = 0.0;
   out_8767003866676733322[79] = 0.0;
   out_8767003866676733322[80] = 0.0;
   out_8767003866676733322[81] = 0.0;
   out_8767003866676733322[82] = 0.0;
   out_8767003866676733322[83] = 0.0;
   out_8767003866676733322[84] = 0.0;
   out_8767003866676733322[85] = 0.0;
   out_8767003866676733322[86] = 0.0;
   out_8767003866676733322[87] = 0.0;
   out_8767003866676733322[88] = 0.0;
   out_8767003866676733322[89] = 0.0;
   out_8767003866676733322[90] = 0.0;
   out_8767003866676733322[91] = 0.0;
   out_8767003866676733322[92] = 0.0;
   out_8767003866676733322[93] = 0.0;
   out_8767003866676733322[94] = 0.0;
   out_8767003866676733322[95] = 1.0;
   out_8767003866676733322[96] = 0.0;
   out_8767003866676733322[97] = 0.0;
   out_8767003866676733322[98] = 0.0;
   out_8767003866676733322[99] = 0.0;
   out_8767003866676733322[100] = 0.0;
   out_8767003866676733322[101] = 0.0;
   out_8767003866676733322[102] = 0.0;
   out_8767003866676733322[103] = 0.0;
   out_8767003866676733322[104] = 0.0;
   out_8767003866676733322[105] = 0.0;
   out_8767003866676733322[106] = 0.0;
   out_8767003866676733322[107] = 0.0;
   out_8767003866676733322[108] = 0.0;
   out_8767003866676733322[109] = 0.0;
   out_8767003866676733322[110] = 0.0;
   out_8767003866676733322[111] = 0.0;
   out_8767003866676733322[112] = 0.0;
   out_8767003866676733322[113] = 0.0;
   out_8767003866676733322[114] = 1.0;
   out_8767003866676733322[115] = 0.0;
   out_8767003866676733322[116] = 0.0;
   out_8767003866676733322[117] = 0.0;
   out_8767003866676733322[118] = 0.0;
   out_8767003866676733322[119] = 0.0;
   out_8767003866676733322[120] = 0.0;
   out_8767003866676733322[121] = 0.0;
   out_8767003866676733322[122] = 0.0;
   out_8767003866676733322[123] = 0.0;
   out_8767003866676733322[124] = 0.0;
   out_8767003866676733322[125] = 0.0;
   out_8767003866676733322[126] = 0.0;
   out_8767003866676733322[127] = 0.0;
   out_8767003866676733322[128] = 0.0;
   out_8767003866676733322[129] = 0.0;
   out_8767003866676733322[130] = 0.0;
   out_8767003866676733322[131] = 0.0;
   out_8767003866676733322[132] = 0.0;
   out_8767003866676733322[133] = 1.0;
   out_8767003866676733322[134] = 0.0;
   out_8767003866676733322[135] = 0.0;
   out_8767003866676733322[136] = 0.0;
   out_8767003866676733322[137] = 0.0;
   out_8767003866676733322[138] = 0.0;
   out_8767003866676733322[139] = 0.0;
   out_8767003866676733322[140] = 0.0;
   out_8767003866676733322[141] = 0.0;
   out_8767003866676733322[142] = 0.0;
   out_8767003866676733322[143] = 0.0;
   out_8767003866676733322[144] = 0.0;
   out_8767003866676733322[145] = 0.0;
   out_8767003866676733322[146] = 0.0;
   out_8767003866676733322[147] = 0.0;
   out_8767003866676733322[148] = 0.0;
   out_8767003866676733322[149] = 0.0;
   out_8767003866676733322[150] = 0.0;
   out_8767003866676733322[151] = 0.0;
   out_8767003866676733322[152] = 1.0;
   out_8767003866676733322[153] = 0.0;
   out_8767003866676733322[154] = 0.0;
   out_8767003866676733322[155] = 0.0;
   out_8767003866676733322[156] = 0.0;
   out_8767003866676733322[157] = 0.0;
   out_8767003866676733322[158] = 0.0;
   out_8767003866676733322[159] = 0.0;
   out_8767003866676733322[160] = 0.0;
   out_8767003866676733322[161] = 0.0;
   out_8767003866676733322[162] = 0.0;
   out_8767003866676733322[163] = 0.0;
   out_8767003866676733322[164] = 0.0;
   out_8767003866676733322[165] = 0.0;
   out_8767003866676733322[166] = 0.0;
   out_8767003866676733322[167] = 0.0;
   out_8767003866676733322[168] = 0.0;
   out_8767003866676733322[169] = 0.0;
   out_8767003866676733322[170] = 0.0;
   out_8767003866676733322[171] = 1.0;
   out_8767003866676733322[172] = 0.0;
   out_8767003866676733322[173] = 0.0;
   out_8767003866676733322[174] = 0.0;
   out_8767003866676733322[175] = 0.0;
   out_8767003866676733322[176] = 0.0;
   out_8767003866676733322[177] = 0.0;
   out_8767003866676733322[178] = 0.0;
   out_8767003866676733322[179] = 0.0;
   out_8767003866676733322[180] = 0.0;
   out_8767003866676733322[181] = 0.0;
   out_8767003866676733322[182] = 0.0;
   out_8767003866676733322[183] = 0.0;
   out_8767003866676733322[184] = 0.0;
   out_8767003866676733322[185] = 0.0;
   out_8767003866676733322[186] = 0.0;
   out_8767003866676733322[187] = 0.0;
   out_8767003866676733322[188] = 0.0;
   out_8767003866676733322[189] = 0.0;
   out_8767003866676733322[190] = 1.0;
   out_8767003866676733322[191] = 0.0;
   out_8767003866676733322[192] = 0.0;
   out_8767003866676733322[193] = 0.0;
   out_8767003866676733322[194] = 0.0;
   out_8767003866676733322[195] = 0.0;
   out_8767003866676733322[196] = 0.0;
   out_8767003866676733322[197] = 0.0;
   out_8767003866676733322[198] = 0.0;
   out_8767003866676733322[199] = 0.0;
   out_8767003866676733322[200] = 0.0;
   out_8767003866676733322[201] = 0.0;
   out_8767003866676733322[202] = 0.0;
   out_8767003866676733322[203] = 0.0;
   out_8767003866676733322[204] = 0.0;
   out_8767003866676733322[205] = 0.0;
   out_8767003866676733322[206] = 0.0;
   out_8767003866676733322[207] = 0.0;
   out_8767003866676733322[208] = 0.0;
   out_8767003866676733322[209] = 1.0;
   out_8767003866676733322[210] = 0.0;
   out_8767003866676733322[211] = 0.0;
   out_8767003866676733322[212] = 0.0;
   out_8767003866676733322[213] = 0.0;
   out_8767003866676733322[214] = 0.0;
   out_8767003866676733322[215] = 0.0;
   out_8767003866676733322[216] = 0.0;
   out_8767003866676733322[217] = 0.0;
   out_8767003866676733322[218] = 0.0;
   out_8767003866676733322[219] = 0.0;
   out_8767003866676733322[220] = 0.0;
   out_8767003866676733322[221] = 0.0;
   out_8767003866676733322[222] = 0.0;
   out_8767003866676733322[223] = 0.0;
   out_8767003866676733322[224] = 0.0;
   out_8767003866676733322[225] = 0.0;
   out_8767003866676733322[226] = 0.0;
   out_8767003866676733322[227] = 0.0;
   out_8767003866676733322[228] = 1.0;
   out_8767003866676733322[229] = 0.0;
   out_8767003866676733322[230] = 0.0;
   out_8767003866676733322[231] = 0.0;
   out_8767003866676733322[232] = 0.0;
   out_8767003866676733322[233] = 0.0;
   out_8767003866676733322[234] = 0.0;
   out_8767003866676733322[235] = 0.0;
   out_8767003866676733322[236] = 0.0;
   out_8767003866676733322[237] = 0.0;
   out_8767003866676733322[238] = 0.0;
   out_8767003866676733322[239] = 0.0;
   out_8767003866676733322[240] = 0.0;
   out_8767003866676733322[241] = 0.0;
   out_8767003866676733322[242] = 0.0;
   out_8767003866676733322[243] = 0.0;
   out_8767003866676733322[244] = 0.0;
   out_8767003866676733322[245] = 0.0;
   out_8767003866676733322[246] = 0.0;
   out_8767003866676733322[247] = 1.0;
   out_8767003866676733322[248] = 0.0;
   out_8767003866676733322[249] = 0.0;
   out_8767003866676733322[250] = 0.0;
   out_8767003866676733322[251] = 0.0;
   out_8767003866676733322[252] = 0.0;
   out_8767003866676733322[253] = 0.0;
   out_8767003866676733322[254] = 0.0;
   out_8767003866676733322[255] = 0.0;
   out_8767003866676733322[256] = 0.0;
   out_8767003866676733322[257] = 0.0;
   out_8767003866676733322[258] = 0.0;
   out_8767003866676733322[259] = 0.0;
   out_8767003866676733322[260] = 0.0;
   out_8767003866676733322[261] = 0.0;
   out_8767003866676733322[262] = 0.0;
   out_8767003866676733322[263] = 0.0;
   out_8767003866676733322[264] = 0.0;
   out_8767003866676733322[265] = 0.0;
   out_8767003866676733322[266] = 1.0;
   out_8767003866676733322[267] = 0.0;
   out_8767003866676733322[268] = 0.0;
   out_8767003866676733322[269] = 0.0;
   out_8767003866676733322[270] = 0.0;
   out_8767003866676733322[271] = 0.0;
   out_8767003866676733322[272] = 0.0;
   out_8767003866676733322[273] = 0.0;
   out_8767003866676733322[274] = 0.0;
   out_8767003866676733322[275] = 0.0;
   out_8767003866676733322[276] = 0.0;
   out_8767003866676733322[277] = 0.0;
   out_8767003866676733322[278] = 0.0;
   out_8767003866676733322[279] = 0.0;
   out_8767003866676733322[280] = 0.0;
   out_8767003866676733322[281] = 0.0;
   out_8767003866676733322[282] = 0.0;
   out_8767003866676733322[283] = 0.0;
   out_8767003866676733322[284] = 0.0;
   out_8767003866676733322[285] = 1.0;
   out_8767003866676733322[286] = 0.0;
   out_8767003866676733322[287] = 0.0;
   out_8767003866676733322[288] = 0.0;
   out_8767003866676733322[289] = 0.0;
   out_8767003866676733322[290] = 0.0;
   out_8767003866676733322[291] = 0.0;
   out_8767003866676733322[292] = 0.0;
   out_8767003866676733322[293] = 0.0;
   out_8767003866676733322[294] = 0.0;
   out_8767003866676733322[295] = 0.0;
   out_8767003866676733322[296] = 0.0;
   out_8767003866676733322[297] = 0.0;
   out_8767003866676733322[298] = 0.0;
   out_8767003866676733322[299] = 0.0;
   out_8767003866676733322[300] = 0.0;
   out_8767003866676733322[301] = 0.0;
   out_8767003866676733322[302] = 0.0;
   out_8767003866676733322[303] = 0.0;
   out_8767003866676733322[304] = 1.0;
   out_8767003866676733322[305] = 0.0;
   out_8767003866676733322[306] = 0.0;
   out_8767003866676733322[307] = 0.0;
   out_8767003866676733322[308] = 0.0;
   out_8767003866676733322[309] = 0.0;
   out_8767003866676733322[310] = 0.0;
   out_8767003866676733322[311] = 0.0;
   out_8767003866676733322[312] = 0.0;
   out_8767003866676733322[313] = 0.0;
   out_8767003866676733322[314] = 0.0;
   out_8767003866676733322[315] = 0.0;
   out_8767003866676733322[316] = 0.0;
   out_8767003866676733322[317] = 0.0;
   out_8767003866676733322[318] = 0.0;
   out_8767003866676733322[319] = 0.0;
   out_8767003866676733322[320] = 0.0;
   out_8767003866676733322[321] = 0.0;
   out_8767003866676733322[322] = 0.0;
   out_8767003866676733322[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_2459657190356119743) {
   out_2459657190356119743[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_2459657190356119743[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_2459657190356119743[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_2459657190356119743[3] = dt*state[12] + state[3];
   out_2459657190356119743[4] = dt*state[13] + state[4];
   out_2459657190356119743[5] = dt*state[14] + state[5];
   out_2459657190356119743[6] = state[6];
   out_2459657190356119743[7] = state[7];
   out_2459657190356119743[8] = state[8];
   out_2459657190356119743[9] = state[9];
   out_2459657190356119743[10] = state[10];
   out_2459657190356119743[11] = state[11];
   out_2459657190356119743[12] = state[12];
   out_2459657190356119743[13] = state[13];
   out_2459657190356119743[14] = state[14];
   out_2459657190356119743[15] = state[15];
   out_2459657190356119743[16] = state[16];
   out_2459657190356119743[17] = state[17];
}
void F_fun(double *state, double dt, double *out_6577442919905546465) {
   out_6577442919905546465[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6577442919905546465[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6577442919905546465[2] = 0;
   out_6577442919905546465[3] = 0;
   out_6577442919905546465[4] = 0;
   out_6577442919905546465[5] = 0;
   out_6577442919905546465[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6577442919905546465[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6577442919905546465[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6577442919905546465[9] = 0;
   out_6577442919905546465[10] = 0;
   out_6577442919905546465[11] = 0;
   out_6577442919905546465[12] = 0;
   out_6577442919905546465[13] = 0;
   out_6577442919905546465[14] = 0;
   out_6577442919905546465[15] = 0;
   out_6577442919905546465[16] = 0;
   out_6577442919905546465[17] = 0;
   out_6577442919905546465[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6577442919905546465[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6577442919905546465[20] = 0;
   out_6577442919905546465[21] = 0;
   out_6577442919905546465[22] = 0;
   out_6577442919905546465[23] = 0;
   out_6577442919905546465[24] = 0;
   out_6577442919905546465[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6577442919905546465[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6577442919905546465[27] = 0;
   out_6577442919905546465[28] = 0;
   out_6577442919905546465[29] = 0;
   out_6577442919905546465[30] = 0;
   out_6577442919905546465[31] = 0;
   out_6577442919905546465[32] = 0;
   out_6577442919905546465[33] = 0;
   out_6577442919905546465[34] = 0;
   out_6577442919905546465[35] = 0;
   out_6577442919905546465[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6577442919905546465[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6577442919905546465[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6577442919905546465[39] = 0;
   out_6577442919905546465[40] = 0;
   out_6577442919905546465[41] = 0;
   out_6577442919905546465[42] = 0;
   out_6577442919905546465[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6577442919905546465[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6577442919905546465[45] = 0;
   out_6577442919905546465[46] = 0;
   out_6577442919905546465[47] = 0;
   out_6577442919905546465[48] = 0;
   out_6577442919905546465[49] = 0;
   out_6577442919905546465[50] = 0;
   out_6577442919905546465[51] = 0;
   out_6577442919905546465[52] = 0;
   out_6577442919905546465[53] = 0;
   out_6577442919905546465[54] = 0;
   out_6577442919905546465[55] = 0;
   out_6577442919905546465[56] = 0;
   out_6577442919905546465[57] = 1;
   out_6577442919905546465[58] = 0;
   out_6577442919905546465[59] = 0;
   out_6577442919905546465[60] = 0;
   out_6577442919905546465[61] = 0;
   out_6577442919905546465[62] = 0;
   out_6577442919905546465[63] = 0;
   out_6577442919905546465[64] = 0;
   out_6577442919905546465[65] = 0;
   out_6577442919905546465[66] = dt;
   out_6577442919905546465[67] = 0;
   out_6577442919905546465[68] = 0;
   out_6577442919905546465[69] = 0;
   out_6577442919905546465[70] = 0;
   out_6577442919905546465[71] = 0;
   out_6577442919905546465[72] = 0;
   out_6577442919905546465[73] = 0;
   out_6577442919905546465[74] = 0;
   out_6577442919905546465[75] = 0;
   out_6577442919905546465[76] = 1;
   out_6577442919905546465[77] = 0;
   out_6577442919905546465[78] = 0;
   out_6577442919905546465[79] = 0;
   out_6577442919905546465[80] = 0;
   out_6577442919905546465[81] = 0;
   out_6577442919905546465[82] = 0;
   out_6577442919905546465[83] = 0;
   out_6577442919905546465[84] = 0;
   out_6577442919905546465[85] = dt;
   out_6577442919905546465[86] = 0;
   out_6577442919905546465[87] = 0;
   out_6577442919905546465[88] = 0;
   out_6577442919905546465[89] = 0;
   out_6577442919905546465[90] = 0;
   out_6577442919905546465[91] = 0;
   out_6577442919905546465[92] = 0;
   out_6577442919905546465[93] = 0;
   out_6577442919905546465[94] = 0;
   out_6577442919905546465[95] = 1;
   out_6577442919905546465[96] = 0;
   out_6577442919905546465[97] = 0;
   out_6577442919905546465[98] = 0;
   out_6577442919905546465[99] = 0;
   out_6577442919905546465[100] = 0;
   out_6577442919905546465[101] = 0;
   out_6577442919905546465[102] = 0;
   out_6577442919905546465[103] = 0;
   out_6577442919905546465[104] = dt;
   out_6577442919905546465[105] = 0;
   out_6577442919905546465[106] = 0;
   out_6577442919905546465[107] = 0;
   out_6577442919905546465[108] = 0;
   out_6577442919905546465[109] = 0;
   out_6577442919905546465[110] = 0;
   out_6577442919905546465[111] = 0;
   out_6577442919905546465[112] = 0;
   out_6577442919905546465[113] = 0;
   out_6577442919905546465[114] = 1;
   out_6577442919905546465[115] = 0;
   out_6577442919905546465[116] = 0;
   out_6577442919905546465[117] = 0;
   out_6577442919905546465[118] = 0;
   out_6577442919905546465[119] = 0;
   out_6577442919905546465[120] = 0;
   out_6577442919905546465[121] = 0;
   out_6577442919905546465[122] = 0;
   out_6577442919905546465[123] = 0;
   out_6577442919905546465[124] = 0;
   out_6577442919905546465[125] = 0;
   out_6577442919905546465[126] = 0;
   out_6577442919905546465[127] = 0;
   out_6577442919905546465[128] = 0;
   out_6577442919905546465[129] = 0;
   out_6577442919905546465[130] = 0;
   out_6577442919905546465[131] = 0;
   out_6577442919905546465[132] = 0;
   out_6577442919905546465[133] = 1;
   out_6577442919905546465[134] = 0;
   out_6577442919905546465[135] = 0;
   out_6577442919905546465[136] = 0;
   out_6577442919905546465[137] = 0;
   out_6577442919905546465[138] = 0;
   out_6577442919905546465[139] = 0;
   out_6577442919905546465[140] = 0;
   out_6577442919905546465[141] = 0;
   out_6577442919905546465[142] = 0;
   out_6577442919905546465[143] = 0;
   out_6577442919905546465[144] = 0;
   out_6577442919905546465[145] = 0;
   out_6577442919905546465[146] = 0;
   out_6577442919905546465[147] = 0;
   out_6577442919905546465[148] = 0;
   out_6577442919905546465[149] = 0;
   out_6577442919905546465[150] = 0;
   out_6577442919905546465[151] = 0;
   out_6577442919905546465[152] = 1;
   out_6577442919905546465[153] = 0;
   out_6577442919905546465[154] = 0;
   out_6577442919905546465[155] = 0;
   out_6577442919905546465[156] = 0;
   out_6577442919905546465[157] = 0;
   out_6577442919905546465[158] = 0;
   out_6577442919905546465[159] = 0;
   out_6577442919905546465[160] = 0;
   out_6577442919905546465[161] = 0;
   out_6577442919905546465[162] = 0;
   out_6577442919905546465[163] = 0;
   out_6577442919905546465[164] = 0;
   out_6577442919905546465[165] = 0;
   out_6577442919905546465[166] = 0;
   out_6577442919905546465[167] = 0;
   out_6577442919905546465[168] = 0;
   out_6577442919905546465[169] = 0;
   out_6577442919905546465[170] = 0;
   out_6577442919905546465[171] = 1;
   out_6577442919905546465[172] = 0;
   out_6577442919905546465[173] = 0;
   out_6577442919905546465[174] = 0;
   out_6577442919905546465[175] = 0;
   out_6577442919905546465[176] = 0;
   out_6577442919905546465[177] = 0;
   out_6577442919905546465[178] = 0;
   out_6577442919905546465[179] = 0;
   out_6577442919905546465[180] = 0;
   out_6577442919905546465[181] = 0;
   out_6577442919905546465[182] = 0;
   out_6577442919905546465[183] = 0;
   out_6577442919905546465[184] = 0;
   out_6577442919905546465[185] = 0;
   out_6577442919905546465[186] = 0;
   out_6577442919905546465[187] = 0;
   out_6577442919905546465[188] = 0;
   out_6577442919905546465[189] = 0;
   out_6577442919905546465[190] = 1;
   out_6577442919905546465[191] = 0;
   out_6577442919905546465[192] = 0;
   out_6577442919905546465[193] = 0;
   out_6577442919905546465[194] = 0;
   out_6577442919905546465[195] = 0;
   out_6577442919905546465[196] = 0;
   out_6577442919905546465[197] = 0;
   out_6577442919905546465[198] = 0;
   out_6577442919905546465[199] = 0;
   out_6577442919905546465[200] = 0;
   out_6577442919905546465[201] = 0;
   out_6577442919905546465[202] = 0;
   out_6577442919905546465[203] = 0;
   out_6577442919905546465[204] = 0;
   out_6577442919905546465[205] = 0;
   out_6577442919905546465[206] = 0;
   out_6577442919905546465[207] = 0;
   out_6577442919905546465[208] = 0;
   out_6577442919905546465[209] = 1;
   out_6577442919905546465[210] = 0;
   out_6577442919905546465[211] = 0;
   out_6577442919905546465[212] = 0;
   out_6577442919905546465[213] = 0;
   out_6577442919905546465[214] = 0;
   out_6577442919905546465[215] = 0;
   out_6577442919905546465[216] = 0;
   out_6577442919905546465[217] = 0;
   out_6577442919905546465[218] = 0;
   out_6577442919905546465[219] = 0;
   out_6577442919905546465[220] = 0;
   out_6577442919905546465[221] = 0;
   out_6577442919905546465[222] = 0;
   out_6577442919905546465[223] = 0;
   out_6577442919905546465[224] = 0;
   out_6577442919905546465[225] = 0;
   out_6577442919905546465[226] = 0;
   out_6577442919905546465[227] = 0;
   out_6577442919905546465[228] = 1;
   out_6577442919905546465[229] = 0;
   out_6577442919905546465[230] = 0;
   out_6577442919905546465[231] = 0;
   out_6577442919905546465[232] = 0;
   out_6577442919905546465[233] = 0;
   out_6577442919905546465[234] = 0;
   out_6577442919905546465[235] = 0;
   out_6577442919905546465[236] = 0;
   out_6577442919905546465[237] = 0;
   out_6577442919905546465[238] = 0;
   out_6577442919905546465[239] = 0;
   out_6577442919905546465[240] = 0;
   out_6577442919905546465[241] = 0;
   out_6577442919905546465[242] = 0;
   out_6577442919905546465[243] = 0;
   out_6577442919905546465[244] = 0;
   out_6577442919905546465[245] = 0;
   out_6577442919905546465[246] = 0;
   out_6577442919905546465[247] = 1;
   out_6577442919905546465[248] = 0;
   out_6577442919905546465[249] = 0;
   out_6577442919905546465[250] = 0;
   out_6577442919905546465[251] = 0;
   out_6577442919905546465[252] = 0;
   out_6577442919905546465[253] = 0;
   out_6577442919905546465[254] = 0;
   out_6577442919905546465[255] = 0;
   out_6577442919905546465[256] = 0;
   out_6577442919905546465[257] = 0;
   out_6577442919905546465[258] = 0;
   out_6577442919905546465[259] = 0;
   out_6577442919905546465[260] = 0;
   out_6577442919905546465[261] = 0;
   out_6577442919905546465[262] = 0;
   out_6577442919905546465[263] = 0;
   out_6577442919905546465[264] = 0;
   out_6577442919905546465[265] = 0;
   out_6577442919905546465[266] = 1;
   out_6577442919905546465[267] = 0;
   out_6577442919905546465[268] = 0;
   out_6577442919905546465[269] = 0;
   out_6577442919905546465[270] = 0;
   out_6577442919905546465[271] = 0;
   out_6577442919905546465[272] = 0;
   out_6577442919905546465[273] = 0;
   out_6577442919905546465[274] = 0;
   out_6577442919905546465[275] = 0;
   out_6577442919905546465[276] = 0;
   out_6577442919905546465[277] = 0;
   out_6577442919905546465[278] = 0;
   out_6577442919905546465[279] = 0;
   out_6577442919905546465[280] = 0;
   out_6577442919905546465[281] = 0;
   out_6577442919905546465[282] = 0;
   out_6577442919905546465[283] = 0;
   out_6577442919905546465[284] = 0;
   out_6577442919905546465[285] = 1;
   out_6577442919905546465[286] = 0;
   out_6577442919905546465[287] = 0;
   out_6577442919905546465[288] = 0;
   out_6577442919905546465[289] = 0;
   out_6577442919905546465[290] = 0;
   out_6577442919905546465[291] = 0;
   out_6577442919905546465[292] = 0;
   out_6577442919905546465[293] = 0;
   out_6577442919905546465[294] = 0;
   out_6577442919905546465[295] = 0;
   out_6577442919905546465[296] = 0;
   out_6577442919905546465[297] = 0;
   out_6577442919905546465[298] = 0;
   out_6577442919905546465[299] = 0;
   out_6577442919905546465[300] = 0;
   out_6577442919905546465[301] = 0;
   out_6577442919905546465[302] = 0;
   out_6577442919905546465[303] = 0;
   out_6577442919905546465[304] = 1;
   out_6577442919905546465[305] = 0;
   out_6577442919905546465[306] = 0;
   out_6577442919905546465[307] = 0;
   out_6577442919905546465[308] = 0;
   out_6577442919905546465[309] = 0;
   out_6577442919905546465[310] = 0;
   out_6577442919905546465[311] = 0;
   out_6577442919905546465[312] = 0;
   out_6577442919905546465[313] = 0;
   out_6577442919905546465[314] = 0;
   out_6577442919905546465[315] = 0;
   out_6577442919905546465[316] = 0;
   out_6577442919905546465[317] = 0;
   out_6577442919905546465[318] = 0;
   out_6577442919905546465[319] = 0;
   out_6577442919905546465[320] = 0;
   out_6577442919905546465[321] = 0;
   out_6577442919905546465[322] = 0;
   out_6577442919905546465[323] = 1;
}
void h_4(double *state, double *unused, double *out_7087470237745846386) {
   out_7087470237745846386[0] = state[6] + state[9];
   out_7087470237745846386[1] = state[7] + state[10];
   out_7087470237745846386[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_8925579204978105687) {
   out_8925579204978105687[0] = 0;
   out_8925579204978105687[1] = 0;
   out_8925579204978105687[2] = 0;
   out_8925579204978105687[3] = 0;
   out_8925579204978105687[4] = 0;
   out_8925579204978105687[5] = 0;
   out_8925579204978105687[6] = 1;
   out_8925579204978105687[7] = 0;
   out_8925579204978105687[8] = 0;
   out_8925579204978105687[9] = 1;
   out_8925579204978105687[10] = 0;
   out_8925579204978105687[11] = 0;
   out_8925579204978105687[12] = 0;
   out_8925579204978105687[13] = 0;
   out_8925579204978105687[14] = 0;
   out_8925579204978105687[15] = 0;
   out_8925579204978105687[16] = 0;
   out_8925579204978105687[17] = 0;
   out_8925579204978105687[18] = 0;
   out_8925579204978105687[19] = 0;
   out_8925579204978105687[20] = 0;
   out_8925579204978105687[21] = 0;
   out_8925579204978105687[22] = 0;
   out_8925579204978105687[23] = 0;
   out_8925579204978105687[24] = 0;
   out_8925579204978105687[25] = 1;
   out_8925579204978105687[26] = 0;
   out_8925579204978105687[27] = 0;
   out_8925579204978105687[28] = 1;
   out_8925579204978105687[29] = 0;
   out_8925579204978105687[30] = 0;
   out_8925579204978105687[31] = 0;
   out_8925579204978105687[32] = 0;
   out_8925579204978105687[33] = 0;
   out_8925579204978105687[34] = 0;
   out_8925579204978105687[35] = 0;
   out_8925579204978105687[36] = 0;
   out_8925579204978105687[37] = 0;
   out_8925579204978105687[38] = 0;
   out_8925579204978105687[39] = 0;
   out_8925579204978105687[40] = 0;
   out_8925579204978105687[41] = 0;
   out_8925579204978105687[42] = 0;
   out_8925579204978105687[43] = 0;
   out_8925579204978105687[44] = 1;
   out_8925579204978105687[45] = 0;
   out_8925579204978105687[46] = 0;
   out_8925579204978105687[47] = 1;
   out_8925579204978105687[48] = 0;
   out_8925579204978105687[49] = 0;
   out_8925579204978105687[50] = 0;
   out_8925579204978105687[51] = 0;
   out_8925579204978105687[52] = 0;
   out_8925579204978105687[53] = 0;
}
void h_10(double *state, double *unused, double *out_6226154528069596479) {
   out_6226154528069596479[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_6226154528069596479[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_6226154528069596479[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_4349080714290348357) {
   out_4349080714290348357[0] = 0;
   out_4349080714290348357[1] = 9.8100000000000005*cos(state[1]);
   out_4349080714290348357[2] = 0;
   out_4349080714290348357[3] = 0;
   out_4349080714290348357[4] = -state[8];
   out_4349080714290348357[5] = state[7];
   out_4349080714290348357[6] = 0;
   out_4349080714290348357[7] = state[5];
   out_4349080714290348357[8] = -state[4];
   out_4349080714290348357[9] = 0;
   out_4349080714290348357[10] = 0;
   out_4349080714290348357[11] = 0;
   out_4349080714290348357[12] = 1;
   out_4349080714290348357[13] = 0;
   out_4349080714290348357[14] = 0;
   out_4349080714290348357[15] = 1;
   out_4349080714290348357[16] = 0;
   out_4349080714290348357[17] = 0;
   out_4349080714290348357[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_4349080714290348357[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_4349080714290348357[20] = 0;
   out_4349080714290348357[21] = state[8];
   out_4349080714290348357[22] = 0;
   out_4349080714290348357[23] = -state[6];
   out_4349080714290348357[24] = -state[5];
   out_4349080714290348357[25] = 0;
   out_4349080714290348357[26] = state[3];
   out_4349080714290348357[27] = 0;
   out_4349080714290348357[28] = 0;
   out_4349080714290348357[29] = 0;
   out_4349080714290348357[30] = 0;
   out_4349080714290348357[31] = 1;
   out_4349080714290348357[32] = 0;
   out_4349080714290348357[33] = 0;
   out_4349080714290348357[34] = 1;
   out_4349080714290348357[35] = 0;
   out_4349080714290348357[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_4349080714290348357[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_4349080714290348357[38] = 0;
   out_4349080714290348357[39] = -state[7];
   out_4349080714290348357[40] = state[6];
   out_4349080714290348357[41] = 0;
   out_4349080714290348357[42] = state[4];
   out_4349080714290348357[43] = -state[3];
   out_4349080714290348357[44] = 0;
   out_4349080714290348357[45] = 0;
   out_4349080714290348357[46] = 0;
   out_4349080714290348357[47] = 0;
   out_4349080714290348357[48] = 0;
   out_4349080714290348357[49] = 0;
   out_4349080714290348357[50] = 1;
   out_4349080714290348357[51] = 0;
   out_4349080714290348357[52] = 0;
   out_4349080714290348357[53] = 1;
}
void h_13(double *state, double *unused, double *out_5823501144179669569) {
   out_5823501144179669569[0] = state[3];
   out_5823501144179669569[1] = state[4];
   out_5823501144179669569[2] = state[5];
}
void H_13(double *state, double *unused, double *out_1314947996661404758) {
   out_1314947996661404758[0] = 0;
   out_1314947996661404758[1] = 0;
   out_1314947996661404758[2] = 0;
   out_1314947996661404758[3] = 1;
   out_1314947996661404758[4] = 0;
   out_1314947996661404758[5] = 0;
   out_1314947996661404758[6] = 0;
   out_1314947996661404758[7] = 0;
   out_1314947996661404758[8] = 0;
   out_1314947996661404758[9] = 0;
   out_1314947996661404758[10] = 0;
   out_1314947996661404758[11] = 0;
   out_1314947996661404758[12] = 0;
   out_1314947996661404758[13] = 0;
   out_1314947996661404758[14] = 0;
   out_1314947996661404758[15] = 0;
   out_1314947996661404758[16] = 0;
   out_1314947996661404758[17] = 0;
   out_1314947996661404758[18] = 0;
   out_1314947996661404758[19] = 0;
   out_1314947996661404758[20] = 0;
   out_1314947996661404758[21] = 0;
   out_1314947996661404758[22] = 1;
   out_1314947996661404758[23] = 0;
   out_1314947996661404758[24] = 0;
   out_1314947996661404758[25] = 0;
   out_1314947996661404758[26] = 0;
   out_1314947996661404758[27] = 0;
   out_1314947996661404758[28] = 0;
   out_1314947996661404758[29] = 0;
   out_1314947996661404758[30] = 0;
   out_1314947996661404758[31] = 0;
   out_1314947996661404758[32] = 0;
   out_1314947996661404758[33] = 0;
   out_1314947996661404758[34] = 0;
   out_1314947996661404758[35] = 0;
   out_1314947996661404758[36] = 0;
   out_1314947996661404758[37] = 0;
   out_1314947996661404758[38] = 0;
   out_1314947996661404758[39] = 0;
   out_1314947996661404758[40] = 0;
   out_1314947996661404758[41] = 1;
   out_1314947996661404758[42] = 0;
   out_1314947996661404758[43] = 0;
   out_1314947996661404758[44] = 0;
   out_1314947996661404758[45] = 0;
   out_1314947996661404758[46] = 0;
   out_1314947996661404758[47] = 0;
   out_1314947996661404758[48] = 0;
   out_1314947996661404758[49] = 0;
   out_1314947996661404758[50] = 0;
   out_1314947996661404758[51] = 0;
   out_1314947996661404758[52] = 0;
   out_1314947996661404758[53] = 0;
}
void h_14(double *state, double *unused, double *out_184671168520898278) {
   out_184671168520898278[0] = state[6];
   out_184671168520898278[1] = state[7];
   out_184671168520898278[2] = state[8];
}
void H_14(double *state, double *unused, double *out_4962338348638621158) {
   out_4962338348638621158[0] = 0;
   out_4962338348638621158[1] = 0;
   out_4962338348638621158[2] = 0;
   out_4962338348638621158[3] = 0;
   out_4962338348638621158[4] = 0;
   out_4962338348638621158[5] = 0;
   out_4962338348638621158[6] = 1;
   out_4962338348638621158[7] = 0;
   out_4962338348638621158[8] = 0;
   out_4962338348638621158[9] = 0;
   out_4962338348638621158[10] = 0;
   out_4962338348638621158[11] = 0;
   out_4962338348638621158[12] = 0;
   out_4962338348638621158[13] = 0;
   out_4962338348638621158[14] = 0;
   out_4962338348638621158[15] = 0;
   out_4962338348638621158[16] = 0;
   out_4962338348638621158[17] = 0;
   out_4962338348638621158[18] = 0;
   out_4962338348638621158[19] = 0;
   out_4962338348638621158[20] = 0;
   out_4962338348638621158[21] = 0;
   out_4962338348638621158[22] = 0;
   out_4962338348638621158[23] = 0;
   out_4962338348638621158[24] = 0;
   out_4962338348638621158[25] = 1;
   out_4962338348638621158[26] = 0;
   out_4962338348638621158[27] = 0;
   out_4962338348638621158[28] = 0;
   out_4962338348638621158[29] = 0;
   out_4962338348638621158[30] = 0;
   out_4962338348638621158[31] = 0;
   out_4962338348638621158[32] = 0;
   out_4962338348638621158[33] = 0;
   out_4962338348638621158[34] = 0;
   out_4962338348638621158[35] = 0;
   out_4962338348638621158[36] = 0;
   out_4962338348638621158[37] = 0;
   out_4962338348638621158[38] = 0;
   out_4962338348638621158[39] = 0;
   out_4962338348638621158[40] = 0;
   out_4962338348638621158[41] = 0;
   out_4962338348638621158[42] = 0;
   out_4962338348638621158[43] = 0;
   out_4962338348638621158[44] = 1;
   out_4962338348638621158[45] = 0;
   out_4962338348638621158[46] = 0;
   out_4962338348638621158[47] = 0;
   out_4962338348638621158[48] = 0;
   out_4962338348638621158[49] = 0;
   out_4962338348638621158[50] = 0;
   out_4962338348638621158[51] = 0;
   out_4962338348638621158[52] = 0;
   out_4962338348638621158[53] = 0;
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

void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_4, H_4, NULL, in_z, in_R, in_ea, MAHA_THRESH_4);
}
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_10, H_10, NULL, in_z, in_R, in_ea, MAHA_THRESH_10);
}
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_13, H_13, NULL, in_z, in_R, in_ea, MAHA_THRESH_13);
}
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_14, H_14, NULL, in_z, in_R, in_ea, MAHA_THRESH_14);
}
void pose_err_fun(double *nom_x, double *delta_x, double *out_4596150727177448991) {
  err_fun(nom_x, delta_x, out_4596150727177448991);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_5311469374371571464) {
  inv_err_fun(nom_x, true_x, out_5311469374371571464);
}
void pose_H_mod_fun(double *state, double *out_8767003866676733322) {
  H_mod_fun(state, out_8767003866676733322);
}
void pose_f_fun(double *state, double dt, double *out_2459657190356119743) {
  f_fun(state,  dt, out_2459657190356119743);
}
void pose_F_fun(double *state, double dt, double *out_6577442919905546465) {
  F_fun(state,  dt, out_6577442919905546465);
}
void pose_h_4(double *state, double *unused, double *out_7087470237745846386) {
  h_4(state, unused, out_7087470237745846386);
}
void pose_H_4(double *state, double *unused, double *out_8925579204978105687) {
  H_4(state, unused, out_8925579204978105687);
}
void pose_h_10(double *state, double *unused, double *out_6226154528069596479) {
  h_10(state, unused, out_6226154528069596479);
}
void pose_H_10(double *state, double *unused, double *out_4349080714290348357) {
  H_10(state, unused, out_4349080714290348357);
}
void pose_h_13(double *state, double *unused, double *out_5823501144179669569) {
  h_13(state, unused, out_5823501144179669569);
}
void pose_H_13(double *state, double *unused, double *out_1314947996661404758) {
  H_13(state, unused, out_1314947996661404758);
}
void pose_h_14(double *state, double *unused, double *out_184671168520898278) {
  h_14(state, unused, out_184671168520898278);
}
void pose_H_14(double *state, double *unused, double *out_4962338348638621158) {
  H_14(state, unused, out_4962338348638621158);
}
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF pose = {
  .name = "pose",
  .kinds = { 4, 10, 13, 14 },
  .feature_kinds = {  },
  .f_fun = pose_f_fun,
  .F_fun = pose_F_fun,
  .err_fun = pose_err_fun,
  .inv_err_fun = pose_inv_err_fun,
  .H_mod_fun = pose_H_mod_fun,
  .predict = pose_predict,
  .hs = {
    { 4, pose_h_4 },
    { 10, pose_h_10 },
    { 13, pose_h_13 },
    { 14, pose_h_14 },
  },
  .Hs = {
    { 4, pose_H_4 },
    { 10, pose_H_10 },
    { 13, pose_H_13 },
    { 14, pose_H_14 },
  },
  .updates = {
    { 4, pose_update_4 },
    { 10, pose_update_10 },
    { 13, pose_update_13 },
    { 14, pose_update_14 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_lib_init(pose)
