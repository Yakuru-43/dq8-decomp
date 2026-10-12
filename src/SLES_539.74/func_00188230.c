// range: 0x188230 0x1882F0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_0016B3E0(); /* extern */
M2C_UNK func_002C3C80();                            /* extern */
M2C_UNK func_002C4A90();   /* extern */
M2C_UNK func_002C5F60();                      /* extern */
M2C_UNK func_0033B5B0();                      /* extern */
M2C_UNK func_00351910();             /* extern */
extern s32 D_003E04AC;
extern s8 D_003E04B0;
extern s8 D_003E04BC;
extern s32 D_003E04C0;
extern s32 D_003E04C4;
extern s32 D_003E04D8;
extern s16 D_003E04DC;
extern s16 D_003E04E0;
extern s32 D_003E04E4;
extern s8 D_003E04E8;
extern s8 D_003E04EC;
extern s8 D_003E04F0;
extern s8 D_003E04F8;
extern s8 D_003E1038;
extern s32 D_0040F970 __attribute__((section(".data")));
extern s32 D_0040F974 __attribute__((section(".data")));
extern s128 D_0044F920 __attribute__((section(".data")));

typedef struct {
    char pad0[0x44B0];
    s32 unk44B0;
} S_arg0;

void func_00188230(S_arg0 *arg0) {
    D_0040F970 = 0;
    D_003E04AC = 0;
    D_0040F974 = 0;
    D_003E04B0 = 0;
    D_003E04F0 = 0;
    func_002C3C80();
    D_003E04EC = 0;
    D_0044F920 = 0;
    D_003E1038 = 0;
    func_0016B3E0(arg0, 1, arg0->unk44B0, 0x10);
    D_003E04C0 = 0;
    D_003E04BC = 0;
    D_003E04C4 = 0;
    func_002C5F60(arg0);
    D_003E04DC = 0;
    D_003E04E0 = 0;
    D_003E04E4 = 0;
    D_003E04E8 = 0;
    D_003E04F8 = 0;
    D_003E04D8 = 0;
    func_002C4A90(0, 0, 0);
    func_00351910(arg0, 0);
    func_0033B5B0(arg0);
}
