// range: 0x218E00 0x218F40
// flags: -flag divbyzerocheck
#include "common.h"

extern void func_00133CB8(char *dst, char *src);
extern s32 func_00218F40(s32 base, s32 count);
extern s32 func_0022A880(s32 value);
extern char *D_003A5C60[];
extern char D_003C7F88[];

void func_00218E00(char *dst, s32 n, s32 width) {
    s32 value;
    s32 written;
    s32 digits;
    s32 i;
    s32 count;
    char *src;
    s32 div;

    if (dst == 0) {
        return;
    }
    value = n;
    written = 0;
    digits = func_0022A880(n);
    if (0 < width) {
        count = width - digits;
        *dst = 0;
        for (i = 0; i < count; i++) {
            func_00133CB8(dst, D_003C7F88);
            written++;
        }
    }
    while (digits > 0) {
        if (digits == 1) {
            src = D_003A5C60[value];
        } else {
            div = func_00218F40(10, digits - 1);
            src = D_003A5C60[value / div];
            value = value % div;
        }
        dst[written] = *src;
        written++;
        digits--;
    }
    dst[written] = 0;
}
