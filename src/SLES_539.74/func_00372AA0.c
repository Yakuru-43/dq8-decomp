// range: 0x372AA0 0x372B30
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_0025ADC0(s16);                         /* extern */
M2C_UNK func_0025B3A0(s16);                         /* extern */
M2C_UNK func_0025BA50(s16);                         /* extern */

typedef struct {
    u8 unk0;
    char pad1[0x1];
    s16 unk2;
    char pad4[0xC];
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s8 unk24;
    char pad25[0x3F];
    s16 unk64;
    char pad66[0x2];
    s32 unk68;
} S_arg0;

void func_00372AA0(S_arg0 *arg0) {
    u8 temp_v1;

    temp_v1 = arg0->unk0;
    if (temp_v1 != 0) {
        if (temp_v1 != 0) {
            func_0025ADC0(arg0->unk2);
        }
        func_0025B3A0(arg0->unk2);
        arg0->unk24 = 0;
        arg0->unk64 = -1;
        func_0025BA50(arg0->unk2);
        arg0->unk2 = -1;
        arg0->unk0 = 0U;
        arg0->unk10 = 0x3F800000;
        arg0->unk14 = 0x3F800000;
        arg0->unk20 = 0;
        arg0->unk1C = 0xBF800000;
        arg0->unk18 = 0x3F800000;
        arg0->unk24 = 0;
        arg0->unk64 = -1;
        arg0->unk68 = 0;
    }
}
