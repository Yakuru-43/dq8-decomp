// range: 0x371D40 0x371E00
#include "common.h"

s32 func_0025BA50(s32);
M2C_UNK func_0025ADC0(s16);                         /* extern */
M2C_UNK func_0025B3A0(s16);                         /* extern */

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

void func_00371D40(s32 *arg0, s32 arg1) {
    u8 temp_v1;
    S_arg0 *var_s0;

    if ((arg1 >= 0) && (arg1 < 6)) {
        var_s0 = *(S_arg0 **)(arg0 + arg1);
    } else {
        var_s0 = NULL;
    }
    if (var_s0 != NULL) {
        temp_v1 = var_s0->unk0;
        if (temp_v1 != 0) {
            if (temp_v1 != 0) {
                func_0025ADC0(var_s0->unk2);
            }
            func_0025B3A0(var_s0->unk2);
            var_s0->unk24 = 0;
            var_s0->unk64 = -1;
            func_0025BA50(var_s0->unk2);
            var_s0->unk2 = -1;
            var_s0->unk0 = 0U;
            var_s0->unk10 = 0x3F800000;
            var_s0->unk14 = 0x3F800000;
            var_s0->unk20 = 0;
            var_s0->unk1C = 0xBF800000;
            var_s0->unk18 = 0x3F800000;
            var_s0->unk24 = 0;
            var_s0->unk64 = -1;
            var_s0->unk68 = 0;
        }
    }
}
