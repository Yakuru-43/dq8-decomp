// range: 0x2D34A0 0x2D34C0
#include "common.h"

M2C_UNK func_00131188();                              /* extern */
extern M2C_UNK D_004504B0 __attribute__((section(".data")));   /* extern */
extern s8 D_003E1098;                                  /* extern */

void func_002D34A0(void) {
    D_003E1098 = 0;
    func_00131188(&D_004504B0, 0, 0x730);
}
