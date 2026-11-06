// range: 0x3713C0 0x371490
#include "common.h"

typedef struct {
    /* 0x00 */ char pad_00[0x18];
    /* 0x18 */ s32 unk_18;
} S_hdr;

s32 func_003715D0(void *arg0);
s32 func_003715E0(void *arg0);

s32 func_003713C0(S_hdr *arg0, s32 arg1) {
    s32 a;
    s32 b;

    if (arg0->unk_18 == 0) {
        return 0;
    }
    if (arg1 == 0) {
        a = func_003715E0((void *)arg0->unk_18);
        b = func_003715E0(arg0);
        if (a != b) {
            return func_003715E0((void *)arg0->unk_18) - func_003715E0(arg0);
        }
    }
    if (arg1 == 1) {
        a = func_003715D0((void *)arg0->unk_18);
        b = func_003715D0(arg0);
        if (a != b) {
            return func_003715D0((void *)arg0->unk_18) - func_003715D0(arg0);
        }
    }
    return 0;
}
