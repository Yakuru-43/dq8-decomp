// range: 0x1ED790 0x1ED820
#include "common.h"

extern s32 func_00166760(void);
extern s32 func_001341D8(void *);
extern s32 func_0018F5A0(s32);
extern s32 func_0014E130(void *, s32);
extern s32 func_001340C0(void *, void *);

extern void *D_003E0790;
extern void *D_003E0770;

s32 func_001ED790(void) {
    void *s1;
    void *s0;
    void *v1;

    if (D_003E0790 == NULL) {
        return 0;
    }
    s1 = (void *)func_00166760();
    if (s1 == NULL) {
        return 0;
    }
    s0 = (void *)func_0014E130(D_003E0770, func_0018F5A0(func_001341D8(s1) + 1));
    if (s0 != NULL) {
        func_001340C0(s0, s1);
    }
    v1 = D_003E0790;
    *(s32 *)((char *)v1 + 0x3C) = (s32)s0;
    return 1;
}
