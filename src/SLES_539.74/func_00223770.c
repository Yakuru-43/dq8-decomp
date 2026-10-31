// range: 0x223770 0x2237B0
#include "common.h"

extern s16 *D_003E0A1C;

s32 func_00223770(s32 index) {
    if (index < 0 || D_003E0A1C[0] < index) {
        return 0;
    }
    return D_003E0A1C[index + 0x12];
}
