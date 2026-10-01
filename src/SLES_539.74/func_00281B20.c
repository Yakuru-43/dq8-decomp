// range: 0x281B20 0x281B90
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00286B30(s32, s32);                    /* extern */
M2C_UNK func_00286BE0(s32, s32);                    /* extern */

typedef struct {
    char pad0[0x28];
    s32 unk28;
    s32 unk2C;
    s32 unk30;
} S_arg1;

typedef struct {
    char pad0[0x4];
    s32 unk4;
} S_arg0;

s32 func_00281B20(S_arg0 *arg0, S_arg1 *arg1) {
    s32 temp_a0;
    s32 temp_a1;

    if (arg1->unk30 == 0) {
        temp_a0 = arg0->unk4;
        if (temp_a0 == 0) {
            return 0;
        }
        temp_a1 = arg1->unk28;
        if (temp_a1 == 0) {
            return 0;
        }
        if (arg1->unk2C != 0) {
            func_00286BE0(temp_a0, temp_a1);
        } else {
            func_00286B30(temp_a0, temp_a1);
        }
        arg1->unk30 = 1;
        goto block_11;
    }
block_11:
    return 1;
}
