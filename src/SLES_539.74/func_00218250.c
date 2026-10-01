// range: 0x218250 0x218260
// auto: m2c, verified byte-exact
#include "common.h"

extern s16 D_003DFD28;
extern s16 D_003DFD2C;

void func_00218250(s16 arg0, s16 arg1) {
    D_003DFD28 = arg0;
    D_003DFD2C = arg1;
}
