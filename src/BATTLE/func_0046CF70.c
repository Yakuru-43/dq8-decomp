// range: 0x46CF70 0x46CFC0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_1DB520();                              /* extern */

typedef struct {
    char pad0[0x60];
    s32 unk60;
    s32 unk64;
    s32 unk68;
    char pad6C[0x1B0];
    s32 unk21C;
    s32 unk220;
    s32 unk224;
    s32 unk228;
} S_arg0;

void func_0046CF70(S_arg0 *arg0) {
    func_1DB520();
    arg0->unk68 = -1;
    arg0->unk64 = -1;
    arg0->unk21C = 0;
    arg0->unk220 = 0;
    arg0->unk60 = 0;
    arg0->unk224 = 0;
    arg0->unk228 = 0;
}
