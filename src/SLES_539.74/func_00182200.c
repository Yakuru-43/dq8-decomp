// range: 0x182200 0x182260
#include "common.h"

s32 func_00182F50(void);
s32 func_001831A0(void);
s32 func_003530B0(void);
extern s32 D_003DFC64;
extern s32 D_003DFC68;
extern s32 D_003DFC6C;
extern s32 D_003DFC70;

s32 func_00182200(void) {
    if (func_00182F50() != 0) {
        return D_003DFC68;
    }
    if (func_001831A0() != 0) {
        return D_003DFC6C;
    }
    if (func_003530B0() != 0) {
        return D_003DFC70;
    }
    return D_003DFC64;
}
