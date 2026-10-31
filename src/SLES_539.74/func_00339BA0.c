// range: 0x339BA0 0x339C60
#include "common.h"

struct Table {
    s32 field_00;
    s32 count;
    char *low;
    s32 field_0C;
    char *high;
};

void func_00339BA0(struct Table *tbl, s32 key, s32 value) {
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
        *(s32 *)(e + 0x84) = value;
    }
}
