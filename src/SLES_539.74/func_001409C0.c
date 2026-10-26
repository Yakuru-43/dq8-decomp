// range: 0x1409C0 0x140A30
#include "common.h"

typedef struct {
    /* 0000 */ char pad_0[0x20];
    /* 0020 */ f32 base;
    /* 0024 */ f32 top;
} Scale;

typedef struct {
    /* 0000 */ char pad_0[0xF20];
    /* 0F20 */ Scale *scale;
    /* 0F24 */ char pad_1[0x3BC4 - 0xF24];
    /* 3BC4 */ s32 max;
} Obj;

s32 func_001409C0(Obj *o, f32 sub) {
    s32 max;
    Scale *sc;
    f32 top;
    f32 base;
    f32 s;
    f32 result;
    s32 ret;

    sc = o->scale;
    max = o->max;
    top = sc->top;
    base = sc->base;
    s = sub;
    result = (f32)max * (top - s) / (top - base);
    ret = (s32)result;
    if (ret < 0) {
        ret = 0;
    }
    if (max < ret) {
        ret = max;
    }
    return ret;
}
