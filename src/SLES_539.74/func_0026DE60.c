// range: 0x26DE60 0x26DED0
#include "common.h"

struct Struct0026DE60 {
    u8 pad0[0x20];
    s32 field_20;
    u8 pad24[0x30];
    void *field_54;
};

struct Struct0026DE60b {
    u8 pad0[0x10];
    s16 field_10;
    s16 field_12;
};

extern char *func_002682D0(void *, s32, s32, s32);
extern s32 func_001667C0(s32);

s32 func_0026DE60(s32 arg0, s32 arg1, struct Struct0026DE60 **arg2) {
    struct Struct0026DE60 *v0;
    struct Struct0026DE60b *s0;
    void *a0;
    s32 r1;

    v0 = *arg2;
    a0 = v0->field_54;
    if (a0 == 0) {
        return 0;
    }
    s0 = (struct Struct0026DE60b *)func_002682D0(a0, v0->field_20, 1, 0);
    r1 = func_001667C0(arg0);
    s0->field_10 = (s16)r1;
    s0->field_12 = (s16)func_001667C0(arg0 + 8);
    return 1;
}
