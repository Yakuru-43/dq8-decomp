// range: 0x4610B0 0x461140
#include "common.h"

extern void func_20C2D0(void *, s32);
extern void func_20CDA0(void *);
extern void func_3056D0(void);
extern void func_305740(s32, s32, u32);

extern u8 D_003E0148[] __attribute__((section(".sdata")));

typedef struct {
    char pad0[0x14];
    void *unk14;
    char pad18[0x50 - 0x18];
    s32 unk50;
} S_self;

void func_004610B0(s32 idx, S_self *self) {
    s8 buf[4];
    void *p;

    p = self->unk14;
    if (p == 0) {
        return;
    }
    func_20C2D0(p, 0);
    func_20CDA0(p);
    buf[0] = D_003E0148[0];
    buf[1] = D_003E0148[1];
    buf[2] = D_003E0148[2];
    func_305740(buf[idx], 0, D_003E0148[0]);
    func_3056D0();
    self->unk50 = 1;
}
