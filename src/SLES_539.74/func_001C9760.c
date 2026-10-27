// range: 0x1C9760 0x1C9830
#include "common.h"

s32 func_001A2190(s32);
s32 func_0024CF90(s32);
void func_002F5FE0(char *, s32, s32);

s32 func_001C9760(char *arg0) {
    s32 val;
    s32 a1;
    s32 a2;
    s32 a3;
    char *ret;
    char *base;

    if (*(s32 *)(arg0 + 0) == 1) {
        val = (s32)*(f32 *)(arg0 + 4);
    } else {
        val = *(s32 *)(arg0 + 4);
    }

    ret = (char *)func_001A2190(val);
    if (ret == 0) {
        return 0;
    }

    base = arg0 + 8;
    if (*(s32 *)(arg0 + 8) == 1) {
        a1 = (s32)*(f32 *)(base + 4);
    } else {
        a1 = *(s32 *)(base + 4);
    }

    if (*(s32 *)(arg0 + 0x10) == 1) {
        a2 = (s32)*(f32 *)(arg0 + 0x14);
    } else {
        a2 = *(s32 *)(arg0 + 0x14);
    }

    a3 = func_0024CF90(a2);
    func_002F5FE0(ret, a1 - 1, a3);
    return 1;
}
