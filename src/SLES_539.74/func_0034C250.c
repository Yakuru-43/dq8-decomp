// range: 0x34C250 0x34C2F0
#include "common.h"

void *func_0034B240(s32, s32);                        /* extern */
s32 func_0034D790();                                   /* extern */
void *func_0024B7B0(s32, s32);                         /* extern */
char *func_00130FD0(char *, const char *, u32);        /* extern */

s32 func_0034C250(s32 arg0, s32 arg1, void *arg2, void **arg3) {
    s32 value;
    void *record;
    void *src;

    if (arg3 != 0) {
        *arg3 = 0;
    }
    record = func_0034B240(arg0, arg1);
    if (record == 0) {
        return -1;
    }
    value = *(s16 *)record;
    src = func_0024B7B0(func_0034D790(), arg1);
    if (src == 0) {
        return -1;
    }
    func_00130FD0(arg2, src, 1);
    if (arg3 != 0) {
        *arg3 = record;
    }
    return value;
}
