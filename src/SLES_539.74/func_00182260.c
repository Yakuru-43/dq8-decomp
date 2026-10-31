// range: 0x182260 0x1822C0
#include "common.h"

s32 func_00182F50(void);
s32 func_003530B0(void);
extern s32 D_003DFC54;
extern s32 D_003DFC58;
extern s32 D_003DFC5C;
extern s32 D_003DFC60;
extern s16 D_003E04E0;

s32 func_00182260(void) {
    if (func_00182F50() != 0) {
        return D_003DFC58;
    }
    if (func_003530B0() != 0) {
        return D_003DFC5C;
    }
    if (D_003E04E0 == 2) {
        return D_003DFC60;
    }
    return D_003DFC54;
}
