// range: 0x305830 0x305850
#include "common.h"

extern s16 D_003E1144[] __attribute__((section(".sdata")));

s16 func_00305830(s32 index) {
    return D_003E1144[index];
}
