// range: 0x339F30 0x339FE0
#include "common.h"

struct Table {
    s32 field_00;
    s32 count;
    char *low;
    s32 field_0C;
    char *high;
};

s32 func_00339F30(struct Table *tbl, s32 flag) {
    char *node;
    s32 count;
    s32 i;
    s32 result;

    count = tbl->count;
    result = 0;
    for (i = 0; i < count; i++) {
        if (tbl->low != 0 && i >= 0 && i < count) {
            if (i < 32) {
                node = tbl->low + i * 0x220;
            } else {
                node = tbl->high + (i - 32) * 0x220;
            }
        } else {
            node = 0;
        }
        if (node != 0) {
            if (flag == 0) {
                if (*(s8 *)(node + 0x1D2) == 0) {
                    result++;
                }
            }
        }
    }
    return result;
}
