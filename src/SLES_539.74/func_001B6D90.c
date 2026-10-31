// range: 0x1B6D90 0x1B6E10
#include "common.h"

char *func_001814D0(void);
s32 func_00308160(char *, s32);

typedef struct {
    s32 field_00;
    union {
        f32 as_float;
        s32 as_int;
    } field_04;
    s32 field_08;
    s32 *field_0C;
} S_arg0;

s32 func_001B6D90(S_arg0 *arg0) {
    s32 val;
    char *temp_v0;
    s32 result;

    if (arg0->field_00 == 1) {
        val = (s32)arg0->field_04.as_float;
    } else {
        val = arg0->field_04.as_int;
    }
    temp_v0 = func_001814D0();
    result = func_00308160(temp_v0, val);
    if (arg0->field_08 == 3) {
        arg0->field_0C[1] = result;
    }
    return 1;
}
