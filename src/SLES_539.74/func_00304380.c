// range: 0x304380 0x304430
#include "common.h"

void *func_001814D0(void);                                           /* extern */
void *func_002D05A0(void *);                                         /* extern */

void func_00304380(s32 kind, s32 index, s32 value) {
    void *obj;
    void *base;

    obj = func_001814D0();
    base = func_002D05A0(obj);
    if (kind == 0) {
        if (index < 0 || index >= 0x10) {
            return;
        }
        ((s32 *)((char *)base + 0x4090))[index] = value;
    }
    if (kind == 1) {
        if (index < 0 || index >= 0x40) {
            return;
        }
        ((s16 *)((char *)base + 0x40D0))[index] = value;
    }
}
