// range: 0x460FE0 0x461070
#include "common.h"

extern s32 func_3055D0(s32);
extern void func_3056A0(void);
extern void func_20C8C0(void *, s32, s32);

typedef struct {
    char pad0[0x14];
    void *unk14;
    char pad18[0x50 - 0x18];
    s32 unk50;
} S_self;

s32 func_00460FE0(S_self *self) {
    void *p;

    if (self == 0) {
        return 1;
    }
    if (self->unk50 < 0) {
        return 1;
    }
    if (func_3055D0(-1) != 0) {
        return 0;
    }
    p = self->unk14;
    if (p != 0) {
        func_3056A0();
        func_20C8C0(p, 0, -1);
    }
    self->unk50 = -0x400;
    return 1;
}
