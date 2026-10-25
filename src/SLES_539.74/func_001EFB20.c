// range: 0x1EFB20 0x1EFBF0
#include "common.h"

typedef struct {
    char pad0[0x208];
    f32 unk208;
} Unk1EFB20;

extern f32 D_003A4B40 __attribute__((section(".data")));
extern f32 D_003A4B44 __attribute__((section(".data")));
extern f32 D_003A4B48 __attribute__((section(".data")));
extern f32 D_003A4B4C __attribute__((section(".data")));
extern f32 D_003DF56C;
extern void func_0010AF10(f32, f32 *, f32 *);
extern void func_0010B060(f32, f32 *, f32 *);
extern f32 func_0013BCA0(f32);
extern void func_0013C680(s32, f32 *, f32 *);
extern void func_0013D2B0(f32 *);
extern f32 func_001F0190(Unk1EFB20 *);

void func_001EFB20(Unk1EFB20 *arg0, s32 arg1) {
    f32 vec[4];
    f32 mtx[16];

    vec[0] = D_003A4B40;
    vec[1] = D_003A4B44;
    vec[2] = D_003A4B48;
    vec[3] = D_003A4B4C;
    func_0013D2B0(mtx);
    func_0010AF10(func_0013BCA0((D_003DF56C * func_001F0190(arg0)) / 24.0f), mtx, mtx);
    func_0010B060(arg0->unk208, mtx, mtx);
    func_0013C680(arg1, mtx, vec);
}
