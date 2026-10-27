// range: 0x1CC600 0x1CC690
#include "common.h"

s32 func_00201FE0(s32);

typedef struct {
    s32 field_00;
    union {
        f32 as_float;
        s32 as_int;
    } field_04;
    s32 field_08;
    s32 *field_0C;
} S_arg0;

s32 func_001CC600(S_arg0 *arg0) {
    s32 temp_v0;
    s32 val;

    if (arg0->field_00 == 1) {
        val = (s32)arg0->field_04.as_float;
    } else {
        val = arg0->field_04.as_int;
    }

    if (val >= 0 && val < 4) {
        temp_v0 = func_00201FE0(val);
        if (arg0->field_08 == 3) {
            arg0->field_0C[1] = temp_v0;
        }
        return 1;
    }

    return 0;
}
