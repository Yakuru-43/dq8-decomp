// range: 0x37F990 0x37FA50
#include "common.h"

extern s16 D_00415E94 __attribute__((section(".data")));
extern s32 D_00415EB4 __attribute__((section(".data")));
extern s32 D_00415EB8 __attribute__((section(".data")));
extern s32 D_00415EBC __attribute__((section(".data")));
extern s32 D_00415EC4 __attribute__((section(".data")));
extern s32 D_00415EC8 __attribute__((section(".data")));
extern M2C_UNK D_00415A40 __attribute__((section(".data")));

void func_002202E0(void *, void *);
void func_002204B0(void *);
void func_002209E0(s32, s32);
void func_00312560(s32, s32);

void func_0037F990(void) {
    s32 buf[6];
    u8 *p;
    u32 n;

    D_00415E94 = 0;
    func_002204B0(&D_00415A40);
    p = (u8 *)buf;
    n = 0x18;
    if (p != 0) {
        do {
            *p++ = 0;
            n--;
        } while (n != 0);
    }
    buf[0] = D_00415EB8;
    buf[1] = D_00415EB4;
    buf[2] = D_00415EC4;
    buf[3] = D_00415EC8;
    buf[4] = D_00415EBC;
    func_002202E0(&D_00415A40, buf);
    func_00312560(1, 0);
    func_002209E0(D_00415EB8, 0x4650);
}
