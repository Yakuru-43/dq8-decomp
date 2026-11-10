// range: 0x222CB0 0x222D50
#include "common.h"

struct Obj {
    /* 0x00 */ u8 pad_00[0x2];
    /* 0x02 */ s16 n2;
    /* 0x04 */ s32 total;
    /* 0x08 */ s16 n8;
};

s32 func_00222D50(void *);
s32 func_0022A840(s32, s32);
s32 func_00222D60(struct Obj *);

void func_00222CB0(struct Obj *arg0, s32 arg1) {
    s32 base;
    s32 idx = arg1 + 0;

    if (idx < 0) {
        idx = 9;
    }
    if (idx > 9) {
        idx = 0;
    }
    base = func_0022A840(10, func_00222D50(arg0));
    arg0->total = arg0->total - base * func_00222D60(arg0);
    arg0->total = arg0->total + idx * base;
}
