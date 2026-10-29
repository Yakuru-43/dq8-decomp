// range: 0x001CFB20 0x001CFBC0
#include "common.h"

s32 func_001CFF60(char *, s32);
s32 func_001CFBC0(s32, s32, s32, s32);

typedef struct {
    /* 0x00 */ s32 field_00;
    /* 0x04 */ f32 field_04;
    /* 0x08 */ u8 pad_08[4];
    /* 0x0C */ char *field_0C;
    /* 0x10 */ u8 pad_10[4];
    /* 0x14 */ s32 field_14;
    /* 0x18 */ s32 field_18;
    /* 0x1C */ f32 field_1C;
} S_CFB20;

s32 func_001CFB20(S_CFB20 *arg0) {
    s32 id0;
    s32 id1;
    s32 val;
    char *name;
    s32 obj;

    if (arg0->field_00 == 1) {
        id0 = (s32)arg0->field_04;
    } else {
        id0 = *(s32 *)&arg0->field_04;
    }
    name = arg0->field_0C;
    id1 = arg0->field_14;
    if (arg0->field_18 == 1) {
        val = (s32)arg0->field_1C;
    } else {
        val = *(s32 *)&arg0->field_1C;
    }
    obj = func_001CFF60(name, 0);
    if (!obj) {
        obj = 0;
    } else {
        obj = func_001CFBC0(id0, id1, val, obj);
    }
    return obj;
}
