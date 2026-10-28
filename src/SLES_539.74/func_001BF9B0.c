// range: 0x1BF9B0 0x1BFA40
#include "common.h"

M2C_UNK func_00353170(s32, s32);                    /* extern */
void func_003537B0(s32);                            /* extern */
s32 func_001923B0(s32);                             /* extern */
M2C_UNK func_00353450(s32, s32);                    /* extern */
extern s32 D_003E0664;

typedef struct {
    s32 field_00;
    f32 field_04;
} Struct_1BF9B0;

s32 func_001BF9B0(Struct_1BF9B0 *arg0) {
    s32 temp_s0;
    s32 val;

    temp_s0 = D_003E0664;
    if (arg0->field_00 == 1) {
        val = (s32)arg0->field_04;
    } else {
        val = *(s32 *)&arg0->field_04;
    }
    if (val != 1) {
        func_00353170(temp_s0, 0);
        func_003537B0(temp_s0);
    } else {
        func_00353170(temp_s0, val);
        func_00353450(temp_s0, func_001923B0(0));
    }
    return 1;
}
