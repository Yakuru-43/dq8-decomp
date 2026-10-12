// range: 0x192380 0x1923B0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_002572F0(M2C_UNK *, M2C_UNK);          /* extern */
extern s8 D_003E05BC;
extern M2C_UNK D_004102A0 __attribute__((section(".data")));

void func_00192380(void) {

    if (!(D_003E05BC != 0)) {
        return;
    }

    func_002572F0(&D_004102A0, 5);
}
