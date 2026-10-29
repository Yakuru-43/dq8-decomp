// range: 0x1822C0 0x182320
#include "common.h"

s32 func_00182F50(void);
s32 func_003530B0(void);
extern s32 D_003DFC44;
extern s32 D_003DFC48;
extern s32 D_003DFC4C;
extern s32 D_003DFC50;
extern s16 D_003E04E0;

s32 func_001822C0(void) {
    if (func_00182F50() != 0) {
        return D_003DFC48;
    }
    if (func_003530B0() != 0) {
        return D_003DFC4C;
    }
    if (D_003E04E0 == 2) {
        return D_003DFC50;
    }
    return D_003DFC44;
}
