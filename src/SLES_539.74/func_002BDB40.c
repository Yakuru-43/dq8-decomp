// range: 0x2BDB40 0x2BDBA0
#include "common.h"

extern void func_002C0A00(s32, s32);

void func_002BDB40(s32 arg0) {
    s32 var_s0;

    func_002C0A00(arg0, 1);
    func_002C0A00(arg0, 4);
    var_s0 = 0;
    do {
        func_002C0A00(arg0, var_s0 + 0x64);
        var_s0 += 1;
    } while (var_s0 < 0x12);
}
