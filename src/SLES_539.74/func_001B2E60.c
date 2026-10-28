// range: 0x1B2E60 0x1B2F00
#include "common.h"

s32 func_001CFF60(char *, s32);
s32 func_001CFBC0(s32, M2C_UNK *, s32, s32);
extern M2C_UNK D_003C44F8 __attribute__((section(".data")));

typedef struct {
    s32 field_00;
    f32 field_04;
    s32 field_08;
    char *field_0C;
    s32 field_10;
    f32 field_14;
} S_arg0;

s32 func_001B2E60(S_arg0 *arg0) {
    s32 id0;
    s32 id1;
    char *name;
    s32 obj;

    if (arg0->field_00 == 1) {
        id0 = (s32)arg0->field_04;
    } else {
        id0 = *(s32 *)&arg0->field_04;
    }
    name = arg0->field_0C;
    if (arg0->field_10 == 1) {
        id1 = (s32)arg0->field_14;
    } else {
        id1 = *(s32 *)&arg0->field_14;
    }
    obj = func_001CFF60(name, 0);
    if (!obj) {
        obj = 0;
    } else {
        obj = func_001CFBC0(id0, &D_003C44F8, id1, obj);
    }
    return obj;
}
