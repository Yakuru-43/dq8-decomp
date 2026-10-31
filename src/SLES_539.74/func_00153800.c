// range: 0x00153800 0x001538F0
#include "common.h"

void *func_0014EA80(s32, s32);

struct Buf3 {
    s32 count;
    s32 *buf1;
    s32 *buf2;
    s32 *buf3;
};

s32 func_00153800(struct Buf3 *arg0, s32 arg1, s32 arg2) {
    s32 size;
    s32 i;

    arg0->count = 0;
    size = arg1 << 2;
    arg0->buf1 = func_0014EA80(size, arg2);
    arg0->buf2 = func_0014EA80(size, arg2);
    arg0->buf3 = func_0014EA80(size, arg2);
    if (arg0->buf1 != 0 && arg0->buf2 != 0 && arg0->buf3 != 0) {
        arg0->count = arg1;
        for (i = 0; i < arg1; i++) {
            arg0->buf2[i] = 0;
            arg0->buf3[i] = 0;
            arg0->buf1[i] = 0;
        }
        return 1;
    }
    return 0;
}
