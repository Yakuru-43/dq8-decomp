// range: 0x377F90 0x377FA0
// auto: m2c, verified byte-exact
#include "common.h"

extern s32 D_003E14D4;

s32 func_00377F90(s32 arg0) {
    return (D_003E14D4 & arg0) != 0;
}
