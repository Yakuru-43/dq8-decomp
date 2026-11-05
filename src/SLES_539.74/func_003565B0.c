// range: 0x3565B0 0x356660
#include "common.h"

typedef struct {
    /* 0x0 */ union { s32 i; f32 f; } v;
    /* 0x4 */ s8 type;
} Val;

static inline f32 Val_GetFloat(Val *v) {
    if (v->type == 1) {
        return v->v.f;
    }
    if (v->type == 0) {
        return (f32)v->v.i;
    }
    return 0.0f;
}

s32 func_003565B0(Val *arg0, Val *arg1) {
    if (arg0->type == 0) {
        if (arg1->type == 0) {
            return arg0->v.i >= arg1->v.i;
        }
    }
    return Val_GetFloat(arg0) >= Val_GetFloat(arg1);
}
