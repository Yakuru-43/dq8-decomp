// range: 0x304B70 0x304B80
// auto: hand, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x4050];
    f32 unk4050;
    s32 unk4054;
} S_arg0;

M2C_UNK func_00304980(s32, f32);                     /* extern */

s32 func_00304B70(S_arg0 *arg0) {
    return func_00304980(arg0->unk4054, arg0->unk4050);
}
