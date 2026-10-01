// range: 0x460B20 0x460B60
// auto: m2c draft, verified byte-exact
#include "common.h"

char *func_370FA0(s32, M2C_UNK *);                  /* extern */
extern M2C_UNK D_00478FD0 __attribute__((section(".data")));

typedef struct {
    char pad0[0x20];
    s32 unk20;
} S_arg0;

void func_00460B20(S_arg0 *arg0) {
    M2C_FIELD(M2C_FIELD(arg0, char **, 0x18), s16 *, 0x12) = (s16) M2C_FIELD(func_370FA0(arg0->unk20, &D_00478FD0), s16 *, 0x12);
}
