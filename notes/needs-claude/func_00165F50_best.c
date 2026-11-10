// range: 0x165F50 0x166130
// best draft (not matched, not committed)
#include "common.h"

typedef struct {
    s32 field_00;
    s32 field_04;
    s32 field_08;
} Struct_165F50;

union ValueU {
    s32 i;
    f32 f;
};

struct TypeVal {
    s32 type;
    union ValueU v;
};

union Val64 {
    s64 ll;
    struct TypeVal tv;
};

s32 func_001341D8(s32, s32 *);                       /* extern */
void func_00166670(void *, s64);                      /* extern */

s32 func_00165F50(Struct_165F50 *arg0) {
    s8 buf[0x408];
    union Val64 val;
    s32 base;
    s32 cursor;
    s32 count;
    s32 i;
    s32 j;
    s32 b;
    s32 t;
    s32 r;
    s32 d;
    s32 p;

    base = arg0->field_00;
    cursor = arg0->field_08;
    count = *(s16 *)(base + cursor);
    arg0->field_08 = cursor + 2;
    if (count == 0) {
        return 0;
    }
    for (i = 0; i < count; i++) {
        cursor = arg0->field_08;
        arg0->field_08 = cursor + 1;
        b = *(u8 *)(arg0->field_00 + cursor);
        if (b == 3) {
            buf[i] = 0;
        } else if (b == 2) {
            buf[i] = 2;
        } else if (b == 1) {
            buf[i] = 1;
        }
    }
    cursor = arg0->field_08;
    r = cursor & 3;
    if (cursor < 0 && r != 0) {
        r -= 4;
    }
    if (r != 0) {
        arg0->field_08 = arg0->field_08 + 4 - r;
    }
    for (j = 0; j < count; j++) {
        t = buf[j];
        val.tv.type = t;
        if (t == 0) {
            base = arg0->field_00;
            cursor = arg0->field_08;
            p = base + cursor;
            val.tv.v.i = p;
            d = func_001341D8(p, &val.tv.v.i) + 1;
            r = d & 3;
            if (d < 0 && r != 0) {
                r -= 4;
            }
            if (r != 0) {
                d = d + 4 - r;
            }
            arg0->field_08 = arg0->field_08 + d;
        } else if (t == 2) {
            base = arg0->field_00;
            cursor = arg0->field_08;
            val.tv.v.f = *(f32 *)(base + cursor);
            arg0->field_08 = cursor + 4;
        } else if (t == 1) {
            base = arg0->field_00;
            cursor = arg0->field_08;
            val.tv.v.i = *(s32 *)(base + cursor);
            arg0->field_08 = cursor + 4;
        }
        func_00166670(arg0, val.ll);
    }
    return count;
}
