// range: 0x302850 0x302870
#include "common.h"

u8 func_00302850(void *arg0) {
    s32 entries;
    s32 base;

    entries = M2C_FIELD(arg0, s32 *, 0x1C);
    base = M2C_FIELD(arg0, s32 *, 4);
    return *(u8 *)(base + (entries << 6));
}
