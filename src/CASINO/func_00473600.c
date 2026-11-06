// range: 0x473600 0x4736B0
#include "common.h"

extern void func_131188(char *, s32, s32);

void func_00473600(char *table, s32 idx, char *node) {
    char *prev;
    char *next;

    prev = *(char **)(node + 0x50);
    next = *(char **)(node + 0x54);
    if (prev != 0) {
        *(char **)(prev + 0x54) = next;
    }
    if (next != 0) {
        *(char **)(next + 0x50) = prev;
    }
    if (prev == 0 && next == 0) {
        ((s32 *)(table + 0x5A0))[idx] = 0;
        ((s32 *)(table + 0x5F0))[idx] = 0;
    }
    if (prev == 0 && next != 0) {
        ((char **)(table + 0x5F0))[idx] = next;
    }
    if (prev != 0 && next == 0) {
        ((char **)(table + 0x5A0))[idx] = prev;
    }
    *(s32 *)node = 0;
    *(s32 *)(node + 0x50) = 0;
    *(s32 *)(node + 0x54) = 0;
    func_131188(node + 0x10, 0, 0x20);
}
