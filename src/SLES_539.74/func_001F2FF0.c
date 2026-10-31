// range: 0x1F2FF0 0x1F3060
#include "common.h"

s32 func_001F2FF0(char *arg0, s32 arg1) {
    s32 table;
    void **node;
    void *next;
    s32 count;

    table = *(s32 *)(arg0 + 4);
    if (table == 0) {
        return 0;
    }
    if (arg1 < 0 || arg1 >= 0xD) {
        return 0;
    }
    node = *(void **)(table + (arg1 * 4));
    if (node == 0) {
        return 0;
    }
    next = *node;
    count = 1;
    while (next != 0) {
        next = *(void **)next;
        count += 1;
    }
    return count;
}
