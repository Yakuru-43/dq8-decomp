// range: 0x463CF0 0x463EF0
#include "common.h"

typedef struct {
    char pad0[0x10];
    s16 unk10;
    s16 unk12;
} S_18;

typedef struct {
    char pad0[0x18];
    S_18 *unk18;
} S_arg0;

s32 func_201CD0();                                     /* extern */
M2C_UNK func_22AB50(M2C_UNK);                          /* extern */
s32 func_370E00(s32, s32, s32);                        /* extern */
s32 func_370F60(s32, s32);                             /* extern */
s32 func_371490(S_arg0 *);                             /* extern */
s32 func_37AD10();                                     /* extern */
M2C_UNK func_37DD00(s32, s32);                         /* extern */
M2C_UNK func_37DFC0(S_arg0 *, s32, s32, s32, f32, s32); /* extern */
M2C_UNK func_37E170(s32, s16);                         /* extern */

extern s16 D_003E1528 __attribute__((section(".sdata")));
extern s16 D_003E152C __attribute__((section(".sdata")));
extern f32 D_003DF744 __attribute__((section(".sdata")));

s32 func_00463CF0(S_arg0 *arg0) {
    s32 ctx;
    s32 start;
    S_18 *p;
    s32 cur;
    s32 off;
    s32 base;

    ctx = func_201CD0();
    if (func_37AD10() == 4) {
        start = D_003E1528;
        if (func_370F60(ctx, 8) != 0) {
            D_003E1528++;
        } else if (func_370F60(ctx, 4) != 0) {
            D_003E1528--;
        } else {
            func_370E00(ctx, 2, 3);
        }
        if (D_003E1528 < 0) {
            D_003E1528 = D_003E152C;
        }
        if (D_003E152C < D_003E1528) {
            D_003E1528 = 0;
        }
        if (start != D_003E1528) {
            func_22AB50(0x28);
        }
        if (start != D_003E1528 || func_371490(arg0) != 0) {
            p = arg0->unk18;
            cur = D_003E1528;
            base = p->unk10 + p->unk12 * 4;
            off = D_003E1528 * 12;
            func_37E170(func_37AD10(), cur);
            func_37DD00(func_37AD10(), off + base);
            func_37DFC0(arg0, func_37AD10(), 1, 0x18703, D_003DF744, 0x485);
        }
    } else {
        func_370E00(ctx, 2, 3);
        if (func_371490(arg0) != 0) {
            p = arg0->unk18;
            func_37DD00(func_37AD10(), p->unk10 + p->unk12 * 4);
            func_37DFC0(arg0, func_37AD10(), 1, 0x18703, D_003DF744, 0x485);
        }
    }
    return 1;
}
