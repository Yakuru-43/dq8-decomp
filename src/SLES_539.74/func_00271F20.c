// range: 0x271F20 0x271F50
// Pass the string through the splice worker: heap strings pass their buffer
// position, short strings pass their length (byte 0 >> 1).
#include "common.h"

extern void func_00107090(void *, u32, u32, u32);

/* short string header: bit 0 is the "heap" flag, bits 1-7 the length */
struct ShortStr {
    u8 heap : 1;
    u8 len : 7;
};

void func_00271F20(void *s, u32 tail) {
    u32 pos;

    if (*(u32 *)s & 1) {
        pos = *(u32 *)((char *)s + 4);
    } else {
        pos = (u8)((struct ShortStr *)s)->len;
    }
    func_00107090(s, pos, 0, tail);
}
