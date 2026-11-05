// range: 0x356D00 0x356DE0
#include "common.h"

typedef struct {
    /* 0x0 */ union { s32 i; f32 f; } v;
    /* 0x4 */ s8 type;
} Val;

void func_00356D00(Val *result, Val *right, Val *left) {
    Val temp;

    temp.v.f = right->v.f;
    M2C_FIELD(&temp, s8 *, 4) = right->type;
    if (left->type == 0) {
        s32 lval = left->v.i;
        if (M2C_FIELD(&temp, s8 *, 4) == 0) {
            temp.v.i = temp.v.i + lval;
        } else if (M2C_FIELD(&temp, s8 *, 4) == 1) {
            temp.v.f = temp.v.f + (f32)lval;
        } else {
            temp.v.i = 0;
            M2C_FIELD(&temp, s8 *, 4) = -1;
        }
    } else if (left->type == 1) {
        f32 lval = left->v.f;
        if (M2C_FIELD(&temp, s8 *, 4) == 0) {
            M2C_FIELD(&temp, s8 *, 4) = 1;
            temp.v.f = (f32)temp.v.i + lval;
        } else if (M2C_FIELD(&temp, s8 *, 4) == 1) {
            temp.v.f = temp.v.f + lval;
        } else {
            temp.v.i = 0;
            M2C_FIELD(&temp, s8 *, 4) = -1;
        }
    }
    result->v.f = temp.v.f;
    result->type = temp.type;
}
