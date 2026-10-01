// range: 0x372520 0x372580
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_0025ACE0(s16, f32);                    /* extern */

typedef struct {
    char pad0[0x2];
    s16 unk2;
    char pad4[0xC];
    f32 unk10;
    f32 unk14;
    f32 unk18;
} S_arg0;

void func_00372520(S_arg0 *arg0, f32 fparg0) {
    f32 temp_f12;
    f32 temp_f2;

    temp_f2 = arg0->unk18 * (arg0->unk10 * arg0->unk14);
    arg0->unk14 = fparg0;
    temp_f12 = arg0->unk18 * (arg0->unk10 * fparg0);
    if (temp_f2 != temp_f12) {
        func_0025ACE0(arg0->unk2, temp_f12);
    }
}
