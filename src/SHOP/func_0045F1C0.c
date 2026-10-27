// range: 0x45F1C0 0x45F220
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_2D34C0();                                  /* extern */
M2C_UNK func_2D49C0(s32, M2C_UNK, M2C_UNK *);       /* extern */
M2C_UNK func_2D4A40(s32, M2C_UNK, M2C_UNK *);       /* extern */
extern M2C_UNK D_00474450 __attribute__((section(".data")));
extern M2C_UNK D_00474460 __attribute__((section(".data")));

void func_0045F1C0(void) {
    s32 temp_v0;

    temp_v0 = func_2D34C0();

    if (!(temp_v0 != 0)) {
        return;
    }

    func_2D4A40(temp_v0, 0x17A2, &D_00474450);
    func_2D49C0(temp_v0, 0x17A2, &D_00474460);
}
