// range: 0x4717E0 0x471850
#include "common.h"

s32 func_00471850(s32, s32 *, s32 *);
s32 func_1339E0(s32, char *, ...);
extern char D_00484430[];
extern char D_00484440[];

s32 func_004717E0(s32 arg0, s32 arg1) {
    s32 sp2C;
    s32 sp28;

    if (func_00471850(arg1, &sp2C, &sp28) == 1) {
        return func_1339E0(arg0, D_00484440, sp2C, sp28);
    }
    return func_1339E0(arg0, D_00484430);
}
