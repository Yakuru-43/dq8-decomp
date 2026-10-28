// range: 0x1DC0F0 0x1DC160
#include "common.h"

f32 func_003626D0(s32);

typedef struct {
    s32 field_00;
    union {
        f32 as_float;
        s32 as_int;
    } field_04;
    s32 field_08;
    char *field_0C;
} S_arg0;

s32 func_001DC0F0(S_arg0 *arg0) {
    s32 val;
    f32 temp_f0;

    if (arg0->field_00 == 1) {
        val = (s32)arg0->field_04.as_float;
    } else {
        val = arg0->field_04.as_int;
    }
    temp_f0 = func_003626D0(val);
    if (arg0->field_08 == 3) {
        *(f32 *)(arg0->field_0C + 4) = temp_f0;
    }
    return 1;
}
