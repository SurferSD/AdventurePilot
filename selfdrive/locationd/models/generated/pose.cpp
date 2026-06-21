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
void err_fun(double *nom_x, double *delta_x, double *out_5361244045644666122) {
   out_5361244045644666122[0] = delta_x[0] + nom_x[0];
   out_5361244045644666122[1] = delta_x[1] + nom_x[1];
   out_5361244045644666122[2] = delta_x[2] + nom_x[2];
   out_5361244045644666122[3] = delta_x[3] + nom_x[3];
   out_5361244045644666122[4] = delta_x[4] + nom_x[4];
   out_5361244045644666122[5] = delta_x[5] + nom_x[5];
   out_5361244045644666122[6] = delta_x[6] + nom_x[6];
   out_5361244045644666122[7] = delta_x[7] + nom_x[7];
   out_5361244045644666122[8] = delta_x[8] + nom_x[8];
   out_5361244045644666122[9] = delta_x[9] + nom_x[9];
   out_5361244045644666122[10] = delta_x[10] + nom_x[10];
   out_5361244045644666122[11] = delta_x[11] + nom_x[11];
   out_5361244045644666122[12] = delta_x[12] + nom_x[12];
   out_5361244045644666122[13] = delta_x[13] + nom_x[13];
   out_5361244045644666122[14] = delta_x[14] + nom_x[14];
   out_5361244045644666122[15] = delta_x[15] + nom_x[15];
   out_5361244045644666122[16] = delta_x[16] + nom_x[16];
   out_5361244045644666122[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_8995639648578932435) {
   out_8995639648578932435[0] = -nom_x[0] + true_x[0];
   out_8995639648578932435[1] = -nom_x[1] + true_x[1];
   out_8995639648578932435[2] = -nom_x[2] + true_x[2];
   out_8995639648578932435[3] = -nom_x[3] + true_x[3];
   out_8995639648578932435[4] = -nom_x[4] + true_x[4];
   out_8995639648578932435[5] = -nom_x[5] + true_x[5];
   out_8995639648578932435[6] = -nom_x[6] + true_x[6];
   out_8995639648578932435[7] = -nom_x[7] + true_x[7];
   out_8995639648578932435[8] = -nom_x[8] + true_x[8];
   out_8995639648578932435[9] = -nom_x[9] + true_x[9];
   out_8995639648578932435[10] = -nom_x[10] + true_x[10];
   out_8995639648578932435[11] = -nom_x[11] + true_x[11];
   out_8995639648578932435[12] = -nom_x[12] + true_x[12];
   out_8995639648578932435[13] = -nom_x[13] + true_x[13];
   out_8995639648578932435[14] = -nom_x[14] + true_x[14];
   out_8995639648578932435[15] = -nom_x[15] + true_x[15];
   out_8995639648578932435[16] = -nom_x[16] + true_x[16];
   out_8995639648578932435[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_401548470790065973) {
   out_401548470790065973[0] = 1.0;
   out_401548470790065973[1] = 0.0;
   out_401548470790065973[2] = 0.0;
   out_401548470790065973[3] = 0.0;
   out_401548470790065973[4] = 0.0;
   out_401548470790065973[5] = 0.0;
   out_401548470790065973[6] = 0.0;
   out_401548470790065973[7] = 0.0;
   out_401548470790065973[8] = 0.0;
   out_401548470790065973[9] = 0.0;
   out_401548470790065973[10] = 0.0;
   out_401548470790065973[11] = 0.0;
   out_401548470790065973[12] = 0.0;
   out_401548470790065973[13] = 0.0;
   out_401548470790065973[14] = 0.0;
   out_401548470790065973[15] = 0.0;
   out_401548470790065973[16] = 0.0;
   out_401548470790065973[17] = 0.0;
   out_401548470790065973[18] = 0.0;
   out_401548470790065973[19] = 1.0;
   out_401548470790065973[20] = 0.0;
   out_401548470790065973[21] = 0.0;
   out_401548470790065973[22] = 0.0;
   out_401548470790065973[23] = 0.0;
   out_401548470790065973[24] = 0.0;
   out_401548470790065973[25] = 0.0;
   out_401548470790065973[26] = 0.0;
   out_401548470790065973[27] = 0.0;
   out_401548470790065973[28] = 0.0;
   out_401548470790065973[29] = 0.0;
   out_401548470790065973[30] = 0.0;
   out_401548470790065973[31] = 0.0;
   out_401548470790065973[32] = 0.0;
   out_401548470790065973[33] = 0.0;
   out_401548470790065973[34] = 0.0;
   out_401548470790065973[35] = 0.0;
   out_401548470790065973[36] = 0.0;
   out_401548470790065973[37] = 0.0;
   out_401548470790065973[38] = 1.0;
   out_401548470790065973[39] = 0.0;
   out_401548470790065973[40] = 0.0;
   out_401548470790065973[41] = 0.0;
   out_401548470790065973[42] = 0.0;
   out_401548470790065973[43] = 0.0;
   out_401548470790065973[44] = 0.0;
   out_401548470790065973[45] = 0.0;
   out_401548470790065973[46] = 0.0;
   out_401548470790065973[47] = 0.0;
   out_401548470790065973[48] = 0.0;
   out_401548470790065973[49] = 0.0;
   out_401548470790065973[50] = 0.0;
   out_401548470790065973[51] = 0.0;
   out_401548470790065973[52] = 0.0;
   out_401548470790065973[53] = 0.0;
   out_401548470790065973[54] = 0.0;
   out_401548470790065973[55] = 0.0;
   out_401548470790065973[56] = 0.0;
   out_401548470790065973[57] = 1.0;
   out_401548470790065973[58] = 0.0;
   out_401548470790065973[59] = 0.0;
   out_401548470790065973[60] = 0.0;
   out_401548470790065973[61] = 0.0;
   out_401548470790065973[62] = 0.0;
   out_401548470790065973[63] = 0.0;
   out_401548470790065973[64] = 0.0;
   out_401548470790065973[65] = 0.0;
   out_401548470790065973[66] = 0.0;
   out_401548470790065973[67] = 0.0;
   out_401548470790065973[68] = 0.0;
   out_401548470790065973[69] = 0.0;
   out_401548470790065973[70] = 0.0;
   out_401548470790065973[71] = 0.0;
   out_401548470790065973[72] = 0.0;
   out_401548470790065973[73] = 0.0;
   out_401548470790065973[74] = 0.0;
   out_401548470790065973[75] = 0.0;
   out_401548470790065973[76] = 1.0;
   out_401548470790065973[77] = 0.0;
   out_401548470790065973[78] = 0.0;
   out_401548470790065973[79] = 0.0;
   out_401548470790065973[80] = 0.0;
   out_401548470790065973[81] = 0.0;
   out_401548470790065973[82] = 0.0;
   out_401548470790065973[83] = 0.0;
   out_401548470790065973[84] = 0.0;
   out_401548470790065973[85] = 0.0;
   out_401548470790065973[86] = 0.0;
   out_401548470790065973[87] = 0.0;
   out_401548470790065973[88] = 0.0;
   out_401548470790065973[89] = 0.0;
   out_401548470790065973[90] = 0.0;
   out_401548470790065973[91] = 0.0;
   out_401548470790065973[92] = 0.0;
   out_401548470790065973[93] = 0.0;
   out_401548470790065973[94] = 0.0;
   out_401548470790065973[95] = 1.0;
   out_401548470790065973[96] = 0.0;
   out_401548470790065973[97] = 0.0;
   out_401548470790065973[98] = 0.0;
   out_401548470790065973[99] = 0.0;
   out_401548470790065973[100] = 0.0;
   out_401548470790065973[101] = 0.0;
   out_401548470790065973[102] = 0.0;
   out_401548470790065973[103] = 0.0;
   out_401548470790065973[104] = 0.0;
   out_401548470790065973[105] = 0.0;
   out_401548470790065973[106] = 0.0;
   out_401548470790065973[107] = 0.0;
   out_401548470790065973[108] = 0.0;
   out_401548470790065973[109] = 0.0;
   out_401548470790065973[110] = 0.0;
   out_401548470790065973[111] = 0.0;
   out_401548470790065973[112] = 0.0;
   out_401548470790065973[113] = 0.0;
   out_401548470790065973[114] = 1.0;
   out_401548470790065973[115] = 0.0;
   out_401548470790065973[116] = 0.0;
   out_401548470790065973[117] = 0.0;
   out_401548470790065973[118] = 0.0;
   out_401548470790065973[119] = 0.0;
   out_401548470790065973[120] = 0.0;
   out_401548470790065973[121] = 0.0;
   out_401548470790065973[122] = 0.0;
   out_401548470790065973[123] = 0.0;
   out_401548470790065973[124] = 0.0;
   out_401548470790065973[125] = 0.0;
   out_401548470790065973[126] = 0.0;
   out_401548470790065973[127] = 0.0;
   out_401548470790065973[128] = 0.0;
   out_401548470790065973[129] = 0.0;
   out_401548470790065973[130] = 0.0;
   out_401548470790065973[131] = 0.0;
   out_401548470790065973[132] = 0.0;
   out_401548470790065973[133] = 1.0;
   out_401548470790065973[134] = 0.0;
   out_401548470790065973[135] = 0.0;
   out_401548470790065973[136] = 0.0;
   out_401548470790065973[137] = 0.0;
   out_401548470790065973[138] = 0.0;
   out_401548470790065973[139] = 0.0;
   out_401548470790065973[140] = 0.0;
   out_401548470790065973[141] = 0.0;
   out_401548470790065973[142] = 0.0;
   out_401548470790065973[143] = 0.0;
   out_401548470790065973[144] = 0.0;
   out_401548470790065973[145] = 0.0;
   out_401548470790065973[146] = 0.0;
   out_401548470790065973[147] = 0.0;
   out_401548470790065973[148] = 0.0;
   out_401548470790065973[149] = 0.0;
   out_401548470790065973[150] = 0.0;
   out_401548470790065973[151] = 0.0;
   out_401548470790065973[152] = 1.0;
   out_401548470790065973[153] = 0.0;
   out_401548470790065973[154] = 0.0;
   out_401548470790065973[155] = 0.0;
   out_401548470790065973[156] = 0.0;
   out_401548470790065973[157] = 0.0;
   out_401548470790065973[158] = 0.0;
   out_401548470790065973[159] = 0.0;
   out_401548470790065973[160] = 0.0;
   out_401548470790065973[161] = 0.0;
   out_401548470790065973[162] = 0.0;
   out_401548470790065973[163] = 0.0;
   out_401548470790065973[164] = 0.0;
   out_401548470790065973[165] = 0.0;
   out_401548470790065973[166] = 0.0;
   out_401548470790065973[167] = 0.0;
   out_401548470790065973[168] = 0.0;
   out_401548470790065973[169] = 0.0;
   out_401548470790065973[170] = 0.0;
   out_401548470790065973[171] = 1.0;
   out_401548470790065973[172] = 0.0;
   out_401548470790065973[173] = 0.0;
   out_401548470790065973[174] = 0.0;
   out_401548470790065973[175] = 0.0;
   out_401548470790065973[176] = 0.0;
   out_401548470790065973[177] = 0.0;
   out_401548470790065973[178] = 0.0;
   out_401548470790065973[179] = 0.0;
   out_401548470790065973[180] = 0.0;
   out_401548470790065973[181] = 0.0;
   out_401548470790065973[182] = 0.0;
   out_401548470790065973[183] = 0.0;
   out_401548470790065973[184] = 0.0;
   out_401548470790065973[185] = 0.0;
   out_401548470790065973[186] = 0.0;
   out_401548470790065973[187] = 0.0;
   out_401548470790065973[188] = 0.0;
   out_401548470790065973[189] = 0.0;
   out_401548470790065973[190] = 1.0;
   out_401548470790065973[191] = 0.0;
   out_401548470790065973[192] = 0.0;
   out_401548470790065973[193] = 0.0;
   out_401548470790065973[194] = 0.0;
   out_401548470790065973[195] = 0.0;
   out_401548470790065973[196] = 0.0;
   out_401548470790065973[197] = 0.0;
   out_401548470790065973[198] = 0.0;
   out_401548470790065973[199] = 0.0;
   out_401548470790065973[200] = 0.0;
   out_401548470790065973[201] = 0.0;
   out_401548470790065973[202] = 0.0;
   out_401548470790065973[203] = 0.0;
   out_401548470790065973[204] = 0.0;
   out_401548470790065973[205] = 0.0;
   out_401548470790065973[206] = 0.0;
   out_401548470790065973[207] = 0.0;
   out_401548470790065973[208] = 0.0;
   out_401548470790065973[209] = 1.0;
   out_401548470790065973[210] = 0.0;
   out_401548470790065973[211] = 0.0;
   out_401548470790065973[212] = 0.0;
   out_401548470790065973[213] = 0.0;
   out_401548470790065973[214] = 0.0;
   out_401548470790065973[215] = 0.0;
   out_401548470790065973[216] = 0.0;
   out_401548470790065973[217] = 0.0;
   out_401548470790065973[218] = 0.0;
   out_401548470790065973[219] = 0.0;
   out_401548470790065973[220] = 0.0;
   out_401548470790065973[221] = 0.0;
   out_401548470790065973[222] = 0.0;
   out_401548470790065973[223] = 0.0;
   out_401548470790065973[224] = 0.0;
   out_401548470790065973[225] = 0.0;
   out_401548470790065973[226] = 0.0;
   out_401548470790065973[227] = 0.0;
   out_401548470790065973[228] = 1.0;
   out_401548470790065973[229] = 0.0;
   out_401548470790065973[230] = 0.0;
   out_401548470790065973[231] = 0.0;
   out_401548470790065973[232] = 0.0;
   out_401548470790065973[233] = 0.0;
   out_401548470790065973[234] = 0.0;
   out_401548470790065973[235] = 0.0;
   out_401548470790065973[236] = 0.0;
   out_401548470790065973[237] = 0.0;
   out_401548470790065973[238] = 0.0;
   out_401548470790065973[239] = 0.0;
   out_401548470790065973[240] = 0.0;
   out_401548470790065973[241] = 0.0;
   out_401548470790065973[242] = 0.0;
   out_401548470790065973[243] = 0.0;
   out_401548470790065973[244] = 0.0;
   out_401548470790065973[245] = 0.0;
   out_401548470790065973[246] = 0.0;
   out_401548470790065973[247] = 1.0;
   out_401548470790065973[248] = 0.0;
   out_401548470790065973[249] = 0.0;
   out_401548470790065973[250] = 0.0;
   out_401548470790065973[251] = 0.0;
   out_401548470790065973[252] = 0.0;
   out_401548470790065973[253] = 0.0;
   out_401548470790065973[254] = 0.0;
   out_401548470790065973[255] = 0.0;
   out_401548470790065973[256] = 0.0;
   out_401548470790065973[257] = 0.0;
   out_401548470790065973[258] = 0.0;
   out_401548470790065973[259] = 0.0;
   out_401548470790065973[260] = 0.0;
   out_401548470790065973[261] = 0.0;
   out_401548470790065973[262] = 0.0;
   out_401548470790065973[263] = 0.0;
   out_401548470790065973[264] = 0.0;
   out_401548470790065973[265] = 0.0;
   out_401548470790065973[266] = 1.0;
   out_401548470790065973[267] = 0.0;
   out_401548470790065973[268] = 0.0;
   out_401548470790065973[269] = 0.0;
   out_401548470790065973[270] = 0.0;
   out_401548470790065973[271] = 0.0;
   out_401548470790065973[272] = 0.0;
   out_401548470790065973[273] = 0.0;
   out_401548470790065973[274] = 0.0;
   out_401548470790065973[275] = 0.0;
   out_401548470790065973[276] = 0.0;
   out_401548470790065973[277] = 0.0;
   out_401548470790065973[278] = 0.0;
   out_401548470790065973[279] = 0.0;
   out_401548470790065973[280] = 0.0;
   out_401548470790065973[281] = 0.0;
   out_401548470790065973[282] = 0.0;
   out_401548470790065973[283] = 0.0;
   out_401548470790065973[284] = 0.0;
   out_401548470790065973[285] = 1.0;
   out_401548470790065973[286] = 0.0;
   out_401548470790065973[287] = 0.0;
   out_401548470790065973[288] = 0.0;
   out_401548470790065973[289] = 0.0;
   out_401548470790065973[290] = 0.0;
   out_401548470790065973[291] = 0.0;
   out_401548470790065973[292] = 0.0;
   out_401548470790065973[293] = 0.0;
   out_401548470790065973[294] = 0.0;
   out_401548470790065973[295] = 0.0;
   out_401548470790065973[296] = 0.0;
   out_401548470790065973[297] = 0.0;
   out_401548470790065973[298] = 0.0;
   out_401548470790065973[299] = 0.0;
   out_401548470790065973[300] = 0.0;
   out_401548470790065973[301] = 0.0;
   out_401548470790065973[302] = 0.0;
   out_401548470790065973[303] = 0.0;
   out_401548470790065973[304] = 1.0;
   out_401548470790065973[305] = 0.0;
   out_401548470790065973[306] = 0.0;
   out_401548470790065973[307] = 0.0;
   out_401548470790065973[308] = 0.0;
   out_401548470790065973[309] = 0.0;
   out_401548470790065973[310] = 0.0;
   out_401548470790065973[311] = 0.0;
   out_401548470790065973[312] = 0.0;
   out_401548470790065973[313] = 0.0;
   out_401548470790065973[314] = 0.0;
   out_401548470790065973[315] = 0.0;
   out_401548470790065973[316] = 0.0;
   out_401548470790065973[317] = 0.0;
   out_401548470790065973[318] = 0.0;
   out_401548470790065973[319] = 0.0;
   out_401548470790065973[320] = 0.0;
   out_401548470790065973[321] = 0.0;
   out_401548470790065973[322] = 0.0;
   out_401548470790065973[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_8900446657124786632) {
   out_8900446657124786632[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_8900446657124786632[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_8900446657124786632[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_8900446657124786632[3] = dt*state[12] + state[3];
   out_8900446657124786632[4] = dt*state[13] + state[4];
   out_8900446657124786632[5] = dt*state[14] + state[5];
   out_8900446657124786632[6] = state[6];
   out_8900446657124786632[7] = state[7];
   out_8900446657124786632[8] = state[8];
   out_8900446657124786632[9] = state[9];
   out_8900446657124786632[10] = state[10];
   out_8900446657124786632[11] = state[11];
   out_8900446657124786632[12] = state[12];
   out_8900446657124786632[13] = state[13];
   out_8900446657124786632[14] = state[14];
   out_8900446657124786632[15] = state[15];
   out_8900446657124786632[16] = state[16];
   out_8900446657124786632[17] = state[17];
}
void F_fun(double *state, double dt, double *out_8518082037714010112) {
   out_8518082037714010112[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8518082037714010112[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8518082037714010112[2] = 0;
   out_8518082037714010112[3] = 0;
   out_8518082037714010112[4] = 0;
   out_8518082037714010112[5] = 0;
   out_8518082037714010112[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8518082037714010112[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8518082037714010112[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_8518082037714010112[9] = 0;
   out_8518082037714010112[10] = 0;
   out_8518082037714010112[11] = 0;
   out_8518082037714010112[12] = 0;
   out_8518082037714010112[13] = 0;
   out_8518082037714010112[14] = 0;
   out_8518082037714010112[15] = 0;
   out_8518082037714010112[16] = 0;
   out_8518082037714010112[17] = 0;
   out_8518082037714010112[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8518082037714010112[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8518082037714010112[20] = 0;
   out_8518082037714010112[21] = 0;
   out_8518082037714010112[22] = 0;
   out_8518082037714010112[23] = 0;
   out_8518082037714010112[24] = 0;
   out_8518082037714010112[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8518082037714010112[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_8518082037714010112[27] = 0;
   out_8518082037714010112[28] = 0;
   out_8518082037714010112[29] = 0;
   out_8518082037714010112[30] = 0;
   out_8518082037714010112[31] = 0;
   out_8518082037714010112[32] = 0;
   out_8518082037714010112[33] = 0;
   out_8518082037714010112[34] = 0;
   out_8518082037714010112[35] = 0;
   out_8518082037714010112[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8518082037714010112[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8518082037714010112[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8518082037714010112[39] = 0;
   out_8518082037714010112[40] = 0;
   out_8518082037714010112[41] = 0;
   out_8518082037714010112[42] = 0;
   out_8518082037714010112[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8518082037714010112[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_8518082037714010112[45] = 0;
   out_8518082037714010112[46] = 0;
   out_8518082037714010112[47] = 0;
   out_8518082037714010112[48] = 0;
   out_8518082037714010112[49] = 0;
   out_8518082037714010112[50] = 0;
   out_8518082037714010112[51] = 0;
   out_8518082037714010112[52] = 0;
   out_8518082037714010112[53] = 0;
   out_8518082037714010112[54] = 0;
   out_8518082037714010112[55] = 0;
   out_8518082037714010112[56] = 0;
   out_8518082037714010112[57] = 1;
   out_8518082037714010112[58] = 0;
   out_8518082037714010112[59] = 0;
   out_8518082037714010112[60] = 0;
   out_8518082037714010112[61] = 0;
   out_8518082037714010112[62] = 0;
   out_8518082037714010112[63] = 0;
   out_8518082037714010112[64] = 0;
   out_8518082037714010112[65] = 0;
   out_8518082037714010112[66] = dt;
   out_8518082037714010112[67] = 0;
   out_8518082037714010112[68] = 0;
   out_8518082037714010112[69] = 0;
   out_8518082037714010112[70] = 0;
   out_8518082037714010112[71] = 0;
   out_8518082037714010112[72] = 0;
   out_8518082037714010112[73] = 0;
   out_8518082037714010112[74] = 0;
   out_8518082037714010112[75] = 0;
   out_8518082037714010112[76] = 1;
   out_8518082037714010112[77] = 0;
   out_8518082037714010112[78] = 0;
   out_8518082037714010112[79] = 0;
   out_8518082037714010112[80] = 0;
   out_8518082037714010112[81] = 0;
   out_8518082037714010112[82] = 0;
   out_8518082037714010112[83] = 0;
   out_8518082037714010112[84] = 0;
   out_8518082037714010112[85] = dt;
   out_8518082037714010112[86] = 0;
   out_8518082037714010112[87] = 0;
   out_8518082037714010112[88] = 0;
   out_8518082037714010112[89] = 0;
   out_8518082037714010112[90] = 0;
   out_8518082037714010112[91] = 0;
   out_8518082037714010112[92] = 0;
   out_8518082037714010112[93] = 0;
   out_8518082037714010112[94] = 0;
   out_8518082037714010112[95] = 1;
   out_8518082037714010112[96] = 0;
   out_8518082037714010112[97] = 0;
   out_8518082037714010112[98] = 0;
   out_8518082037714010112[99] = 0;
   out_8518082037714010112[100] = 0;
   out_8518082037714010112[101] = 0;
   out_8518082037714010112[102] = 0;
   out_8518082037714010112[103] = 0;
   out_8518082037714010112[104] = dt;
   out_8518082037714010112[105] = 0;
   out_8518082037714010112[106] = 0;
   out_8518082037714010112[107] = 0;
   out_8518082037714010112[108] = 0;
   out_8518082037714010112[109] = 0;
   out_8518082037714010112[110] = 0;
   out_8518082037714010112[111] = 0;
   out_8518082037714010112[112] = 0;
   out_8518082037714010112[113] = 0;
   out_8518082037714010112[114] = 1;
   out_8518082037714010112[115] = 0;
   out_8518082037714010112[116] = 0;
   out_8518082037714010112[117] = 0;
   out_8518082037714010112[118] = 0;
   out_8518082037714010112[119] = 0;
   out_8518082037714010112[120] = 0;
   out_8518082037714010112[121] = 0;
   out_8518082037714010112[122] = 0;
   out_8518082037714010112[123] = 0;
   out_8518082037714010112[124] = 0;
   out_8518082037714010112[125] = 0;
   out_8518082037714010112[126] = 0;
   out_8518082037714010112[127] = 0;
   out_8518082037714010112[128] = 0;
   out_8518082037714010112[129] = 0;
   out_8518082037714010112[130] = 0;
   out_8518082037714010112[131] = 0;
   out_8518082037714010112[132] = 0;
   out_8518082037714010112[133] = 1;
   out_8518082037714010112[134] = 0;
   out_8518082037714010112[135] = 0;
   out_8518082037714010112[136] = 0;
   out_8518082037714010112[137] = 0;
   out_8518082037714010112[138] = 0;
   out_8518082037714010112[139] = 0;
   out_8518082037714010112[140] = 0;
   out_8518082037714010112[141] = 0;
   out_8518082037714010112[142] = 0;
   out_8518082037714010112[143] = 0;
   out_8518082037714010112[144] = 0;
   out_8518082037714010112[145] = 0;
   out_8518082037714010112[146] = 0;
   out_8518082037714010112[147] = 0;
   out_8518082037714010112[148] = 0;
   out_8518082037714010112[149] = 0;
   out_8518082037714010112[150] = 0;
   out_8518082037714010112[151] = 0;
   out_8518082037714010112[152] = 1;
   out_8518082037714010112[153] = 0;
   out_8518082037714010112[154] = 0;
   out_8518082037714010112[155] = 0;
   out_8518082037714010112[156] = 0;
   out_8518082037714010112[157] = 0;
   out_8518082037714010112[158] = 0;
   out_8518082037714010112[159] = 0;
   out_8518082037714010112[160] = 0;
   out_8518082037714010112[161] = 0;
   out_8518082037714010112[162] = 0;
   out_8518082037714010112[163] = 0;
   out_8518082037714010112[164] = 0;
   out_8518082037714010112[165] = 0;
   out_8518082037714010112[166] = 0;
   out_8518082037714010112[167] = 0;
   out_8518082037714010112[168] = 0;
   out_8518082037714010112[169] = 0;
   out_8518082037714010112[170] = 0;
   out_8518082037714010112[171] = 1;
   out_8518082037714010112[172] = 0;
   out_8518082037714010112[173] = 0;
   out_8518082037714010112[174] = 0;
   out_8518082037714010112[175] = 0;
   out_8518082037714010112[176] = 0;
   out_8518082037714010112[177] = 0;
   out_8518082037714010112[178] = 0;
   out_8518082037714010112[179] = 0;
   out_8518082037714010112[180] = 0;
   out_8518082037714010112[181] = 0;
   out_8518082037714010112[182] = 0;
   out_8518082037714010112[183] = 0;
   out_8518082037714010112[184] = 0;
   out_8518082037714010112[185] = 0;
   out_8518082037714010112[186] = 0;
   out_8518082037714010112[187] = 0;
   out_8518082037714010112[188] = 0;
   out_8518082037714010112[189] = 0;
   out_8518082037714010112[190] = 1;
   out_8518082037714010112[191] = 0;
   out_8518082037714010112[192] = 0;
   out_8518082037714010112[193] = 0;
   out_8518082037714010112[194] = 0;
   out_8518082037714010112[195] = 0;
   out_8518082037714010112[196] = 0;
   out_8518082037714010112[197] = 0;
   out_8518082037714010112[198] = 0;
   out_8518082037714010112[199] = 0;
   out_8518082037714010112[200] = 0;
   out_8518082037714010112[201] = 0;
   out_8518082037714010112[202] = 0;
   out_8518082037714010112[203] = 0;
   out_8518082037714010112[204] = 0;
   out_8518082037714010112[205] = 0;
   out_8518082037714010112[206] = 0;
   out_8518082037714010112[207] = 0;
   out_8518082037714010112[208] = 0;
   out_8518082037714010112[209] = 1;
   out_8518082037714010112[210] = 0;
   out_8518082037714010112[211] = 0;
   out_8518082037714010112[212] = 0;
   out_8518082037714010112[213] = 0;
   out_8518082037714010112[214] = 0;
   out_8518082037714010112[215] = 0;
   out_8518082037714010112[216] = 0;
   out_8518082037714010112[217] = 0;
   out_8518082037714010112[218] = 0;
   out_8518082037714010112[219] = 0;
   out_8518082037714010112[220] = 0;
   out_8518082037714010112[221] = 0;
   out_8518082037714010112[222] = 0;
   out_8518082037714010112[223] = 0;
   out_8518082037714010112[224] = 0;
   out_8518082037714010112[225] = 0;
   out_8518082037714010112[226] = 0;
   out_8518082037714010112[227] = 0;
   out_8518082037714010112[228] = 1;
   out_8518082037714010112[229] = 0;
   out_8518082037714010112[230] = 0;
   out_8518082037714010112[231] = 0;
   out_8518082037714010112[232] = 0;
   out_8518082037714010112[233] = 0;
   out_8518082037714010112[234] = 0;
   out_8518082037714010112[235] = 0;
   out_8518082037714010112[236] = 0;
   out_8518082037714010112[237] = 0;
   out_8518082037714010112[238] = 0;
   out_8518082037714010112[239] = 0;
   out_8518082037714010112[240] = 0;
   out_8518082037714010112[241] = 0;
   out_8518082037714010112[242] = 0;
   out_8518082037714010112[243] = 0;
   out_8518082037714010112[244] = 0;
   out_8518082037714010112[245] = 0;
   out_8518082037714010112[246] = 0;
   out_8518082037714010112[247] = 1;
   out_8518082037714010112[248] = 0;
   out_8518082037714010112[249] = 0;
   out_8518082037714010112[250] = 0;
   out_8518082037714010112[251] = 0;
   out_8518082037714010112[252] = 0;
   out_8518082037714010112[253] = 0;
   out_8518082037714010112[254] = 0;
   out_8518082037714010112[255] = 0;
   out_8518082037714010112[256] = 0;
   out_8518082037714010112[257] = 0;
   out_8518082037714010112[258] = 0;
   out_8518082037714010112[259] = 0;
   out_8518082037714010112[260] = 0;
   out_8518082037714010112[261] = 0;
   out_8518082037714010112[262] = 0;
   out_8518082037714010112[263] = 0;
   out_8518082037714010112[264] = 0;
   out_8518082037714010112[265] = 0;
   out_8518082037714010112[266] = 1;
   out_8518082037714010112[267] = 0;
   out_8518082037714010112[268] = 0;
   out_8518082037714010112[269] = 0;
   out_8518082037714010112[270] = 0;
   out_8518082037714010112[271] = 0;
   out_8518082037714010112[272] = 0;
   out_8518082037714010112[273] = 0;
   out_8518082037714010112[274] = 0;
   out_8518082037714010112[275] = 0;
   out_8518082037714010112[276] = 0;
   out_8518082037714010112[277] = 0;
   out_8518082037714010112[278] = 0;
   out_8518082037714010112[279] = 0;
   out_8518082037714010112[280] = 0;
   out_8518082037714010112[281] = 0;
   out_8518082037714010112[282] = 0;
   out_8518082037714010112[283] = 0;
   out_8518082037714010112[284] = 0;
   out_8518082037714010112[285] = 1;
   out_8518082037714010112[286] = 0;
   out_8518082037714010112[287] = 0;
   out_8518082037714010112[288] = 0;
   out_8518082037714010112[289] = 0;
   out_8518082037714010112[290] = 0;
   out_8518082037714010112[291] = 0;
   out_8518082037714010112[292] = 0;
   out_8518082037714010112[293] = 0;
   out_8518082037714010112[294] = 0;
   out_8518082037714010112[295] = 0;
   out_8518082037714010112[296] = 0;
   out_8518082037714010112[297] = 0;
   out_8518082037714010112[298] = 0;
   out_8518082037714010112[299] = 0;
   out_8518082037714010112[300] = 0;
   out_8518082037714010112[301] = 0;
   out_8518082037714010112[302] = 0;
   out_8518082037714010112[303] = 0;
   out_8518082037714010112[304] = 1;
   out_8518082037714010112[305] = 0;
   out_8518082037714010112[306] = 0;
   out_8518082037714010112[307] = 0;
   out_8518082037714010112[308] = 0;
   out_8518082037714010112[309] = 0;
   out_8518082037714010112[310] = 0;
   out_8518082037714010112[311] = 0;
   out_8518082037714010112[312] = 0;
   out_8518082037714010112[313] = 0;
   out_8518082037714010112[314] = 0;
   out_8518082037714010112[315] = 0;
   out_8518082037714010112[316] = 0;
   out_8518082037714010112[317] = 0;
   out_8518082037714010112[318] = 0;
   out_8518082037714010112[319] = 0;
   out_8518082037714010112[320] = 0;
   out_8518082037714010112[321] = 0;
   out_8518082037714010112[322] = 0;
   out_8518082037714010112[323] = 1;
}
void h_4(double *state, double *unused, double *out_340313044583703153) {
   out_340313044583703153[0] = state[6] + state[9];
   out_340313044583703153[1] = state[7] + state[10];
   out_340313044583703153[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_3448892390570509255) {
   out_3448892390570509255[0] = 0;
   out_3448892390570509255[1] = 0;
   out_3448892390570509255[2] = 0;
   out_3448892390570509255[3] = 0;
   out_3448892390570509255[4] = 0;
   out_3448892390570509255[5] = 0;
   out_3448892390570509255[6] = 1;
   out_3448892390570509255[7] = 0;
   out_3448892390570509255[8] = 0;
   out_3448892390570509255[9] = 1;
   out_3448892390570509255[10] = 0;
   out_3448892390570509255[11] = 0;
   out_3448892390570509255[12] = 0;
   out_3448892390570509255[13] = 0;
   out_3448892390570509255[14] = 0;
   out_3448892390570509255[15] = 0;
   out_3448892390570509255[16] = 0;
   out_3448892390570509255[17] = 0;
   out_3448892390570509255[18] = 0;
   out_3448892390570509255[19] = 0;
   out_3448892390570509255[20] = 0;
   out_3448892390570509255[21] = 0;
   out_3448892390570509255[22] = 0;
   out_3448892390570509255[23] = 0;
   out_3448892390570509255[24] = 0;
   out_3448892390570509255[25] = 1;
   out_3448892390570509255[26] = 0;
   out_3448892390570509255[27] = 0;
   out_3448892390570509255[28] = 1;
   out_3448892390570509255[29] = 0;
   out_3448892390570509255[30] = 0;
   out_3448892390570509255[31] = 0;
   out_3448892390570509255[32] = 0;
   out_3448892390570509255[33] = 0;
   out_3448892390570509255[34] = 0;
   out_3448892390570509255[35] = 0;
   out_3448892390570509255[36] = 0;
   out_3448892390570509255[37] = 0;
   out_3448892390570509255[38] = 0;
   out_3448892390570509255[39] = 0;
   out_3448892390570509255[40] = 0;
   out_3448892390570509255[41] = 0;
   out_3448892390570509255[42] = 0;
   out_3448892390570509255[43] = 0;
   out_3448892390570509255[44] = 1;
   out_3448892390570509255[45] = 0;
   out_3448892390570509255[46] = 0;
   out_3448892390570509255[47] = 1;
   out_3448892390570509255[48] = 0;
   out_3448892390570509255[49] = 0;
   out_3448892390570509255[50] = 0;
   out_3448892390570509255[51] = 0;
   out_3448892390570509255[52] = 0;
   out_3448892390570509255[53] = 0;
}
void h_10(double *state, double *unused, double *out_7998523049083505895) {
   out_7998523049083505895[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_7998523049083505895[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_7998523049083505895[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_3744112959449252940) {
   out_3744112959449252940[0] = 0;
   out_3744112959449252940[1] = 9.8100000000000005*cos(state[1]);
   out_3744112959449252940[2] = 0;
   out_3744112959449252940[3] = 0;
   out_3744112959449252940[4] = -state[8];
   out_3744112959449252940[5] = state[7];
   out_3744112959449252940[6] = 0;
   out_3744112959449252940[7] = state[5];
   out_3744112959449252940[8] = -state[4];
   out_3744112959449252940[9] = 0;
   out_3744112959449252940[10] = 0;
   out_3744112959449252940[11] = 0;
   out_3744112959449252940[12] = 1;
   out_3744112959449252940[13] = 0;
   out_3744112959449252940[14] = 0;
   out_3744112959449252940[15] = 1;
   out_3744112959449252940[16] = 0;
   out_3744112959449252940[17] = 0;
   out_3744112959449252940[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_3744112959449252940[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_3744112959449252940[20] = 0;
   out_3744112959449252940[21] = state[8];
   out_3744112959449252940[22] = 0;
   out_3744112959449252940[23] = -state[6];
   out_3744112959449252940[24] = -state[5];
   out_3744112959449252940[25] = 0;
   out_3744112959449252940[26] = state[3];
   out_3744112959449252940[27] = 0;
   out_3744112959449252940[28] = 0;
   out_3744112959449252940[29] = 0;
   out_3744112959449252940[30] = 0;
   out_3744112959449252940[31] = 1;
   out_3744112959449252940[32] = 0;
   out_3744112959449252940[33] = 0;
   out_3744112959449252940[34] = 1;
   out_3744112959449252940[35] = 0;
   out_3744112959449252940[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_3744112959449252940[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_3744112959449252940[38] = 0;
   out_3744112959449252940[39] = -state[7];
   out_3744112959449252940[40] = state[6];
   out_3744112959449252940[41] = 0;
   out_3744112959449252940[42] = state[4];
   out_3744112959449252940[43] = -state[3];
   out_3744112959449252940[44] = 0;
   out_3744112959449252940[45] = 0;
   out_3744112959449252940[46] = 0;
   out_3744112959449252940[47] = 0;
   out_3744112959449252940[48] = 0;
   out_3744112959449252940[49] = 0;
   out_3744112959449252940[50] = 1;
   out_3744112959449252940[51] = 0;
   out_3744112959449252940[52] = 0;
   out_3744112959449252940[53] = 1;
}
void h_13(double *state, double *unused, double *out_7266816994167798755) {
   out_7266816994167798755[0] = state[3];
   out_7266816994167798755[1] = state[4];
   out_7266816994167798755[2] = state[5];
}
void H_13(double *state, double *unused, double *out_6661166215902842056) {
   out_6661166215902842056[0] = 0;
   out_6661166215902842056[1] = 0;
   out_6661166215902842056[2] = 0;
   out_6661166215902842056[3] = 1;
   out_6661166215902842056[4] = 0;
   out_6661166215902842056[5] = 0;
   out_6661166215902842056[6] = 0;
   out_6661166215902842056[7] = 0;
   out_6661166215902842056[8] = 0;
   out_6661166215902842056[9] = 0;
   out_6661166215902842056[10] = 0;
   out_6661166215902842056[11] = 0;
   out_6661166215902842056[12] = 0;
   out_6661166215902842056[13] = 0;
   out_6661166215902842056[14] = 0;
   out_6661166215902842056[15] = 0;
   out_6661166215902842056[16] = 0;
   out_6661166215902842056[17] = 0;
   out_6661166215902842056[18] = 0;
   out_6661166215902842056[19] = 0;
   out_6661166215902842056[20] = 0;
   out_6661166215902842056[21] = 0;
   out_6661166215902842056[22] = 1;
   out_6661166215902842056[23] = 0;
   out_6661166215902842056[24] = 0;
   out_6661166215902842056[25] = 0;
   out_6661166215902842056[26] = 0;
   out_6661166215902842056[27] = 0;
   out_6661166215902842056[28] = 0;
   out_6661166215902842056[29] = 0;
   out_6661166215902842056[30] = 0;
   out_6661166215902842056[31] = 0;
   out_6661166215902842056[32] = 0;
   out_6661166215902842056[33] = 0;
   out_6661166215902842056[34] = 0;
   out_6661166215902842056[35] = 0;
   out_6661166215902842056[36] = 0;
   out_6661166215902842056[37] = 0;
   out_6661166215902842056[38] = 0;
   out_6661166215902842056[39] = 0;
   out_6661166215902842056[40] = 0;
   out_6661166215902842056[41] = 1;
   out_6661166215902842056[42] = 0;
   out_6661166215902842056[43] = 0;
   out_6661166215902842056[44] = 0;
   out_6661166215902842056[45] = 0;
   out_6661166215902842056[46] = 0;
   out_6661166215902842056[47] = 0;
   out_6661166215902842056[48] = 0;
   out_6661166215902842056[49] = 0;
   out_6661166215902842056[50] = 0;
   out_6661166215902842056[51] = 0;
   out_6661166215902842056[52] = 0;
   out_6661166215902842056[53] = 0;
}
void h_14(double *state, double *unused, double *out_6080732506564879452) {
   out_6080732506564879452[0] = state[6];
   out_6080732506564879452[1] = state[7];
   out_6080732506564879452[2] = state[8];
}
void H_14(double *state, double *unused, double *out_7412133246909993784) {
   out_7412133246909993784[0] = 0;
   out_7412133246909993784[1] = 0;
   out_7412133246909993784[2] = 0;
   out_7412133246909993784[3] = 0;
   out_7412133246909993784[4] = 0;
   out_7412133246909993784[5] = 0;
   out_7412133246909993784[6] = 1;
   out_7412133246909993784[7] = 0;
   out_7412133246909993784[8] = 0;
   out_7412133246909993784[9] = 0;
   out_7412133246909993784[10] = 0;
   out_7412133246909993784[11] = 0;
   out_7412133246909993784[12] = 0;
   out_7412133246909993784[13] = 0;
   out_7412133246909993784[14] = 0;
   out_7412133246909993784[15] = 0;
   out_7412133246909993784[16] = 0;
   out_7412133246909993784[17] = 0;
   out_7412133246909993784[18] = 0;
   out_7412133246909993784[19] = 0;
   out_7412133246909993784[20] = 0;
   out_7412133246909993784[21] = 0;
   out_7412133246909993784[22] = 0;
   out_7412133246909993784[23] = 0;
   out_7412133246909993784[24] = 0;
   out_7412133246909993784[25] = 1;
   out_7412133246909993784[26] = 0;
   out_7412133246909993784[27] = 0;
   out_7412133246909993784[28] = 0;
   out_7412133246909993784[29] = 0;
   out_7412133246909993784[30] = 0;
   out_7412133246909993784[31] = 0;
   out_7412133246909993784[32] = 0;
   out_7412133246909993784[33] = 0;
   out_7412133246909993784[34] = 0;
   out_7412133246909993784[35] = 0;
   out_7412133246909993784[36] = 0;
   out_7412133246909993784[37] = 0;
   out_7412133246909993784[38] = 0;
   out_7412133246909993784[39] = 0;
   out_7412133246909993784[40] = 0;
   out_7412133246909993784[41] = 0;
   out_7412133246909993784[42] = 0;
   out_7412133246909993784[43] = 0;
   out_7412133246909993784[44] = 1;
   out_7412133246909993784[45] = 0;
   out_7412133246909993784[46] = 0;
   out_7412133246909993784[47] = 0;
   out_7412133246909993784[48] = 0;
   out_7412133246909993784[49] = 0;
   out_7412133246909993784[50] = 0;
   out_7412133246909993784[51] = 0;
   out_7412133246909993784[52] = 0;
   out_7412133246909993784[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_5361244045644666122) {
  err_fun(nom_x, delta_x, out_5361244045644666122);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_8995639648578932435) {
  inv_err_fun(nom_x, true_x, out_8995639648578932435);
}
void pose_H_mod_fun(double *state, double *out_401548470790065973) {
  H_mod_fun(state, out_401548470790065973);
}
void pose_f_fun(double *state, double dt, double *out_8900446657124786632) {
  f_fun(state,  dt, out_8900446657124786632);
}
void pose_F_fun(double *state, double dt, double *out_8518082037714010112) {
  F_fun(state,  dt, out_8518082037714010112);
}
void pose_h_4(double *state, double *unused, double *out_340313044583703153) {
  h_4(state, unused, out_340313044583703153);
}
void pose_H_4(double *state, double *unused, double *out_3448892390570509255) {
  H_4(state, unused, out_3448892390570509255);
}
void pose_h_10(double *state, double *unused, double *out_7998523049083505895) {
  h_10(state, unused, out_7998523049083505895);
}
void pose_H_10(double *state, double *unused, double *out_3744112959449252940) {
  H_10(state, unused, out_3744112959449252940);
}
void pose_h_13(double *state, double *unused, double *out_7266816994167798755) {
  h_13(state, unused, out_7266816994167798755);
}
void pose_H_13(double *state, double *unused, double *out_6661166215902842056) {
  H_13(state, unused, out_6661166215902842056);
}
void pose_h_14(double *state, double *unused, double *out_6080732506564879452) {
  h_14(state, unused, out_6080732506564879452);
}
void pose_H_14(double *state, double *unused, double *out_7412133246909993784) {
  H_14(state, unused, out_7412133246909993784);
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
