// range: 0x310680 0x310760
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_0014A490(s32, M2C_UNK *);                  /* extern */
s32 func_00151B40(char *);                          /* extern */
M2C_UNK func_00151F40(s32, s32);                    /* extern */
s32 func_00161E80(s32, M2C_UNK *, M2C_UNK);         /* extern */
char *func_0016D5B0(s32, s32);                      /* extern */
s32 func_001813A0();                                /* extern */
M2C_UNK func_003108A0(M2C_UNK *, s32, s32, s32);    /* extern */
extern M2C_UNK D_003D0930 __attribute__((section(".data")));
extern M2C_UNK D_003D0940 __attribute__((section(".data")));
extern M2C_UNK D_004528A0 __attribute__((section(".data")));
extern s32 D_004528A4 __attribute__((section(".data")));

void func_00310680(s32 arg0, s32 arg1) {
    s32 temp_v0;
    char *temp_s0;


    if (!(arg1 != 0)) {
        return;
    }

    temp_s0 = func_0016D5B0(func_001813A0(), arg0);
    if (arg0 != 0) {

    } else {
        func_003108A0(&D_004528A0, func_00161E80(arg1, &D_003D0930, 0), M2C_FIELD(temp_s0, s32 *, 0x4DC), M2C_FIELD(temp_s0, s32 *, 0x470));
        if ((temp_s0 != NULL) && (D_004528A4 != 0) && (arg0 == 0)) {
            temp_v0 = func_0014A490(func_00151B40(temp_s0), &D_003D0940);
            if (temp_v0 != 0) {
                func_00151F40(D_004528A4, temp_v0);
            }
        }
    }
}
