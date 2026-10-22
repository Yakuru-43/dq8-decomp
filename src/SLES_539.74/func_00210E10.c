// range: 0x210E10 0x210E90
#include "common.h"

M2C_UNK func_001339E0(char *, M2C_UNK *, char *);      /* extern */
M2C_UNK func_001340C0(M2C_UNK *, char *);               /* extern */
M2C_UNK func_00133CB8(M2C_UNK *, char *);               /* extern */
extern M2C_UNK D_003C78B0 __attribute__((section(".data")));

void func_00210E10(char *arg0, M2C_UNK *arg1) {
    char bufB0[0x80];
    char buf30[0x80];

    func_001339E0(bufB0, &D_003C78B0, arg0);
    func_001339E0(buf30, &D_003C78B0, arg0);
    if (arg1 != 0) {
        func_001340C0(arg1, bufB0);
        func_00133CB8(arg1, buf30);
    }
}
