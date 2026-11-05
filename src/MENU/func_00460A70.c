// range: 0x460A70 0x460B60
#include "common.h"

M2C_UNK func_00460C00(s32, s32, f32);               /* extern */
M2C_UNK func_00460D00(void);                        /* extern */
s32 func_00460D70(void);                            /* extern */
M2C_UNK func_00460DE0(M2C_UNK);                     /* extern */
s32 func_201CD0();                                  /* extern */
M2C_UNK func_2D38E0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_3705B0(M2C_UNK, M2C_UNK);              /* extern */
M2C_UNK func_3710B0(char *, M2C_UNK, s32);          /* extern */
M2C_UNK func_37C110(M2C_UNK, M2C_UNK, M2C_UNK);     /* extern */
M2C_UNK func_37CEA0(M2C_UNK);                       /* extern */
M2C_UNK func_37CE30(M2C_UNK);                       /* extern */
M2C_UNK func_37D780(M2C_UNK);                       /* extern */
M2C_UNK func_37E170(s32, M2C_UNK);                  /* extern */
extern f32 D_003DF78C __attribute__((section(".sdata")));
extern s16 D_003E1528 __attribute__((section(".sdata")));

s32 func_00460A70(char *arg0, M2C_UNK arg1) {
    s32 temp_v0;

    func_2D38E0(arg1, 0x4A6, 1, -1);
    func_37CEA0(1);
    func_37CE30(0);
    func_3705B0(func_201CD0(), 4);
    func_00460C00(M2C_FIELD(M2C_FIELD(arg0, char **, 0x18), s16 *, 0x12), 0,
                  D_003DF78C);
    temp_v0 = func_00460D70();
    if (temp_v0 == 4) {
        func_37E170(temp_v0, D_003E1528);
    } else {
        func_37E170(temp_v0, 0);
    }
    func_00460DE0(temp_v0);
    func_37D780(0);
    func_00460D00();
    func_37C110(1, 1, 0);
    func_3710B0(arg0, 1, 4);
    return 1;
}
