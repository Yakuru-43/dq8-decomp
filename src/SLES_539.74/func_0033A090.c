// range: 0x33A090 0x33A130
#include "common.h"

struct Table {
    s32 field_00;
    s32 count;
    char *low;
    s32 field_0C;
    char *high;
};

char *func_0033A090(struct Table *tbl, s32 id) {
    char *node;
    s32 i;

    if (tbl->low == 0) {
        return 0;
    }
    for (i = 0; i < tbl->count; i++) {
        if (i < 32) {
            node = tbl->low + i * 0x220;
            if (id == *(s32 *)(node + 0x184)) {
                return node;
            }
        } else {
            if (*(s32 *)(tbl->high + i * 0x220 - 0x427C) == id) {
                return tbl->high + (i - 32) * 0x220;
            }
        }
    }
    return 0;
}
