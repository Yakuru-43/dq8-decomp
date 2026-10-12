// range: 0x1FF470 0x1FF4B0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_001FF7F0();                            /* extern */
M2C_UNK func_001FF830();                            /* extern */
M2C_UNK func_00244650(s32);                         /* extern */
extern s32 D_003E0B30;

void func_001FF470(void) {

    if (!(D_003E0B30 != 0)) {
        return;
    }

    func_001FF830();
    func_00244650(D_003E0B30);
    func_001FF7F0();
}
