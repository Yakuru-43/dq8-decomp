// range: 0x46B8D0 0x46B950
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_2D38E0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_2D45D0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
char *func_370FA0(s32, M2C_UNK *);                  /* extern */
M2C_UNK func_37AB80(M2C_UNK, s16, M2C_UNK);         /* extern */
extern M2C_UNK D_00479438 __attribute__((section(".data")));

typedef struct {
    char pad0[0x20];
    s32 unk20;
} S_arg0;

s32 func_0046B8D0(S_arg0 *arg0, M2C_UNK arg1) {
    func_2D38E0(arg1, 0x18707, 1, -1);
    func_2D45D0(arg1, 0x18707, 5, 1);
    func_37AB80(2, M2C_FIELD(func_370FA0(arg0->unk20, &D_00479438), s16 *, 0x12), 1);
    return 1;
}
