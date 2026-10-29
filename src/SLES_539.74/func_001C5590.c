// range: 0x1C5590 0x1C5670
#include "common.h"

extern void func_001A3870(char *arg0, f32 *arg1);
extern char *D_003E06FC;

typedef struct {
    /* 0x0 */ s32 isFloat;
    /* 0x4 */ union { s32 i; f32 f; } v;
} Tagged;

s32 func_001C5590(Tagged *arg0) {
    f32 args[4];
    f32 f1;
    f32 f2;
    f32 f3;
    s32 x;
    char *entry;
    Tagged *t1;
    Tagged *t2;

    if (arg0[0].isFloat == 1) {
        x = (s32)arg0[0].v.f;
    } else {
        x = arg0[0].v.i;
    }
    t1 = arg0 + 1;
    if (t1->isFloat == 0) {
        f1 = (f32)t1->v.i;
    } else {
        f1 = t1->v.f;
    }
    args[0] = f1;
    t2 = arg0 + 2;
    if (t2->isFloat == 0) {
        f2 = (f32)t2->v.i;
    } else {
        f2 = t2->v.f;
    }
    args[1] = f2;
    if (arg0[3].isFloat == 0) {
        f3 = (f32)arg0[3].v.i;
    } else {
        f3 = arg0[3].v.f;
    }
    args[2] = f3;
    args[3] = 1.0f;
    if (x >= 0 && x < 32) {
        entry = D_003E06FC + x * 1520;
    } else {
        entry = 0;
    }
    if (entry == 0) {
        return 0;
    }
    func_001A3870(entry, args);
    return 1;
}
