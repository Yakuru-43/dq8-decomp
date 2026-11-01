// range: 0x22A6F0 0x22A840
// flags: -flag divbyzerocheck
#include "common.h"

s32 func_0012D4C0(s32);
void func_00133CB8(char *, const char *);
extern const char *D_003A5E90[] __attribute__((section(".data")));

static inline s32 count_digits(s32 n) {
    s32 digits = 1;
    s32 v = func_0012D4C0(n);

    while (v >= 10) {
        v /= 10;
        digits++;
    }
    return digits;
}

void func_0022A6F0(char *buf, s32 n) {
    s32 rest;
    s32 digits;
    s32 e;
    s32 p;
    s32 i;
    s32 q;

    if (buf == NULL || n < 0) {
        return;
    }
    rest = n;
    *buf = 0;
    digits = count_digits(n);
    while (digits > 0) {
        e = digits - 1;
        if (e == 0) {
            func_00133CB8(buf, D_003A5E90[rest]);
            break;
        }
        if (e > 0) {
            p = 10;
            for (i = 0; i < digits - 2; i++) {
                p *= 10;
            }
        } else {
            p = 1;
        }
        q = rest / p;
        func_00133CB8(buf, D_003A5E90[q]);
        rest -= q * p;
        digits--;
    }
}
