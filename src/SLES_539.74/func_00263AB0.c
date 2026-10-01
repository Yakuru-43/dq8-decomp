// range: 0x263AB0 0x263AF0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00131188(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_0027F130();                            /* extern */
extern M2C_UNK D_0041E470 __attribute__((section(".data")));
extern s16 D_0041E530 __attribute__((section(".data")));
extern s16 D_0041E532 __attribute__((section(".data")));

void func_00263AB0(void) {
    func_00131188(&D_0041E470, 0, 0xE0);
    D_0041E530 = -1;
    D_0041E532 = -1;
    func_0027F130();
}
