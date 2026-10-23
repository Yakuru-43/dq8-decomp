// range: 0x305850 0x305870
#include "common.h"

extern s16 D_003E1144[] __attribute__((section(".sdata")));

void func_00305850(s32 index, s16 value) {
    D_003E1144[index] = value;
}
