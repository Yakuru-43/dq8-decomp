// range: 0x0046AC60 0x0046AE20
// flags: -flag divbyzerocheck   (add on line 2 when working; try_match needs it on the command line too)
#include "common.h"

extern u32 func_100860(s32);
extern void func_100780(u32);
extern void func_131188(char *, s32, s32);

s32 func_0046AC60(s32 value, char *dst, s32 len) {
    s32 count;
    s32 mul;
    s32 i;
    s32 j;
    s32 k;
    u32 work;
    s32 off;
    s32 div10;
    s32 mul10;

    count = 0;
    mul = 1;
    for (i = 0; i < 8; i++) {
        if (value >= mul) {
            count++;
        }
        mul *= 10;
    }
    if (count == 0) {
        return 0;
    }
    work = func_100860(count * 4);
    if (work == 0) {
        return 0;
    }
    for (i = count - 1; i >= 0; i--) {
        if (i <= 0) {
            *(s32 *)(work + i * 4) = value;
        } else {
            div10 = 10;
            for (j = 0; j < i - 1; j++) {
                div10 *= 10;
            }
            *(s32 *)(work + i * 4) = value / div10;
            mul10 = 10;
            for (k = 0; k < i - 1; k++) {
                mul10 *= 10;
            }
            value -= *(s32 *)(work + i * 4) * mul10;
        }
    }
    func_131188(dst, 0, len);
    off = 0;
    for (i = count - 1; i >= 0; i--) {
        dst[off] = ((*(u32 *)(work + i * 4) + 0x7FFF + 0x250) & 0xFF00) >> 8;
        dst[off + 1] = *(s32 *)(work + i * 4) + 0x7FFF + 0x250;
        off += 2;
    }
    func_100780(work);
    return count;
}
