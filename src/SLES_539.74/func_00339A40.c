// range: 0x339A40 0x339B00
#include "common.h"

struct Table {
    s32 field_00;
    s32 count;
    char *low;
    s32 field_0C;
    char *high;
};

s32 func_00339A40(struct Table *tbl, s32 key) {
    char *base;
    char *e;
    s32 count;
    s32 i;
    s32 ret;

    ret = -1;
    base = tbl->low;
    if (base == 0) {
        e = 0;
    } else {
        count = tbl->count;
        for (i = 0; i < count; i++) {
            if (i < 32) {
                e = base + i * 0x220;
                if (key == *(s32 *)(e + 0x184)) {
                    goto found;
                }
            } else {
                if (key == *(s32 *)(tbl->high + i * 0x220 - 0x427C)) {
                    e = tbl->high + (i - 32) * 0x220;
                    goto found;
                }
            }
        }
        e = 0;
    }
found:
    if (e != 0) {
        ret = *(s16 *)(e + 0x188);
    }
    return ret;
}
