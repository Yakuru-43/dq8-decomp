// best draft for func_00213850 (attempt 2, CLASS structural score=209,
// 204 words differ, 896 vs 876 bytes) — factory-2 session 42, cut off by
// the 45-min session limit, not by the per-function limit (2/20 attempts).
// Also kept in src/SLES_539.74/func_00213850.c (uncommitted) with the
// float-arg fix for the mode==1 !flag74 call applied.
// range: 0x213850 0x213BC0
#include "common.h"

s32 func_0015F490(void);                                    /* extern */
s32 func_00141BF0();                                        /* extern */
void func_002112C0(s32);                                    /* extern */
void func_00141B00(s32);                                    /* extern */
void func_00214200(s32);                                    /* extern */
void func_00213FB0(s32);                                    /* extern */
void func_00214740(void);                                   /* extern */
void func_00129E60(char *, f32);                            /* extern */
s32 func_0015F450();                                        /* extern */
M2C_UNK func_0015AEF0(s32, char *, M2C_UNK);                /* extern */
s32 func_00212D40(char *);                                  /* extern */
s32 func_00200F80();                                        /* extern */
void func_001419A0(s32, s32, f32);                          /* extern */
void func_00214690(s32, s32);                               /* extern */
void func_00217FB0(s32, s32, s32, s32);                     /* extern */
void func_002179D0(s32, s32, s32, f32, f32);                /* extern */
s32 func_00167B20(void);                                    /* extern */
void func_00176F90(s32);                                    /* extern */
M2C_UNK func_00221F50(char *);                               /* extern */
s32 func_001FFC30(s32);                                     /* extern */
void func_003731B0(s32, s32, s32, s32);                     /* extern */

extern char *D_003E0908;
extern u8 D_003DFD0C;
extern s8 D_003E08F0;
extern u8 D_003E0900;
extern u8 D_003E0940;
extern char *D_003E0944;
extern f32 D_003DF688;
extern f32 D_003DF778;
extern char D_003C7CE0[];
extern s32 (*D_003DFD20[])(s32, s32);

void func_00213850(void) {
    s32 handle;
    s32 idx;
    s32 other;
    s32 r1;
    s32 obj;
    s32 cnt;
    s32 arg;
    s32 src;
    s32 msg;
    s32 r2;

    handle = func_0015F490();
    idx = D_003DFD0C;
    other = idx ^ 1;
    r1 = D_003DFD20[idx](-1, *(s32 *)(D_003E0908 + idx * 4 + 0x418));
    D_003DFD20[other](r1, *(s32 *)(D_003E0908 + other * 4 + 0x418));
    obj = func_00200F80();
    if (obj == 0) {
        return;
    }
    if (D_003E08F0 > 0) {
        func_00214740();
    }
    r2 = func_00141BF0();
    func_002112C0(handle);
    func_00141B00(r2);
    func_00214200(handle);
    func_00213FB0(D_003DFD0C);
    if ((f32) *(s32 *)(D_003E0908 + 0x414) >= 128.0f) {
        func_00129E60(D_003E0908, *(f32 *)(D_003E0908 + 0x480));
        func_0015AEF0(func_0015F450(), D_003C7CE0, -1);
        arg = func_00212D40(D_003E0908);
        if (D_003DFD0C == 0) {
            func_00214690(0, *(s32 *)(D_003E0908 + 0x418));
            if (*(s32 *)(D_003E0908 + 0x24) != 0 && D_003E0940 != 0) {
                if (*(u8 *)(D_003E0944 + 0x74) != 0) {
                    func_00217FB0(0, arg, *(s32 *)(D_003E0908 + 0x418), 0);
                    cnt = (s32) *(f32 *)(D_003E0908 + 0x698);
                } else {
                    func_001419A0(handle, *(s16 *)obj, 1.0f);
                    func_002179D0(0, arg, *(s32 *)(D_003E0908 + 0x418), 1.0f,
                                 3.0f);
                    cnt = (s32) *(f32 *)(D_003E0908 + 0x624);
                }
            }
        }
        if (D_003DFD0C == 1) {
            func_00214690(1, *(s32 *)(D_003E0908 + 0x41C));
            if (*(u8 *)(D_003E0944 + 0x74) != 0) {
                func_00217FB0(1, 0x80, *(s32 *)(D_003E0908 + 0x41C), 0);
            } else {
                func_001419A0(handle, *(s16 *)obj, 1.0f);
                func_002179D0(1, arg, *(s32 *)(D_003E0908 + 0x41C),
                              D_003DF688, D_003DF778);
            }
        }
    } else {
        cnt = 0;
    }
    if (*(s32 *)(D_003E0908 + 0x5FC) != 0) {
        func_00176F90(func_00167B20());
        func_001419A0(handle,
                      *(s32 *)(*(s32 *)(D_003E0908 + 0x5FC) + 0x1668), 1.0f);
        func_00221F50(D_003E0908);
        return;
    }
    if (*(s32 *)(D_003E0908 + 0x414) < 128) {
        return;
    }
    src = obj;
    if (D_003DFD0C == 1) {
        src = 0x190;
        msg = 3000;
    } else if (D_003DFD0C != 0) {
        msg = 3002;
    } else if (D_003E0940 != 0) {
        msg = 3001;
    } else {
        msg = 3002;
    }
    if (D_003E0900 == 1 || D_003E0900 == 2) {
        msg = 3003;
    }
    if (D_003DFD0C == 0 && cnt >= 257) {
        src = 0x14;
    }
    func_003731B0(func_001FFC30(msg), src, 0x190, 1);
}
