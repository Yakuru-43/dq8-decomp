// range: 0x1C2210 0x1C2250
#include "common.h"

struct S_1C2210 {
    s32 field_0;
    f32 field_4;
};

s32 func_00168900(s32);

s32 func_001C2210(struct S_1C2210 *arg0) {
    s32 val;
    if (arg0->field_0 == 1) {
        val = (s32)arg0->field_4;
    } else {
        val = *(s32 *)&arg0->field_4;
    }
    func_00168900(val);
    return 1;
}
