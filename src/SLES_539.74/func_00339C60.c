// range: 0x339C60 0x339D00
#include "common.h"

struct Table {
    s32 field_00;
    s32 count;
    char *low;
    s32 field_0C;
    char *high;
};

s32 func_00339C60(struct Table *tbl, s32 key) {
    char *base;
    char *e;
    s32 count;
    s32 i;

    base = tbl->low;
    if (base == 0) {
        e = 0;
    } else {
        count = tbl->count;
        for (i = 0; i < count; i++) {
            if (i < 32) {
                e = base + i * 0x220;
                if (key == *(s32 *)(e + 0x180)) {
                    goto found;
                }
            } else {
                if (key == *(s32 *)(tbl->high + i * 0x220 - 0x4280)) {
                    e = tbl->high + (i - 32) * 0x220;
                    goto found;
                }
            }
        }
        e = 0;
    }
found:
    if (e != 0) {
        return *(s32 *)(e + 0x184);
    }
    return -1;
}
