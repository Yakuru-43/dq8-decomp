// range: 0x224680 0x224730
#include "common.h"

extern s16 D_00415E94 __attribute__((section(".data")));
extern s16 D_00415E96 __attribute__((section(".data")));
extern s32 D_00415EB8 __attribute__((section(".data")));
extern s32 D_00415EBC __attribute__((section(".data")));
extern M2C_UNK D_00415A40 __attribute__((section(".data")));
extern u8 D_003E0A44 __attribute__((section(".sdata")));

void func_00220900(s32, s32);
void func_002F5EB0(s32, s32);
void func_00220750(s32, s32);
void func_002202E0(void *, void *);

void func_00224680(void) {
    s32 buf[3];
    u8 *p;
    u32 n;

    D_00415E94 = 0;
    D_00415E96 = -1;
    func_00220900(D_00415EB8, 0);
    func_002F5EB0(D_00415EB8, 1);
    func_00220750(D_00415EB8, 1);
    p = (u8 *)buf;
    D_003E0A44 = 0;
    n = 12;
    if (p != 0) {
        do {
            *p++ = 0;
            n--;
        } while (n != 0);
    }
    buf[0] = D_00415EB8;
    buf[1] = D_00415EBC;
    func_002202E0(&D_00415A40, buf);
}
