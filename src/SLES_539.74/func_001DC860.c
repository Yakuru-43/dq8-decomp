// range: 0x1DC860 0x1DC8E0
#include "common.h"

s32 func_00339E90(s32, s32);
extern char *D_003E0734;

typedef struct {
    s32 field_00;
    union {
        f32 as_float;
        s32 as_int;
    } field_04;
    s32 field_08;
    char *field_0C;
} S_arg0;

s32 func_001DC860(S_arg0 *arg0) {
    s32 temp_v0;
    s32 val;

    if (arg0->field_00 == 1) {
        val = (s32)arg0->field_04.as_float;
    } else {
        val = arg0->field_04.as_int;
    }
    temp_v0 = func_00339E90(*(s32 *)(D_003E0734 + 4) + 0x6B34, val);
    if (arg0->field_08 == 3) {
        *(s32 *)(arg0->field_0C + 4) = temp_v0;
    }
    return 1;
}
