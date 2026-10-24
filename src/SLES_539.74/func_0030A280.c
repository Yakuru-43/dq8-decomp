// range: 0x30A280 0x30A320
#include "common.h"

s32 func_001629F0(char *, s32, s32 *);                  /* extern */
s32 func_0014E240(s32, s32);                             /* extern */
s32 func_00130FD0(s32, s32, s32);                        /* extern */
s32 func_0015F450();                                     /* extern */
void func_0015A4A0(s32, s32, s32, s32, s32);              /* extern */
extern char *D_003DFFA0;

void func_0030A280(s32 arg0, s32 arg1, s32 arg2) {
    s32 out;
    s32 alloc;
    s32 mgr;

    if (func_001629F0(D_003DFFA0, arg0, &out) != 0) {
        alloc = func_0014E240(arg1, (out >> 4) + 1);
        func_00130FD0(alloc, arg0, out);
        mgr = func_0015F450();
        func_0015A4A0(mgr, alloc, arg2, 0, 0);
    }
}
