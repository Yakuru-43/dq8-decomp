// range: 0x166910 0x1669E0
#include "common.h"

struct Unk166910 {
    char pad0[0x10];
    f32 q10[4];
    f32 q20[4];
    f32 q30[4];
    char pad40[0x80];
    virtual s32 vf0();
    virtual s32 vf1();
    virtual s32 vf2();
    virtual s32 vf3();
    virtual s32 vf4(f32, f32 *);
    virtual void vf5(f32 *);
};

extern "C" {

extern void func_0010ABC0(f32 *, f32 *, f32 *);
extern void func_0010AFB8(f32, f32 *, f32 *);
extern void func_0013B720(f32 *, f32 *);
extern f32 func_0013BCA0(f32);
extern void func_0013D140(f32 *, f32 *, f32 *);
extern void func_0013D2B0(f32 *);

void func_00166910(Unk166910 *self, f32 angle) {
    f32 mtxB[16];
    f32 mtxA[16];

    self->vf4(angle, mtxB);
    func_0013D2B0(mtxA);
    func_0010AFB8(func_0013BCA0(angle), mtxA, mtxA);
    func_0013D140(mtxB, mtxB, mtxA);
    self->vf5(mtxB);
    func_0010ABC0(self->q30, self->q10, self->q20);
    func_0010ABC0(self->q10, self->q20, self->q30);
    func_0013B720(self->q10, self->q10);
    func_0013B720(self->q20, self->q20);
    func_0013B720(self->q30, self->q30);
}

}
