// range: 0x33F590 0x33F5D0
#include "common.h"

typedef struct {
    u8 pad[0x20];
    s32 count;
    s16 *base;
} SearchStruct;

s16 *func_0033F590(SearchStruct *arg0, s32 arg1) {
    s32 i;
    s16 *p;

    for (i = 0; i < arg0->count; i++) {
        p = arg0->base + (i * 4);
        if (*p == arg1) {
            return p;
        }
    }

    return NULL;
}
