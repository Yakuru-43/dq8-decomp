// range: 0x210A40 0x210A90
#include "common.h"

M2C_UNK func_001340C0(M2C_UNK *, M2C_UNK *);         /* extern */
M2C_UNK func_001339E0(M2C_UNK *, M2C_UNK *, M2C_UNK *); /* extern */

extern M2C_UNK D_003C78B0 __attribute__((section(".data")));

void func_00210A40(M2C_UNK *arg0, M2C_UNK *arg1) {
    func_001340C0(arg0, &D_003C78B0);
    func_001339E0(arg0, arg0, arg1);
}
