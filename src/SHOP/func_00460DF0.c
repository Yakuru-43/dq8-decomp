// range: 0x460DF0 0x460ED0
#include "common.h"

s32 func_181420();                                   /* extern */
s32 func_00462AD0(void);                             /* extern */
s32 func_205D30(s32, s32);                            /* extern */
s32 func_206080(s32, s32);                            /* extern */
s32 func_00460ED0(s32);                               /* extern */

s32 func_00460DF0(s32 arg0) {
    s32 shop;
    s32 sum;
    s32 target;
    s32 i;
    s32 kind;
    s32 ok;

    shop = func_181420();
    sum = 0;
    target = func_00462AD0();
    for (i = 0; i < 5; i++) {
        kind = func_205D30(shop, i);
        if (kind != 4) {
            ok = func_206080(shop, kind);
            if (ok == 0) {
                continue;
            }
        }
        if (arg0 != 0) {
            sum += func_00460ED0(kind);
            continue;
        }
        if (target == kind) {
            sum = func_00460ED0(target);
        }
    }
    return sum;
}
