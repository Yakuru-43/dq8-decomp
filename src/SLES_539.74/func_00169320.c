// range: 0x169320 0x169390
#include "common.h"

extern void func_00131188(char *, s32, s32);
extern s32 func_0015C030(char *);
extern s32 func_0019B1E0(char *);

s32 func_00169320(char *arg0) {
    char *var_s0;

    func_0015C030(arg0 + 0x20);
    var_s0 = arg0 + 0x90;
    do {
        func_00131188(var_s0, 0, 0x20);
        var_s0 += 0x20;
    } while (var_s0 < arg0 + 0x310);
    func_0019B1E0(arg0);
    return (s32)arg0;
}
