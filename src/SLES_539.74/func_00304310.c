// range: 0x304310 0x304380
#include "common.h"

void *func_001814D0(void);                                           /* extern */
void *func_002D05A0(void *);                                         /* extern */

void func_00304310(s32 kind, s32 index, s32 value) {
    void *obj;
    void *base;

    obj = func_001814D0();
    base = func_002D05A0(obj);
    if (kind != 4) {
        return;
    }
    if (index < 0 || index >= 0x10) {
        return;
    }
    ((s32 *)((char *)base + 0x4154))[index] = value;
}
