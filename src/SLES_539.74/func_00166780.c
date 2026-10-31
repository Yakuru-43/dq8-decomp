// range: 0x166780 0x1667C0
#include "common.h"

typedef struct {
    s32 type;
    union {
        s32 i;
        f32 f;
    } val;
} Val;

f32 func_00166780(char *arg0) {
    Val *v = (Val *)arg0;

    switch (v->type) {
    case 1:
        return (f32)v->val.i;
    case 2:
        return v->val.f;
    default:
        return 0.0f;
    }
}
