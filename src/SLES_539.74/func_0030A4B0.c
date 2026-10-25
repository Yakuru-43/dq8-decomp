// range: 0x30A4B0 0x30A590
#include "common.h"

s32 func_0024C670(s32);                                /* extern */
void func_001339E0(char *, char *, s32);                /* extern */
s32 func_0015F450();                                    /* extern */
s32 func_0015AEF0(s32, char *, s32);                    /* extern */
extern char D_003D0238[];

s32 func_0030A4B0(s32 arg0, s32 *arg1, s32 *arg2, s32 arg3) {
    char buf40[0x20];
    s32 count;
    s32 page;
    s32 mgr;

    *arg1 = 0;
    *arg2 = 0;
    count = func_0024C670(arg0);
    if (count >= 0) {
        page = count % 64;
        *arg1 = (page % 8) << 5;
        *arg2 = (page / 8) << 5;
        func_001339E0(buf40, D_003D0238, count / 64 + 1);
        mgr = func_0015F450();
        return func_0015AEF0(mgr, buf40, arg3);
    }
    return 0;
}
