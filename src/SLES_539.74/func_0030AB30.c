// range: 0x30AB30 0x30ABA0
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_0030ABA0(s32);                             /* extern */
s32 func_0030ABB0(s32);                             /* extern */
M2C_UNK func_003568F0(f32, s32);                    /* extern */

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x10, 0x14, 0x18, 0x1c, 0x20, 0x24, 0x28, 0x2c, 0x30, 0x34], gap at: 0x8. */
typedef struct {
    char pad0[0x138];
    s32 unk138;
} S_arg1;

void func_0030AB30(s32 arg0, S_arg1 *arg1) {
    f32 temp_f20;

    temp_f20 = (f32) func_0030ABB0(arg1->unk138);
    func_003568F0(temp_f20 / (f32) func_0030ABA0(arg1->unk138), arg0);
}
