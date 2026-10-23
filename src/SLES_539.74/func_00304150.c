// range: 0x304150 0x304200
#include "common.h"

void *func_001814D0(void);                                           /* extern */
void *func_002D05A0(void *);                                         /* extern */
s64 func_0020F5E0(void *);                                           /* extern */
s64 func_00167FB0(void);                                             /* extern */
void func_00304CC0(void *);                                          /* extern */
void func_00304380(s32, s32, s64);                                   /* extern */

void func_00304150(s32 mode) {
    void *obj;
    void *base;
    s64 t;
    s64 u;
    s32 total;

    obj = func_001814D0();
    if (obj == 0) {
        return;
    }
    base = func_002D05A0(obj);
    if (base == 0) {
        return;
    }
    if (mode == 0) {
        func_00304CC0(base);
    }
    if (mode == 1) {
        t = func_0020F5E0(obj);
        u = func_00167FB0();
        total = t + u;
        func_00304380(0, 0, total);
    }
}
