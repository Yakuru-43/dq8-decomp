// Best draft for func_004728F0 (CASINO), NOT a match — 232 vs 228 bytes,
// CLASS structural score=41. See func_004728F0.md.
// range: 0x4728F0 0x4729E0
#include "common.h"

extern void func_131188(void *, s32, s32); /* memset */
extern void func_00460720(s32, char *, char *);

s32 func_004728F0(char *arg0, s32 arg1, s32 arg2) {
    char *base;
    char *p;
    s32 i;

    if (*(s32 *)(arg0 + (arg1 << 2)) != 0) {
        return 0;
    }
    *(s32 *)(arg0 + (arg1 << 2)) = arg2;
    *(s32 *)(arg0 + (arg1 << 2) + 0x550) = 0;
    *(s32 *)(arg0 + (arg1 << 2) + 0x5A0) = 0;
    *(s32 *)(arg0 + (arg1 << 2) + 0x5F0) = 0;
    base = arg0 + arg1 * 2816;
    for (i = 0; i < 20; i++) {
        p = base + i * 88;
        func_131188(p + 0x640, 0, 0x58);
    }
    *(s32 *)(p + 0x640) = 0;
    func_00460720(arg2, arg0 + (arg1 << 2) + 0x50, arg0 + (arg1 << 2) + 0xA0);
    return 1;
}
