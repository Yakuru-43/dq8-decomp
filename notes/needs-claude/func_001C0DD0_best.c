// Best attempt for func_001C0DD0 (score 2; see func_001C0DD0.md).
// range: 0x1C0DD0 0x1C0E90
#include "common.h"

typedef struct Slot1C0DD0 {
    /* 0x00 */ s32 type;
    /* 0x04 */ char *ptr;
} Slot1C0DD0;

typedef struct {
    /* 0x00 */ s32 kind;
    /* 0x04 */ union {
        f32 as_float;
        s32 as_int;
    } field_04;
    /* 0x08 */ s32 field_08;
    /* 0x0C */ s32 field_0C;
    /* 0x10 */ Slot1C0DD0 out[3];
} S_1C0DD0;

typedef struct {
    s32 _pad[4];
} S_D_00411ED0;

extern S_D_00411ED0 D_00411ED0;

s32 func_001ABB60(s32, s32, s32, f32 *);

s32 func_001C0DD0(S_1C0DD0 *obj) {
    f32 buf[3];
    f32 val1;
    f32 val2;
    s32 a1;
    s32 a2;
    s32 result;
    f32 *bp;
    Slot1C0DD0 *sl;

    if (obj->kind == 1) {
        a1 = (s32)obj->field_04.as_float;
        a2 = obj->field_0C;
    } else {
        a1 = obj->field_04.as_int;
        a2 = obj->field_0C;
    }
    bp = buf;
    result = func_001ABB60((s32)&D_00411ED0, a1, a2, bp);
    if (result != 0) {
        sl = obj->out;
        if (sl->type == 3) {
            *(f32 *)(sl->ptr + 4) = buf[0];
        }
        sl = obj->out + 1;
        val1 = buf[1];
        if (sl->type == 3) {
            *(f32 *)(sl->ptr + 4) = val1;
        }
        val2 = buf[2];
        if (obj->out[2].type == 3) {
            *(f32 *)(obj->out[2].ptr + 4) = val2;
        }
    }
    return result;
}
