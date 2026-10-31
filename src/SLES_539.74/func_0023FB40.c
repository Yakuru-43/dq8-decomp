// range: 0x23FB40 0x23FC50
#include "common.h"

s32 func_00132D38(void);

typedef struct {
    s32 field_00;
    f32 field_04;
    s32 field_08;
    char *field_0C;
} S_arg0;

s32 func_0023FB40(S_arg0 *arg0, s32 arg1) {
    f32 scale;
    s32 n;
    s32 r;
    f32 rf;
    f32 res;
    s32 ires;

    if (arg1 != 2) {
        return 0;
    }

    if (arg0->field_00 == 1) {
        if (arg0->field_00 == 0) {
            scale = (f32)*(s32 *)&arg0->field_04;
        } else {
            scale = arg0->field_04;
        }
        r = func_00132D38();
        rf = (f32)r;
        res = scale * rf / 2147483648.0f;
        if (arg0->field_08 == 3) {
            *(f32 *)(arg0->field_0C + 4) = res;
        }
    } else {
        if (arg0->field_00 == 1) {
            n = (s32)arg0->field_04;
        } else {
            n = *(s32 *)&arg0->field_04;
        }
        r = func_00132D38();
        rf = (f32)r;
        ires = (s32)((f32)n * rf / 2147483648.0f);
        if (arg0->field_08 == 3) {
            *(s32 *)(arg0->field_0C + 4) = ires;
        }
    }
    return 1;
}
