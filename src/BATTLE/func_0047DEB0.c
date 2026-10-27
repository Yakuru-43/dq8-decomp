// range: 0x47DEB0 0x47DF00
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00471470(s32, s32, s32);               /* extern */
s32 func_00472620(s32);                             /* extern */

typedef struct {
    char pad0[0x10];
    s32 unk10;
    char pad14[0x3C];
    s32 unk50;
} S_arg2;

s32 func_0047DEB0(s32 arg0, s32 arg1, S_arg2 *arg2) {
    func_00471470(arg0, func_00472620(arg2->unk50), arg2->unk10);
    return 0;
}
