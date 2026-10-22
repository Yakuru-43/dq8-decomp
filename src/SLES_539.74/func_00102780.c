// range: 0x102780 0x102840
#include "common.h"

u8 *func_00100EE0(u8 *p, u32 *out);

struct Block {
    u32 pad0[5];   /* 0x00 */
    u32 f14;       /* 0x14 */
    u32 f18;       /* 0x18 */
    u32 pad1[121]; /* 0x1C */
    u128 q200;     /* 0x200 */
    u32 pad2[4];   /* 0x210 */
    u32 f220;      /* 0x220 */
    u32 f224;      /* 0x224 */
    u32 f228;      /* 0x228 */
    u32 f22C;      /* 0x22C */
    u32 f230;      /* 0x230 */
    u32 f234;      /* 0x234 */
};

struct Src {
    u32 pad;
    u8 *flags;     /* 0x04 */
};

/* Unpack a flag byte and three varints into the block; the 0x20 bit
 * selects the source of f18, the 0x40 bit a third varint into f234. */
void func_00102780(struct Block *obj, struct Src *src) {
    u8 *fp;
    s32 flag40;
    u8 *p;

    fp = src->flags;
    flag40 = (s32)*(s8 *)fp & 0x40;
    obj->f230 = (s32)*(s8 *)fp & 0x20;
    obj->f22C = (s32)*(s8 *)fp & 0x10;
    obj->f228 = (s32)*(s8 *)fp & 0xF;
    p = func_00100EE0(fp + 1, &obj->f220);
    p = func_00100EE0(p, &obj->f224);
    if (obj->f230 != 0) {
        obj->f18 = (u32)obj->q200;
    } else {
        obj->f18 = obj->f14;
    }
    if (flag40 != 0) {
        func_00100EE0(p, &obj->f234);
    } else {
        obj->f234 = 0;
    }
}
