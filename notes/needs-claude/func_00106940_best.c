// range: 0x106940 0x106950
#include "common.h"

extern void *func_001030B0(void *self);

typedef struct {
    u8 pad00[0x48];
    u32 baseOff; /* 0x48: delta back to the base sub-object */
} Adj;

void *func_00106940(void *self) {
    Adj *a = (Adj *)self;
    u32 off;
    char *base;

    off = a->baseOff;
    base = (char *)self - 8;
    return func_001030B0(base + off);
}
