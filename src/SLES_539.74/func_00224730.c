// range: 0x224730 0x224770
#include "common.h"

extern s32 *D_003E0A18;

s32 *func_00224730(s32 index) {
    if (index >= 0 && index < D_003E0A18[0]) {
        return D_003E0A18 + index + 0xC;
    }
    return 0;
}
