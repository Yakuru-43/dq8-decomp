// range: 0x2915F0 0x291670
#include "common.h"

M2C_UNK func_00292C60();                            /* extern */

typedef struct {
    char pad0[0x590];
    s32 unk590[6];
    s32 unk5A8[6];
    s32 unk5C0[6];
} S_arg0;

s32 func_002915F0(S_arg0 *arg0, u8 arg1) {
    s32 *sel;

    if (arg1 == 2) {
        sel = arg0->unk5C0;
    } else if (arg1 == 1) {
        sel = arg0->unk5A8;
    } else {
        sel = arg0->unk590;
    }
    if (func_00292C60(arg0) == 0) {
        return sel[0] + sel[1];
    }
    return sel[2] + sel[3] + sel[4] + sel[5];
}
