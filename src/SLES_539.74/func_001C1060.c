// range: 0x1C1060 0x1C10E0
#include "common.h"

s32 func_001ABAD0(void *, s32, s32);

typedef struct {
    s32 field_00;
    union {
        f32 as_float;
        s32 as_int;
    } field_04;
    s32 field_08;
    s32 field_0C;
    s32 field_10;
    s32 *field_14;
} S_arg0;

typedef struct {
    s32 _pad[4];
} S_D_00411ED0;

extern S_D_00411ED0 D_00411ED0;

s32 func_001C1060(S_arg0 *arg0) {
    s32 temp_v0;
    s32 val;

    if (arg0->field_00 == 1) {
        val = (s32)arg0->field_04.as_float;
    } else {
        val = arg0->field_04.as_int;
    }
    temp_v0 = func_001ABAD0(&D_00411ED0, val, arg0->field_0C);
    if (arg0->field_10 == 3) {
        arg0->field_14[1] = temp_v0;
    }
    return 1;
}
