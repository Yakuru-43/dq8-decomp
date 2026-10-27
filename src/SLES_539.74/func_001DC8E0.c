// range: 0x1DC8E0 0x1DC960
#include "common.h"

s32 func_00339E90(s32, s32);

typedef struct {
    s32 field_0;
    union {
        f32 as_float;
        s32 as_int;
    } field_4;
    s32 field_8;
    s32 *field_C;
} S_arg0;

extern char *D_003E0734;

s32 func_001DC8E0(S_arg0 *arg0) {
    s32 temp_v0;
    s32 val;

    if (arg0->field_0 == 1) {
        val = (s32)arg0->field_4.as_float;
    } else {
        val = arg0->field_4.as_int;
    }
    temp_v0 = func_00339E90(*(s32 *)(D_003E0734 + 4) + 0x6B34, val);
    if (arg0->field_8 == 3) {
        arg0->field_C[1] = temp_v0;
    }
    return 1;
}
