// range: 0x314870 0x314950
#include "common.h"

s32 func_0012C080(s32, s32, s32);
s32 func_0012C1E0(s32);
s32 func_0012C548(s32, s32, s32);
s32 func_0012C6C0(s32, s32, s32 *);

s32 func_00314870(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp5C;
    s32 var_s1;
    s32 var_s0;

    var_s1 = 1;
    if (func_0012C080(0, 0, arg0) < 0) {
        return 0;
    }
    func_0012C6C0(0, 0, &sp5C);
    var_s0 = sp5C;
    if (var_s0 < 0) {
        return 0;
    }
    if (func_0012C548(var_s0, arg1, arg2) < 0) {
        return 0;
    }
    func_0012C6C0(0, 0, &sp5C);
    if (sp5C != arg2) {
        var_s1 = 0;
    }
    if (func_0012C1E0(var_s0) < 0) {
        return 0;
    }
    func_0012C6C0(0, 0, &sp5C);
    return var_s1;
}
