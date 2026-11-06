// range: 0x46B550 0x46B590
#include "common.h"

typedef struct TagArg {
    /* 0x00 */ s32 tag;
    /* 0x04 */ s32 bits;
} TagArg;

extern s32 D_003E1B9C;
extern void func_1A6FE0(s32, f32);

s32 func_0046B550(TagArg *p) {
    f32 x0 = p->tag == 0 ? (f32)p->bits : *(f32 *)&p->bits;

    func_1A6FE0(D_003E1B9C, x0);
    return 1;
}
