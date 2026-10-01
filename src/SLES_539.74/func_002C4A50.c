// range: 0x2C4A50 0x2C4A90
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_001735C0(s32, s32, M2C_UNK);           /* extern */
M2C_UNK func_002C4A90(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
extern void *D_003E1010;

void func_002C4A50(void) {
    if (D_003E1010 != NULL) {
        func_001735C0(M2C_FIELD(D_003E1010, s32 *, 0x60), M2C_FIELD(D_003E1010, s32 *, 0x64), 0);
    }
    func_002C4A90(0, 0, 0);
}
