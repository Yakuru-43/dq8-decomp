// Best attempt for func_0014ECA0 (register-only ~10/40) — kept for the next
// session. See notes/needs-claude/func_0014ECA0.md.
// range: 0x14ECA0 0x14ED40
#include "common.h"

extern u8 D_003ED890[];

void func_0014ECA0(void *arg0) {
    s32 var_a2 = M2C_FIELD(arg0, s32 *, 0);
    s32 var_a3 = M2C_FIELD(arg0, s32 *, 4);
    u8 *new_var = D_003ED890 + var_a3 * 0xC0 + var_a2 * 0x10;
    M2C_FIELD(arg0, s32 *, 0x18) = M2C_FIELD(new_var, s32 *, 0);
    M2C_FIELD(arg0, s32 *, 0x1C) = M2C_FIELD(new_var, s32 *, 4);
    M2C_FIELD(arg0, s32 *, 0x20) = M2C_FIELD(new_var, s32 *, 8);
    M2C_FIELD(arg0, s32 *, 0x24) =
        ((s32 *) M2C_FIELD(new_var, s32 *, 0x300))[M2C_FIELD(arg0, s32 *, 8)];
    M2C_FIELD(arg0, s32 *, 0x28) =
        ((s32 *) M2C_FIELD(new_var, s32 *, 0x304))[M2C_FIELD(arg0, s32 *, 0xC)];
    M2C_FIELD(arg0, s32 *, 0x2C) =
        ((s32 *) M2C_FIELD(new_var, s32 *, 0x308))[M2C_FIELD(arg0, s32 *, 0x10)];
    M2C_FIELD(arg0, s32 *, 0x14) = 6;
}
