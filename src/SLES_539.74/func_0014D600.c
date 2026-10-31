// range: 0x0014D600 0x0014D700
#include "common.h"

extern u32 func_001341D8(void *);
extern void func_001340C0(char *, void *);
extern void DebugPrintf(char *, s32, s32, void *);
extern char D_003C2040[];

typedef struct Buf {
    char pad_00[0x20];
    s32 flag20; /* 0x20 */
    char pad_24[4];
    char *base28; /* 0x28 */
    s32 count2C;  /* 0x2C */
    char pad_30[4];
    s32 limit34; /* 0x34 */
    char pad_38[0x1C];
    s32 spin54; /* 0x54 */
} Buf;

char *func_0014D600(void *arg0, Buf *arg1) {
    u32 r;
    u32 q;
    s32 n;
    char *result;

    if (arg0 == 0) {
        return 0;
    }
    r = func_001341D8(arg0);
    q = r + 1;
    if ((q & 0xF) != 0) {
        n = (q >> 4) + 1;
    } else {
        n = q >> 4;
    }
    if (arg1->flag20 != 0) {
        result = 0;
    } else if (n <= 0) {
        result = 0;
    } else if (arg1->count2C + n > arg1->limit34) {
        DebugPrintf(D_003C2040, arg1->count2C + n, arg1->limit34, arg1);
        while (arg1->spin54 != 0) {
        }
        result = 0;
    } else {
        result = arg1->base28 + (arg1->count2C << 4);
        arg1->count2C += n;
    }
    if (result == 0) {
        return 0;
    }
    func_001340C0(result, arg0);
    return result;
}
