// range: 0x212130 0x2121F0
#include "common.h"

typedef struct {
    s32 type;
    s32 val;
} Item;

typedef struct {
    char pad0[0x50];
    f32 vals[3];
    f32 unk5C;
} Window;

extern Window *D_003E0944;
extern f32 D_003DF4B8;

s32 func_001667C0(Item *);
void func_00166700(f32 *, Item *);
f32 func_0013BCA0(f32);

s32 func_00212130(Item *arg0) {
    s32 val;
    Item *p;
    s32 i;

    val = func_001667C0(arg0);
    p = arg0 + 1;
    if (!val) {
        func_00166700(D_003E0944->vals, p);
    }
    if (val == 1) {
        for (i = 0; i < 3; i++) {
            val = func_001667C0(p);
            p = p + 1;
            D_003E0944->vals[i] = func_0013BCA0(D_003DF4B8 * (f32)val);
        }
    }
    D_003E0944->unk5C = 1.0f;
    return 1;
}
