// range: 0x1C93E0 0x1C9460
#include "common.h"

s32 func_001A2190(s32);

typedef struct {
    s32 field_00;
    f32 field_04;
    s32 field_08;
    f32 field_0C;
} S_arg0;

s32 func_001C93E0(S_arg0 *arg0) {
    s32 val;
    s32 a1;
    void *ret;

    if (arg0->field_00 == 1) {
        val = (s32)arg0->field_04;
    } else {
        val = *(s32 *)&arg0->field_04;
    }

    ret = (void *)func_001A2190(val);
    if (ret == 0) {
        return 0;
    }

    if (arg0->field_08 == 1) {
        a1 = (s32)arg0->field_0C;
    } else {
        a1 = *(s32 *)&arg0->field_0C;
    }

    *(s32 *)((char *)ret + 0x1660) = a1;
    return 1;
}
