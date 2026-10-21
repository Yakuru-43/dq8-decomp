// range: 0x468490 0x468520
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_0045F0F0(s32, s32, s16);               /* extern */
s32 func_161E80(s32, M2C_UNK *, s32 *);             /* extern */
s32 func_201CD0();                                  /* extern */
s32 func_2D34C0();                                  /* extern */
M2C_UNK func_370C00(s32, M2C_UNK *, M2C_UNK);       /* extern */
M2C_UNK func_370D40(s32, M2C_UNK *, s32);           /* extern */
extern M2C_UNK D_00470CA0 __attribute__((section(".data")));
extern M2C_UNK D_004737D0 __attribute__((section(".data")));
extern M2C_UNK D_00473990 __attribute__((section(".data")));

typedef struct {
    char pad0[0x10C];
    s32 unk10C;
} S_arg0;

void func_00468490(S_arg0 *arg0) {
    s32 sp2C;
    s32 temp_s0;
    s32 var_v0;

    var_v0 = 0;
    if (arg0 != NULL) {
        var_v0 = func_161E80(arg0->unk10C, &D_00473990, &sp2C);
    }
    func_0045F0F0(var_v0, sp2C, *(s16 *)0x415E90);
    temp_s0 = func_2D34C0();
    func_370D40(func_201CD0(), &D_00470CA0, temp_s0);
    func_370C00(func_201CD0(), &D_004737D0, 0);
}
