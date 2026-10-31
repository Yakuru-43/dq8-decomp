// range: 0x1CA0C0 0x1CA230
// best draft, CLASS structural score=48 (48 words differ, 364 vs 364 bytes)
#include "common.h"

void *func_001A2190(s32);
void *func_002F0BF0(void *);
s32 func_002F0BE0(void *);
void func_002F0BD0(void *, s32);
s32 func_002F0BC0(void *);
s32 func_002F6D60(void *, s32, s32);
void func_002E6BB0(void *, s32, s32);
void func_002EA2A0(void *, s32);
void func_002E72C0(void *, s32);

typedef struct {
    /* 0x0 */ s32 isFloat;
    /* 0x4 */ union { s32 i; f32 f; } v;
    /* 0x8 */ s32 tag;
    /* 0xC */ union { s32 i; f32 f; } w;
} TaggedPair;

s32 func_001CA0C0(TaggedPair *arg0) {
    s32 idx;
    s32 sel;
    s32 tag;
    void *r;
    s32 n;
    void *x;
    void *obj;

    if (arg0->isFloat == 1) {
        idx = (s32)arg0->v.f;
    } else {
        idx = arg0->v.i;
    }
    obj = func_001A2190(idx);
    if (obj == 0) {
        return 0;
    }
    tag = arg0->tag;
    switch (tag) {
    case 0:
        sel = (tag == 1) ? (s32)arg0->w.f : arg0->w.i;
        if (sel == -1) {
            func_002EA2A0(obj, sel);
            return 1;
        }
        if (func_002F0BF0(obj) == 0 || func_002F0BE0(obj) < 0) {
            func_002EA2A0(obj, sel);
            return 1;
        }
        r = func_002F0BF0(obj);
        if (r == 0) {
            return 0;
        }
        n = func_002F0BE0(obj);
        if (n > 0) {
            x = (void *)func_002F6D60(r, n, sel);
            if (x == 0) {
                return 0;
            }
            func_002F0BD0(obj, (s32)x);
            x = (void *)func_002F0BC0(obj);
            func_002E72C0(obj, (s32)x);
            return 1;
        }
        return 0;
    case 2:
        func_002E6BB0(obj, arg0->w.i, 0);
        return 1;
    default:
        return 1;
    }
}
