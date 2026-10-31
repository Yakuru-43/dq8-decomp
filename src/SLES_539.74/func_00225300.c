// range: 0x225300 0x2253D0
#include "common.h"

extern s16 D_00415E92 __attribute__((section(".data")));
extern s16 D_00415E94 __attribute__((section(".data")));
extern s16 D_00415E96 __attribute__((section(".data")));
extern s16 D_00415E9A __attribute__((section(".data")));
extern s32 D_00415EB8 __attribute__((section(".data")));
extern M2C_UNK D_00415A40 __attribute__((section(".data")));
extern s32 D_003E0A18 __attribute__((section(".sdata")));
extern u8 D_003E0A40 __attribute__((section(".sdata")));

void func_00220900(s32, s32);
void func_002F5EB0(s32, s32);
void func_00214C00(s32, s32);
void func_00220750(s32, s32);
void func_002202E0(void *, void *);

void func_00225300(void) {
    s32 buf[2];
    u8 *p;
    u32 n;

    D_00415E94 = 0;
    D_00415E96 = -1;
    D_00415E9A = *(s32 *)D_003E0A18;
    D_00415E92 = 0;
    func_00220900(D_00415EB8, 0);
    func_002F5EB0(D_00415EB8, 2);
    func_00214C00(D_00415EB8, 0x32C8);
    func_00220750(D_00415EB8, 1);
    p = (u8 *)buf;
    n = 8;
    if (p != 0) {
        do {
            *p++ = 0;
            n--;
        } while (n != 0);
    }
    buf[0] = D_00415EB8;
    func_002202E0(&D_00415A40, buf);
    D_003E0A40 = 0;
}
