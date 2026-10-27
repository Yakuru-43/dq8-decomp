// range: 0x17B9F0 0x17BA90
#include "common.h"

s32 func_0019A250(void);
s32 func_00345E80(void);
s32 func_003515A0(void);
char *func_0016DF20(char *, s32);
char *func_00189AF0(char *);
char *func_00350EA0(void);
extern s32 D_003DFC2C;

s32 func_0017B9F0(char *arg0) {
    s32 var_s0;
    char *var_v0;

    var_s0 = 0;
    if (func_0019A250() != 0) {
        var_v0 = func_00189AF0(arg0);
    } else {
        if (func_003515A0() != 0) {
            var_v0 = func_00350EA0();
        } else {
            var_v0 = func_0016DF20(arg0, *(s32 *)(arg0 + 0x44BC));
        }
    }
    if (var_v0 != NULL) {
        var_s0 = *(s32 *)(var_v0 + 0x244);
        if ((func_0019A250() != 0) && (func_00345E80() != 0)) {
            var_s0 = D_003DFC2C;
        }
    }
    return var_s0;
}
