// range: 0x376BD0 0x376BE0
// auto: m2c, verified byte-exact
#include "common.h"

extern s8 D_003E1508;
extern s8 D_003E150C;

void func_00376BD0(s8 arg0) {
    D_003E150C = arg0;
    D_003E1508 = 0;
}
