// range: 0x1BB8D0 0x1BB940
#include "common.h"

s32 func_00201C10(s32);

typedef struct {
    s32 field_00;
    f32 field_04;
    s32 field_08;
    char *field_0C;
} S_arg0;

s32 func_001BB8D0(S_arg0 *arg0) {
    s32 temp_v0;
    s32 val;

    if (arg0->field_00 == 1) {
        val = (s32)arg0->field_04;
    } else {
        val = *(s32 *)&arg0->field_04;
    }
    temp_v0 = func_00201C10(val);
    if (arg0->field_08 == 3) {
        *(s32 *)(arg0->field_0C + 4) = temp_v0;
    }
    return 1;
}
