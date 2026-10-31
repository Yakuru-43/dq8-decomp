// range: 0x1CA580 0x1CA600
#include "common.h"

s32 func_001A2130(s32);

typedef struct {
    s32 field_00;
    union {
        f32 as_float;
        s32 as_int;
    } field_04;
    s32 field_08;
    char *field_0C;
} S_arg0;

s32 func_001CA580(S_arg0 *arg0) {
    s32 temp_v0;
    s32 val;
    f32 loaded;

    if (arg0->field_00 == 1) {
        val = (s32)arg0->field_04.as_float;
    } else {
        val = arg0->field_04.as_int;
    }
    temp_v0 = func_001A2130(val);
    if (temp_v0 == 0) {
        return 0;
    }
    loaded = *(f32 *)(temp_v0 + 0x4CC);
    if (arg0->field_08 == 3) {
        *(f32 *)(arg0->field_0C + 4) = loaded;
    }
    return 1;
}
