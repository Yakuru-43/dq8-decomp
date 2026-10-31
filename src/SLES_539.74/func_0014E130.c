// range: 0x0014E130 0x0014E1E0
#include "common.h"

extern void DebugPrintf(char *, s32, s32, void *);
extern char D_003C2040[];

typedef struct BufE130 {
    u8 gap00[0x20];
    s32 flag20; /* 0x20 */
    u8 gap24[4];
    char *base28; /* 0x28 */
    s32 count2C;  /* 0x2C */
    u8 gap30[4];
    s32 limit34; /* 0x34 */
    u8 gap38[0x1C];
    s32 spin54; /* 0x54 */
} BufE130;

char *func_0014E130(BufE130 *buf, s32 n) {
    s32 count;
    s32 total;
    char *result;

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
        while (buf->spin54 != 0) {
        }
        return 0;
    }
    result = buf->base28 + (count << 4);
    buf->count2C = buf->count2C + n;
    return result;
}
