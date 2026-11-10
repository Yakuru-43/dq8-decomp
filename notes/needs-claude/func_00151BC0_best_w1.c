// range: 0x00151BC0 0x00151C90
#include "common.h"

typedef struct NameEntry151BC0 {
    s8 *name; /* 0x00 */
} NameEntry151BC0;

typedef struct NameList151BC0 {
    s32 count;              /* 0x00 */
    NameEntry151BC0 **items; /* 0x04 */
} NameList151BC0;

s32 func_00151BC0(void *o, s8 *name) {
    NameList151BC0 *arr;
    NameEntry151BC0 *e;
    s32 i;
    s8 *pa;
    s8 *pb;
    s32 ok;

    arr = M2C_FIELD(o, NameList151BC0 **, 0x104);
    if (name == 0) {
        return -1;
    }
    if (arr == 0) {
        return -1;
    }
    for (i = 0; i < arr->count; i++) {
        e = arr->items[i];
        if (e == 0) {
            continue;
        }
        pa = e->name;
        if (pa == 0) {
            continue;
        }
        pb = name;
        if (*pa != *pb) {
            ok = 0;
            goto tested;
        }
        while (*pa != 0) {
            if (*pa != *pb) {
                ok = 0;
                goto tested;
            }
            pa = pa + 1;
            pb = pb + 1;
        }
        ok = *pb == 0;
    tested:
        if (ok) {
            return i;
        }
    }
    return -1;
}
