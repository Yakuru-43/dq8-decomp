// range: 0x3138C0 0x313970
#include "common.h"

s32 func_001EC070(s32 *arg0, s32 arg1);              /* extern */
char *func_00161E80(s32 arg0, s32 arg1, s32 *arg2);  /* extern */
void func_001FABC0(s32 arg0, s32 arg1, char *arg2, s32 arg3, s32 arg4); /* extern */

void func_003138C0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 i;
    s32 item;
    char *r;

    for (i = 0;; i++) {
        item = func_001EC070(arg0, i);
        if (item == 0) {
            return;
        }
        r = func_00161E80(arg3, item, 0);
        if (r != 0) {
            func_001FABC0(arg2, item, r, arg1, 0);
        }
    }
}
