// range: 0x36EA30 0x36EA80
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_002F69B0(s32);                         /* extern */

typedef struct {
    s8 unk0;
    char pad1[0x3];
    s16 unk4;
    char pad6[0x6];
    s32 unkC;
    s32 unk10;
    s32 unk14;
} S_arg0;

void func_0036EA30(S_arg0 *arg0) {
    arg0->unk0 = 0;
    arg0->unk4 = 0;
    func_002F69B0(arg0->unkC);
    func_002F69B0(arg0->unkC + 0x1F18);
    arg0->unk14 = (s32) arg0->unk10;
}
