// range: 0x4629F0 0x462AA0
#include "common.h"

extern void func_004659B0(void);
extern void func_22A920(s32);
extern void func_2D38E0(s32, s32, s32, s32);
extern void func_00465D20(void);
extern s32 func_3715D0(s32);
extern void func_00462B20(s32, s32);
extern void func_37CEE0(s32);
extern void func_0045ED00(s32, s32, s32);
extern s32 func_00462AD0(void);
extern void func_37E170(s32, s32);
extern s16 D_003E19BC;

typedef struct {
    char pad0[0x18];
    s32 unk18;
} S_arg0;

s32 func_004629F0(S_arg0 *arg0, s32 arg1) {
    s32 v0;

    D_003E19BC = 0;
    func_004659B0();
    func_22A920(8);
    func_2D38E0(arg1, 0x485, 0, -1);
    func_00465D20();
    v0 = func_3715D0(arg0->unk18);
    func_00462B20(v0, 0);
    func_37CEE0(1);
    func_0045ED00(1, -1, -1);
    func_2D38E0(arg1, 0x1777, 0, -1);
    v0 = func_00462AD0();
    func_37E170(v0, 0);
    return 1;
}
