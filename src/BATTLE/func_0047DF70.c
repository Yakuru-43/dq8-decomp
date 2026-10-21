// range: 0x47DF70 0x47DFC0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_004723B0(M2C_UNK *);                   /* extern */
M2C_UNK func_1632E0();                              /* extern */
M2C_UNK func_290770(M2C_UNK *, s32, M2C_UNK *);     /* extern */
extern M2C_UNK D_420C30 __attribute__((section(".data")));
extern M2C_UNK D_4217B8 __attribute__((section(".data")));

typedef struct {
    char pad0[0x10];
    s32 unk10;
} S_arg2;

s32 func_0047DF70(s32 arg0, s32 arg1, S_arg2 *arg2) {
    func_1632E0();
    func_004723B0(&D_4217B8);
    func_290770(&D_420C30, arg2->unk10, &D_4217B8);
    return 0;
}
