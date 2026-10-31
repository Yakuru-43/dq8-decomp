// range: 0x1C9460 0x1C94E0
#include "common.h"

s32 func_001A2190(s32);

typedef struct {
    s32 field_00;
    union {
        f32 as_float;
        s32 as_int;
    } field_04;
    s32 field_08;
    s32 *field_0C;
} S_arg0;

s32 func_001C9460(S_arg0 *arg0) {
    s32 temp_v0;
    s32 val;
    s32 loaded;

    if (arg0->field_00 == 1) {
        val = (s32)arg0->field_04.as_float;
    } else {
        val = arg0->field_04.as_int;
    }
    temp_v0 = func_001A2190(val);
    if (temp_v0 == 0) {
        return 0;
    }
    loaded = *(s32 *)(temp_v0 + 0x1650);
    if (arg0->field_08 == 3) {
        arg0->field_0C[1] = loaded;
    }
    return 1;
}
