// range: 0x210C90 0x210DD0
// flags: -flag divbyzerocheck
// (the original guards the divides with bnez + break 0, 7: #pragma divbyzerocheck)
#include "common.h"

extern s32 func_0022A880(s32 value);
extern void func_00133CB8(char *dst, char *src);
extern s32 func_00210DD0(s32 base, s32 exp);

extern char D_003C7798[];
extern char *D_003A53A0[];

/* Writes value as right-aligned two-byte digit glyphs, padded to count. */
void func_00210C90(char *out, s32 value, s32 count) {
    s32 rest;
    s32 outPos;
    s32 digits;
    s32 i;
    char *str;
    s32 pow10;

    if (out == 0) {
        return;
    }
    outPos = 0;
    rest = value;
    digits = func_0022A880(value);
    if (0 < count) {
        count -= digits;
        out[0] = 0;
        for (i = 0; i < count; i++) {
            func_00133CB8(out, D_003C7798);
            outPos += 2;
        }
    }
    while (digits > 0) {
        if (digits == 1) {
            str = D_003A53A0[rest];
        } else {
            pow10 = func_00210DD0(10, digits - 1);
            str = D_003A53A0[rest / pow10];
            rest %= pow10;
        }
        out[outPos] = str[0];
        out[outPos + 1] = str[1];
        outPos += 2;
        digits--;
    }
    out[outPos] = 0;
}
