// range: 0x1DC080 0x1DC0F0
#include "common.h"

s32 func_003624C0(s32, char *, char *, char *);

typedef struct {
    s32 field_0;
    union {
        f32 as_float;
        s32 as_int;
    } field_4;
    s32 field_8;
    s32 *field_C;
} S_arg0;

s32 func_001DC080(S_arg0 *arg0, char *arg1, char *arg2, char *arg3) {
    s32 temp_v0;
    s32 a0_val;

    if (arg0->field_0 == 1) {
        a0_val = (s32)arg0->field_4.as_float;
    } else {
        a0_val = arg0->field_4.as_int;
    }
    temp_v0 = func_003624C0(a0_val, arg1, arg2, arg3);
    if (arg0->field_8 == 3) {
        arg0->field_C[1] = temp_v0;
    }
    return 1;
}
