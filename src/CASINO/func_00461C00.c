// range: 0x461C00 0x461D00
#include "common.h"

extern void func_159630(char *, s32);
extern char *func_15F450(void);
extern void func_16A430(s32, s32);
extern void func_16BB90(s32, s32);
s32 func_1735C0(s32, s32, s32); /* extern */
extern void func_004736B0(s32, s32, s32);

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 pad8[2];
    s32 unk10;
    s32 unk14;
} S_D003E167C;

extern S_D003E167C *D_003E167C;
extern s32 D_003E17BC;
extern s32 D_003E168C;
extern s32 D_003E17B4;

s32 func_00461C00(void) {
    s32 h;
    char *p;
    s32 i;

    if (D_003E167C == 0) {
        return 0;
    }
    h = D_003E167C->unk14;
    func_1735C0(D_003E17BC, 0, 0);
    p = func_15F450();
    *(u8 *)(p + 0x1E4) = 0;
    for (i = 0; i < D_003E167C->unk4; i++) {
        func_159630(p, D_003E167C->unk0 + i);
    }
    for (i = 0; i < 0x20; i++) {
        func_004736B0(D_003E168C, i, 0x20);
    }
    for (i = 0; i < 0x20; i++) {
        func_004736B0(D_003E168C, i, 0x20);
    }
    func_16A430(h, 0xA0);
    func_16BB90(h, D_003E167C->unk10);
    D_003E17B4 = 0;
    return 1;
}
