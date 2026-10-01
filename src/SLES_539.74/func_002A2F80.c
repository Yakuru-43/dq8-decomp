// range: 0x2A2F80 0x2A31C0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00130FD0(s32, s32, u32);               /* extern */
s32 func_0014E130(s32, u32);                        /* extern */
s32 func_001629F0(M2C_UNK *, s32, u32 *);           /* extern */
M2C_UNK func_00163E10(M2C_UNK *);                   /* extern */
M2C_UNK func_0027EE50(s32, s32);                    /* extern */
M2C_UNK func_0029EDC0(M2C_UNK *, M2C_UNK *, s32);   /* extern */
M2C_UNK func_002AE840(M2C_UNK *, s32, s32);         /* extern */
M2C_UNK func_002AE950(M2C_UNK *);                   /* extern */
M2C_UNK func_002AE960(s32, s32);                    /* extern */
M2C_UNK func_002AEB30(s32, s32);                    /* extern */
M2C_UNK func_002AEC10(M2C_UNK *, s32);              /* extern */
M2C_UNK func_002AECC0(M2C_UNK *, s32);              /* extern */
M2C_UNK func_002AF0E0(M2C_UNK *, s32, s32);         /* extern */
M2C_UNK func_002AF8C0(M2C_UNK *, s32, s32);         /* extern */
M2C_UNK func_002AFA50(M2C_UNK *);                   /* extern */
M2C_UNK func_002AFAA0(M2C_UNK *, s32);              /* extern */
M2C_UNK func_002AFCE0(M2C_UNK *, s32);              /* extern */
M2C_UNK func_002AFD70(M2C_UNK *, s32);              /* extern */
M2C_UNK func_002B00E0(M2C_UNK *, s32);              /* extern */
M2C_UNK func_002B0270(M2C_UNK *, s32);              /* extern */
M2C_UNK func_002B0360(M2C_UNK *, s32);              /* extern */
M2C_UNK func_002B0530(M2C_UNK *, s32);              /* extern */
M2C_UNK func_002B0790(M2C_UNK *, s32);              /* extern */
M2C_UNK func_002B3520(s32);                         /* extern */
M2C_UNK func_0033F5D0(s32, s32);                    /* extern */
M2C_UNK func_0033F640(s32, s32);                    /* extern */
M2C_UNK func_0033F6B0(s32, s32);                    /* extern */
M2C_UNK func_0033F720(s32, s32);                    /* extern */
M2C_UNK func_0033F790(s32, s32);                    /* extern */
M2C_UNK func_0036E9A0(M2C_UNK *, s32);              /* extern */
extern M2C_UNK D_003CC2A8 __attribute__((section(".data")));
extern M2C_UNK D_003CC2B0 __attribute__((section(".data")));
extern M2C_UNK D_003CC2C0 __attribute__((section(".data")));
extern s32 D_003E0EC4;
extern M2C_UNK D_003E0F70;
extern M2C_UNK D_003E0F78;
extern M2C_UNK D_0042CDB0 __attribute__((section(".data")));
extern M2C_UNK D_0042D390 __attribute__((section(".data")));
extern M2C_UNK D_0042EA48 __attribute__((section(".data")));
extern M2C_UNK D_0042EA80 __attribute__((section(".data")));
extern M2C_UNK D_0042EAA0 __attribute__((section(".data")));
extern M2C_UNK D_004392A0 __attribute__((section(".data")));
extern M2C_UNK D_004392B0 __attribute__((section(".data")));
extern M2C_UNK D_004392D0 __attribute__((section(".data")));
extern M2C_UNK D_004392F0 __attribute__((section(".data")));

void func_002A2F80(s32 arg0, s32 arg1) {
    u32 sp4C;
    s32 temp_v0;
    s32 var_s2;
    u32 var_a1;

    if ((arg0 != 0) && (arg1 != 0)) {
        func_002AFA50(&D_004392B0);
        func_002AFAA0(&D_004392B0, arg0);
        func_002AECC0(&D_003E0F78, arg1);
        func_002AEC10(&D_003E0F78, arg0);
        func_00163E10(&D_003CC2A8);
        func_002B0360(&D_0042EAA0, arg0);
        func_002B0790(&D_0042EA80, arg1);
        func_002B0530(&D_0042EA80, arg0);
        func_00163E10(NULL);
        func_00163E10(&D_003CC2B0);
        func_002B0270(&D_004392A0, arg1);
        func_002B00E0(&D_004392A0, arg0);
        func_002AFD70(&D_003E0F70, arg1);
        func_002AFCE0(&D_003E0F70, arg0);
        func_002AF8C0(&D_004392D0, arg0, arg1);
        func_002AF0E0(&D_004392F0, arg0, arg1);
        func_0027EE50(arg0, arg1);
        var_s2 = 0;
        if (func_001629F0(&D_003CC2C0, arg0, &sp4C) != 0) {
            if (!(sp4C & 0xF)) {
                var_a1 = sp4C >> 4;
            } else {
                var_a1 = (sp4C >> 4) + 1;
            }
            temp_v0 = func_0014E130(arg1, var_a1);
            var_s2 = temp_v0;
            D_003E0EC4 = temp_v0;
            func_00130FD0(temp_v0, arg0, sp4C);
        }
        func_002AEB30(arg0, arg1);
        func_002AE960(arg0, arg1);
        func_00163E10(&D_003CC2B0);
        func_0033F790(arg0, arg1);
        func_0033F720(arg0, arg1);
        func_0033F6B0(arg0, arg1);
        func_0033F640(arg0, arg1);
        func_0033F5D0(arg0, arg1);
        func_0036E9A0(&D_0042D390, arg1);
        func_002B3520(arg1);
        func_0029EDC0(&D_0042CDB0, &D_004392A0, var_s2);
        func_002AE950(&D_0042EA48);
        func_002AE840(&D_0042EA48, arg0, arg1);
        func_00163E10(NULL);
    }
}
