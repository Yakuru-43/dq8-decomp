// range: 0x304270 0x304310
#include "common.h"

void *func_001814D0(void);                                           /* extern */
void *func_002D05A0(void *);                                         /* extern */

s32 func_00304270(s32 kind, s32 index) {
    void *obj;
    void *base;

    obj = func_001814D0();
    base = func_002D05A0(obj);
    if (kind == 0) {
        if (index < 0 || index >= 0x10) {
            return -1;
        }
        return ((s32 *)((char *)base + 0x4090))[index];
    }
    if (kind != 1) {
        return -1;
    }
    if (index < 0 || index >= 0x40) {
        return -1;
    }
    return ((s16 *)((char *)base + 0x40D0))[index];
}
