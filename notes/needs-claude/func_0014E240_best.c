// best attempt, score 24 CLASS structural — see func_0014E240.md
// range: 0x0014E240 0x0014E320
#include "common.h"

extern void DebugPrintf(char *, s32, s32, void *);
extern char D_003C2040[];

typedef struct BufE240 {
    u8 gap00[0x20];
    s32 flag20; /* 0x20 */
    u8 gap24[4];
    char *base28; /* 0x28 */
    s32 count2C;  /* 0x2C */
    u8 gap30[4];
    s32 limit34; /* 0x34 */
} BufE240;

char *func_0014E240(BufE240 *buf, s32 n) {
    s32 mis;
    s32 d;
    s32 add;
    s32 count;
    s32 total;
    char *result;

    if (buf->flag20 == 0) {
        mis = (s32)(buf->base28 + (buf->count2C << 4)) & 0x3F;
        if (mis != 0) {
            d = 0x40 - mis;
            add = d / 16;
            buf->count2C = buf->count2C + add;
        }
        if (buf->count2C >= buf->limit34) {
            buf->count2C = buf->limit34;
        }
    }
    if (buf->flag20 != 0) {
        return 0;
    }
    if (n <= 0) {
        return 0;
    }
    count = buf->count2C;
    total = count + n;
    if (total > buf->limit34) {
        DebugPrintf(D_003C2040, total, buf->limit34, buf);
        return 0;
    }
    result = buf->base28 + (count << 4);
    buf->count2C = buf->count2C + n;
    return result;
}
