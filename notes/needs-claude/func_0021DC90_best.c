// range: 0x21DC90 0x21DDC0
#include "common.h"

typedef struct {
    s32 type;
    union {
        s32 i;
        f32 f;
    } val;
} Val;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
} unk_3E09E4;

extern unk_3E09E4 *D_003E09E4;
f32 func_00166780(Val *);

s32 func_0021DC90(Val *arg0, s32 arg1) {
    f32 a;
    f32 b;
    f32 c;
    f32 d;
    f32 e;
    f32 g;
    Val *p;
    s32 count;

    p = arg0;
    count = arg1;
    if (D_003E09E4 == 0) {
        return 0;
    }
    a = func_00166780(p++);
    b = func_00166780(p++);
    c = func_00166780(p++);
    d = 1.0f;
    e = 1.0f;
    g = 1.0f;
    if (count >= 4) {
        d = func_00166780(p++);
    }
    if (count >= 5) {
        e = 1.0f + func_00166780(p++);
    }
    if (count >= 6) {
        g = func_00166780(p);
    }
    D_003E09E4->unkC = a;
    D_003E09E4->unk10 = b;
    D_003E09E4->unk14 = c;
    D_003E09E4->unk18 = d;
    D_003E09E4->unk20 = e;
    D_003E09E4->unk1C = g;
    return 1;
}
