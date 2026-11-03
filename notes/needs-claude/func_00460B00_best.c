// Best attempt for func_00460B00 — NOT matched, do not build with this file.
// See func_00460B00.md for the analysis and what to fix.
// range: 0x460B00 0x460E80
#include "common.h"

void func_13E2D0(s32, s32);
void func_13E2F0(s32, s32);
void func_13EB30(s32, s16 *);
void func_13EBF0(s32, s32, s32);
void func_13ECD0(s32, s32, s32, s32, s32);
void func_13EEE0(s32, f32, f32, f32);
void func_13EF90(s32, s32, s32, s32);
void func_13F450(s32);
void func_13F6C0(s32, s32);
void func_1419A0(s32, s32, f32);
s32 func_141B00(s32);
s32 func_141BF0(s32);
s32 func_145440(s32);
s32 func_145450(s32);
s32 func_15F490(void);
void func_176F90(s32);
void func_22B020(s32, s32, s32, s32, s32, s32, s32, s32, s64, s64, s64, s64);
void func_22B120(s32, s32);

extern s32 D_003E1C40;
extern s16 *D_003E1C6C;
extern u8 D_003E1C78;
extern s32 D_003E1C70;
extern s32 D_003E1C74;
extern f32 D_003E1C8C;
extern s32 D_004643CC __attribute__((section(".data")));
extern s32 D_004643D0 __attribute__((section(".data")));
extern s32 D_00464400 __attribute__((section(".data")));

void func_00460B00(void) {
    s32 obj;
    s32 pane;
    s32 handle;
    s32 count;
    f32 width;
    f32 height;
    f32 half;
    f32 scaled;
    f32 delta;
    f32 scaled2;
    f32 remain;

    obj = func_15F490();
    if (D_004643CC != 0) {
        pane = func_141BF0(obj);
        func_22B120(pane, 2);
        func_13E2D0(pane, 0);
        func_13F6C0(pane, 6);
        func_13ECD0(pane, 0xFF, 0xFF, 0xFF, D_004643D0);
        func_13EF90(pane, 0, 0, 0);
        handle = func_145450(obj);
        func_13EF90(pane, handle, func_145440(obj), 0);
        func_13F450(pane);
        func_141B00(obj);
    }
    if (0 < D_003E1C74 && D_003E1C6C != 0) {
        count = 0;
        width = (f32)func_145450(obj);
        height = (f32)func_145440(obj);
        if (D_003E1C78 != 0) {
            count = D_003E1C74;
        }
        half = 0.5f * (f32)height;
        scaled = half * 1.0f;
        func_1419A0(obj, *D_003E1C6C, 1.0f);
        delta = half - scaled;
        D_003E1C8C = D_003E1C8C + 1.0f;
        if (512.0f <= D_003E1C8C) {
            D_003E1C8C = 0.0f;
        }
        remain = 512.0f - D_003E1C8C;
        handle = func_141BF0(obj);
        func_22B120(handle, 0);
        func_13E2F0(handle, 1);
        func_13F6C0(handle, 6);
        func_13EB30(handle, D_003E1C6C);
        func_13ECD0(handle, 0x80, 0x80, 0x80, count);
        func_13EBF0(handle, 0, 0);
        func_13EEE0(handle, D_003E1C8C, delta, 0.0f);
        func_13EBF0(handle, (s32)(remain - 1.0f), 0x19F);
        scaled2 = delta + 2.0f * scaled;
        func_13EEE0(handle, D_003E1C8C + remain, scaled2, 0.0f);
        func_13EBF0(handle, (s32)remain, 0);
        func_13EEE0(handle, 0.0f, delta, 0.0f);
        func_13EBF0(handle, 0x1FF, 0x19F);
        func_13EEE0(handle, D_003E1C8C, scaled2, 0.0f);
        func_13F450(handle);
        if (D_003E1C70 != 0) {
            func_13E2F0(handle, 1);
            func_22B020(handle, D_003E1C70, 0, 0, (s32)width,
                        (s32)height, 0, 0, 0x200, 0x1C0, 0x80, count);
        }
        func_141B00(obj);
    }
    if (*(u8 *)(D_003E1C40 + 0x34) == 0) {
        func_1419A0(obj, 0xD3, 1.0f);
        func_176F90(D_00464400);
    }
}
