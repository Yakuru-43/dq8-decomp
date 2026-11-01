// range: 0x199E80 0x199F30
// flags: -flag divbyzerocheck
#include "common.h"

void func_001339E0(char *, const char *, s32);
void func_00199F30(char *, s32, s32);
extern char D_003C3708[] __attribute__((section(".data")));
extern char D_003C3710[] __attribute__((section(".data")));

s32 func_00199E80(s32 n, s32 arg1, s32 arg2) {
    char buf[32];
    s32 rem;

    if (n != 0) {
        if (n < 0) {
            n = 0;
        }
        rem = n % 100;
        buf[0] = n / 100 + 0x60;
        buf[1] = 0x5F;
        if (rem >= 10) {
            func_001339E0(&buf[2], D_003C3710, rem);
        } else {
            func_001339E0(&buf[2], D_003C3708, rem);
        }
        func_00199F30(buf, arg1, arg2);
        return 1;
    }
    return 0;
}
