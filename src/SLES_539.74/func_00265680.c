// range: 0x265680 0x265780
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00130FD0(M2C_UNK *, s32, s32);         /* extern */
s32 func_001629F0(M2C_UNK *, s32, s32 *);           /* extern */
M2C_UNK func_00163E10(M2C_UNK *);                   /* extern */
s32 func_0022AB70();                                /* extern */
extern M2C_UNK D_003C9788 __attribute__((section(".data")));
extern M2C_UNK D_003C9798 __attribute__((section(".data")));
extern M2C_UNK D_003C97B0 __attribute__((section(".data")));
extern M2C_UNK D_003C97C8 __attribute__((section(".data")));
extern M2C_UNK D_003C97D8 __attribute__((section(".data")));
extern M2C_UNK D_0041E5C0 __attribute__((section(".data")));
extern M2C_UNK D_0041EC20 __attribute__((section(".data")));
extern M2C_UNK D_0041EF40 __attribute__((section(".data")));
extern M2C_UNK D_0041FCF0 __attribute__((section(".data")));

void func_00265680(s32 arg0) {
    s32 sp2C;
    s32 temp_s0;


    if (!(arg0 != 0)) {
        return;
    }

    temp_s0 = func_0022AB70();
    func_00163E10(&D_003C9788);
    if (func_001629F0(&D_003C9798, temp_s0, &sp2C) != 0) {
        func_00130FD0(&D_0041E5C0, temp_s0, sp2C);
    }
    if (func_001629F0(&D_003C97B0, temp_s0, &sp2C) != 0) {
        func_00130FD0(&D_0041EF40, temp_s0, 0xDB0);
    }
    if (func_001629F0(&D_003C97C8, temp_s0, &sp2C) != 0) {
        func_00130FD0(&D_0041EC20, temp_s0, sp2C);
    }
    if (func_001629F0(&D_003C97D8, temp_s0, &sp2C) != 0) {
        func_00130FD0(&D_0041FCF0, temp_s0, sp2C);
    }
    func_00163E10(NULL);
}
