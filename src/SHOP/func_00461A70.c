// range: 0x461A70 0x461B70
#include "common.h"

extern void func_22A920(s32);
extern void func_2D38E0(void *, s32, s32, s32);
extern void func_2D6430(void *, s32, s32, s32, s32, s32);
extern void func_2D45D0(void *, s32, s32, s32);
extern void func_2D6A80(void *, s32, s32, s32, s32, s32, f32);
extern void func_371050(void *arg0, s32 arg1, s32 arg2, s32 arg3);
M2C_UNK func_0045F560(s32, M2C_UNK *); /* extern */
s32 func_00462620(s32);                /* extern */

extern M2C_UNK D_00474050 __attribute__((section(".data")));

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 pad4;
    s16 unk6;
} S_D00474058;

extern S_D00474058 *D_00474058 __attribute__((section(".data")));

typedef struct {
    char pad0[0x18];
    void *unk18;
} S_arg0;

void func_00461A70(S_arg0 *arg0, void *arg1) {
    func_22A920(3);
    func_2D38E0(arg1, 0x1790, 1, -1);
    func_2D6430(arg1, 0x178F, 2, 0x1790, -5, -2);
    func_2D45D0(arg1, 0x178C, 5, 0);
    func_2D6A80(arg1, 0x1790, 0x17A3, -0x20, 0, 0, 0.5f);
    func_0045F560(func_00462620(1), &D_00474050);
    *(u16 *)((char *)arg0->unk18 + 0x10) = 0;
    D_00474058->unk6 = *(s16 *)((char *)arg0->unk18 + 0x10) + 1;
    func_371050(arg0, 0, D_00474058->unk2 - 1, D_00474058->unk2 - 1);
}
