// range: 0x33F4D0 0x33F510
#include "common.h"

typedef struct {
    u8 pad[0x20];
    s32 count;
    s32 *base;
} SearchStruct;

s32 *func_0033F4D0(SearchStruct *arg0, s32 arg1) {
    s32 i;
    s32 *p;

    for (i = 0; i < arg0->count; i++) {
        p = arg0->base + (i * 2);
        if (*p == arg1) {
            return p;
        }
    }

    return NULL;
}
