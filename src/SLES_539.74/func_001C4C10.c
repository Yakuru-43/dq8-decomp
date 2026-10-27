// range: 0x1C4C10 0x1C4C90
#include "common.h"

extern void func_001A30A0(void *arg0);
extern char *D_003E06FC;

typedef struct {
    /* 0x0 */ s32 isFloat;
    /* 0x4 */ union { s32 i; f32 f; } v;
} Tagged;

s32 func_001C4C10(Tagged *arg0) {
    s32 x;
    char *entry;

    if (arg0[0].isFloat == 1) {
        x = (s32)arg0[0].v.f;
    } else {
        x = arg0[0].v.i;
    }
    if (x >= 0 && x < 32) {
        entry = D_003E06FC + x * 1520;
    } else {
        entry = 0;
    }
    if (entry == 0) {
        return 0;
    }
    func_001A30A0(entry);
    return 1;
}
