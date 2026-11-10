// session-end best draft for func_00462CF0 (MENU, 992 B), 2026-11-03 factory-6.
// NOT a match (try_match attempt 1: CLASS structural score=78, 1000 vs 992 B,
// first real diff at +0x28: prologue daddu $s0,$a0 vs orig daddu $s0,$v0 --
// CW's $s0 capture sits differently). Kept for the next session; src/ must stay
// clean so the build links.
// range: 0x462CF0 0x4630D0
#include "common.h"

s32 func_0045F120(char *);                            /* extern */
s32 func_00463360(s8);                                /* extern */
s32 func_181420();                                    /* extern */
s32 func_1814D0();                                    /* extern */
char *func_201C90();                                  /* extern */
s32 func_201CC0();                                    /* extern */
s32 func_201E70(M2C_UNK, M2C_UNK);                    /* extern */
s32 func_205050(s32, s32, M2C_UNK);                   /* extern */
s32 func_205D30(s32, s32);                            /* extern */
s32 func_25ED30(s32, s32, s32, s32, s32 *);           /* extern */
M2C_UNK func_2D38E0(s32, M2C_UNK, M2C_UNK, M2C_UNK);  /* extern */
s32 func_3084D0(s32, M2C_UNK);                        /* extern */
char *func_359CF0(M2C_UNK *, s32);                    /* extern */
M2C_UNK func_36E6E0(M2C_UNK *, M2C_UNK);              /* extern */
M2C_UNK func_372E60(s32, M2C_UNK, M2C_UNK);           /* extern */
M2C_UNK func_373110();                                /* extern */
M2C_UNK func_3766A0(M2C_UNK *, M2C_UNK, M2C_UNK);     /* extern */
M2C_UNK func_376740(M2C_UNK *, M2C_UNK, M2C_UNK);     /* extern */
M2C_UNK func_376780(M2C_UNK *, M2C_UNK, M2C_UNK);     /* extern */
M2C_UNK func_3768A0(M2C_UNK *);                       /* extern */
s32 func_3769F0(s32);                                 /* extern */
s32 func_377330();                                    /* extern */
s32 func_377870(s32, s16);                            /* extern */
M2C_UNK func_379760(M2C_UNK *, M2C_UNK *, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_37B030(M2C_UNK, s8);                     /* extern */
M2C_UNK func_37CEA0(M2C_UNK);                         /* extern */

extern s16 D_003E1A44 __attribute__((section(".sdata")));
extern s8 D_003E1A4C __attribute__((section(".sdata")));
extern s8 D_003E1A50 __attribute__((section(".sdata")));
extern s8 D_003E14E0 __attribute__((section(".sdata")));
extern s8 D_003E151C __attribute__((section(".sdata")));
extern s32 D_003E1ABC __attribute__((section(".sdata")));
extern M2C_UNK D_421AD0 __attribute__((section(".data")));
extern M2C_UNK D_42D390 __attribute__((section(".data")));
extern M2C_UNK D_00478FA8 __attribute__((section(".data")));

s32 func_00462CF0(s32 arg0, s32 arg1) {
    M2C_UNK sp50[0x5A];
    s32 out;
    s32 scratch;
    s8 temp_a0;
    char *temp_s0;
    char *temp_v0;
    char *temp_v0_3;
    s32 temp_s1;
    s32 temp_s2;
    s32 temp_v0_2;
    s32 r;

    temp_s2 = func_0045F120(func_201C90());
    temp_a0 = D_003E1A4C;
    temp_s0 = func_359CF0(&D_421AD0, *(s32 *)0x458B90);
    D_003E1A50 = 0;
    D_003E14E0 = temp_a0;
    if (D_003E1A44 == 0xE4) {
        if (*(s32 *)0x458B94 == 4) {
            func_00463360(temp_a0);
            temp_s1 = func_181420();
            if (func_205050(temp_s1, temp_s1, 1) > 0) {
                temp_v0 = func_359CF0(&D_421AD0, temp_s1);
                *(s32 *)(temp_v0 + 0xE0) = 0x230;
                *(s32 *)(temp_v0 + 0xE8) = 1;
                *(s32 *)(temp_v0 + 0xEC) = 1;
                *(s16 *)(temp_v0 + 0xC8) = 0xE4;
                *(s16 *)(temp_v0 + 0xCA) = 4;
                *(s16 *)(temp_v0 + 0xCC) = (s16)*(s32 *)0x458B98;
                temp_v0_2 = func_201E70(4, 0xE4);
                if (temp_v0_2 != temp_s1) {
                    temp_v0_3 = func_359CF0(&D_421AD0, temp_v0_2);
                    *(s32 *)(temp_v0_3 + 0xE0) = 0;
                    *(s32 *)(temp_v0_3 + 0xE8) = 0;
                    *(s32 *)(temp_v0_3 + 0xEC) = 0;
                }
            } else {
                func_3768A0(sp50);
                func_376780(sp50, 0, temp_s1);
                func_376740(sp50, 1, 0xE4);
                func_3766A0(sp50, 0x40A, 0);
                func_379760(sp50, &D_00478FA8, 0, 0, 1);
                return 1;
            }
        }
    }
    if (D_003E1A44 == 0x116) {
        D_003E14E0 = 1;
        D_003E1A4C = 1;
    }
    if (D_003E1A44 == 0x165) {
        D_003E14E0 = 1;
        D_003E1A4C = 1;
        if (func_3084D0(func_1814D0(), 0x2B) != 0) {
            D_003E14E0 = 2;
            D_003E1A4C = 2;
        }
    }
    if (D_003E1A44 == 0x168) {
        D_003E14E0 = 1;
        D_003E1A4C = 1;
        if (func_377330() != 0) {
            D_003E14E0 = 2;
            D_003E1A4C = 2;
        }
    }
    if (D_003E1A44 == 0x12D) {
        D_003E14E0 = 1;
    }
    if (D_003E1A44 == 0x120) {
        D_003E14E0 = 2;
        D_003E1A4C = 2;
        if (temp_s0 != 0) {
            if (func_3769F0(func_205D30(func_181420(), *(s32 *)(temp_s0 + 0xF4))) != 0) {
                D_003E14E0 = 1;
                D_003E1A4C = 1;
            }
        }
    }
    if (D_003E1A44 == 0x167) {
        D_003E14E0 = 1;
        if (func_25ED30(temp_s2, 0xF, -1, 0, &scratch) == 0) {
            *(s32 *)(temp_s0 + 0xE0) = 0x2B1;
            D_003E14E0 = 0;
        }
    }
    if ((D_003E1A44 == 0x115) || (D_003E1A44 == 0xCB)) {
        D_003E14E0 = 1;
        out = 0;
        if (func_25ED30(temp_s2, 5, D_003E1ABC, 0, &out) == 0) {
            if (out != 3) {
                D_003E1A4C = 2;
            } else {
                switch (D_003E1A44) {
                case 0xCB:
                    *(s32 *)(temp_s0 + 0xE0) = 0x2B3;
                    D_003E14E0 = 0;
                    D_003E1A4C = 0;
                    break;
                case 0x115:
                    *(s32 *)(temp_s0 + 0xE0) = 0x2B2;
                    D_003E14E0 = 0;
                    D_003E1A4C = 0;
                    break;
                default:
                    *(s32 *)(temp_s0 + 0xE0) = 0x2B2;
                    D_003E14E0 = 0;
                    D_003E1A4C = 0;
                    break;
                }
            }
        }
    }
    func_2D38E0(arg1, 0x18703, 0, -1);
    func_37CEA0(0);
    func_373110();
    func_37B030(1, D_003E1A4C);
    r = func_377870(temp_s2, D_003E1A44);
    D_003E151C = r;
    if (r != 0) {
        func_36E6E0(&D_42D390, 1);
        func_372E60(func_201CC0(), 2, 1);
    }
    return 1;
}
