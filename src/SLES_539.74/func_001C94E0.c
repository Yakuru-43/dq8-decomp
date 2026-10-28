// range: 0x1C94E0 0x1C9560
#include "common.h"

s32 func_001A2190(s32);

typedef struct {
    s32 field_00;
    f32 field_04;
    s32 field_08;
    f32 field_0C;
} S_arg0;

s32 func_001C94E0(S_arg0 *arg0) {
    s32 val;
    s32 a1;
    s32 ret;

    if (arg0->field_00 == 1) {
        val = (s32)arg0->field_04;
    } else {
        val = *(s32 *)&arg0->field_04;
    }

    ret = func_001A2190(val);
    if (ret != 0) {
        if (arg0->field_08 == 1) {
            a1 = (s32)arg0->field_0C;
        } else {
            a1 = *(s32 *)&arg0->field_0C;
        }
        *(s32 *)(ret + 0x1650) = a1;
        return 1;
    }
    return 0;
}
