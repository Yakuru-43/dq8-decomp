// range: 0x1C1130 0x1C1200
#include "common.h"

typedef struct {
    /* 0x00 */ s32 type;
    /* 0x04 */ char *ptr;
} Slot1C1130;

typedef struct {
    /* 0x00 */ s32 field_00;
    /* 0x04 */ union {
        f32 as_float;
        s32 as_int;
    } field_04;
    /* 0x08 */ s32 field_08;
    /* 0x0C */ s32 field_0C;
    /* 0x10 */ Slot1C1130 field_10[3];
} S_arg0;

typedef struct {
    s32 _pad[4];
} S_D_00411ED0;

extern S_D_00411ED0 D_00411ED0;

s32 func_001ABCA0(S_D_00411ED0 *, s32, s32, f32 *);

void func_001C1130(S_arg0 *arg0) {
    f32 out[3];
    s32 val;
    f32 val1;
    f32 val2;
    Slot1C1130 *sl;

    if (arg0->field_00 == 1) {
        val = (s32)arg0->field_04.as_float;
    } else {
        val = arg0->field_04.as_int;
    }
    if (func_001ABCA0(&D_00411ED0, val, arg0->field_0C, out) == 0) {
        return;
    }
    sl = arg0->field_10;
    if (sl->type == 3) {
        *(f32 *)(sl->ptr + 4) = out[0];
    }
    sl = arg0->field_10 + 1;
    val1 = out[1];
    if (sl->type == 3) {
        *(f32 *)(sl->ptr + 4) = val1;
    }
    val2 = out[2];
    if (arg0->field_10[2].type != 3) {
        return;
    }
    *(f32 *)(arg0->field_10[2].ptr + 4) = val2;
}
