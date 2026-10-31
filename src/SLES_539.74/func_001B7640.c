// range: 0x1B7640 0x1B76C0
#include "common.h"

s32 func_001D6CF0(s32);

typedef struct {
    s32 field_00;
    union {
        f32 as_float;
        s32 as_int;
    } field_04;
    s32 field_08;
    s32 *field_0C;
} S_arg0;

s32 func_001B7640(S_arg0 *arg0, s32 arg1) {
    s32 val;
    s32 temp_v0;

    if (arg1 != 2) {
        return 0;
    }
    if (arg0->field_00 == 1) {
        val = (s32)arg0->field_04.as_float;
    } else {
        val = arg0->field_04.as_int;
    }
    temp_v0 = func_001D6CF0(val);
    if (arg0->field_08 == 3) {
        arg0->field_0C[1] = temp_v0;
    }
    return 1;
}
