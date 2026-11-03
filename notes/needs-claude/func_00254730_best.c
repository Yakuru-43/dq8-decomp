// range: 0x254730 0x254A20
#include "common.h"

void func_0010AD40(char *, char *, char *, f32);
char *func_00130FD0(char *, const char *, u32);

void func_00254730(char *arg0, char *arg1, char *arg2, s32 arg3, f32 t) {
    f32 sumA;
    f32 sumB;
    f32 diff;
    f32 base;
    s32 d;
    s32 i;
    s32 n;
    u8 *p0;
    u8 *p1;
    u8 *p2;

    if (arg0 == 0) {
        return;
    }
    if ((arg1 == 0) || (arg2 == 0)) {
        if (arg1 != 0) {
            func_00130FD0(arg0, arg1, 0x1D0);
        }
        if (arg2 != 0) {
            func_00130FD0(arg0, arg2, 0x1D0);
        }
        return;
    }
    func_0010AD40(arg0 + 0x10, arg1 + 0x10, arg2 + 0x10, t);
    func_0010AD40(arg0 + 0x20, arg1 + 0x20, arg2 + 0x20, t);
    func_0010AD40(arg0 + 0x190, arg1 + 0x190, arg2 + 0x190, t);
    func_0010AD40(arg0 + 0x180, arg1 + 0x180, arg2 + 0x180, t);
    for (i = 0; i < 4; i++) {
        func_0010AD40(arg0 + i * 0x10 + 0x30, arg1 + i * 0x10 + 0x30, arg2 + i * 0x10 + 0x30, t);
        func_0010AD40(arg0 + i * 0x10 + 0x70, arg1 + i * 0x10 + 0x70, arg2 + i * 0x10 + 0x70, t);
    }
    *(s32 *)(arg0 + 0x1A0) = *(s32 *)(arg1 + 0x1A0);
    if (arg3 == 0) {
        func_00130FD0(arg0 + 0x1A4, arg1 + 0x1A4, 0x20);
        return;
    }
    p0 = (u8 *)arg0 + 0x1A4;
    p1 = (u8 *)arg1 + 0x1A4;
    p2 = (u8 *)arg2 + 0x1A4;
    sumA = 0.0f;
    base = *(f32 *)(p2 + 0);
    diff = *(f32 *)(p1 + 0);
    sumA += base;
    diff = diff - base;
    diff = diff + t * diff;
    *(f32 *)(p0 + 0) = diff;
    base = *(f32 *)(p2 + 4);
    diff = *(f32 *)(p1 + 4);
    sumA += base;
    diff = diff - base;
    diff = diff + t * diff;
    *(f32 *)(p0 + 4) = diff;
    for (n = 0; n < 4; n++) {
        d = (s32)p1[8 + n] - (s32)p2[8 + n];
        base = (f32)(u32)p2[8 + n];
        sumA += base;
        base = base + t * (f32)d;
        p0[8 + n] = (u8)(u32)base;
    }
    sumB = 0.0f;
    base = *(f32 *)(p2 + 0x10);
    diff = *(f32 *)(p1 + 0x10);
    sumB += base;
    diff = diff - base;
    diff = diff + t * diff;
    *(f32 *)(p0 + 0x10) = diff;
    base = *(f32 *)(p2 + 0x14);
    diff = *(f32 *)(p1 + 0x14);
    sumB += base;
    diff = diff - base;
    diff = diff + t * diff;
    *(f32 *)(p0 + 0x14) = diff;
    base = *(f32 *)(p2 + 0x18);
    diff = *(f32 *)(p1 + 0x18);
    sumB += base;
    diff = diff - base;
    diff = diff + t * diff;
    *(f32 *)(p0 + 0x18) = diff;
    base = *(f32 *)(p2 + 0x1C);
    diff = *(f32 *)(p1 + 0x1C);
    sumB += base;
    diff = diff - base;
    diff = diff + t * diff;
    *(f32 *)(p0 + 0x1C) = diff;
}
