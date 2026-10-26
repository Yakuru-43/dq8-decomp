// range: 0x299A30 0x299A60
#include "common.h"

struct Entry { s64 lo; s64 hi; u8 pad[16]; };

extern struct Entry D_003DB410[] __attribute__((section(".data")));

void func_00299A30(s32 arg0, s64 *arg1, s64 *arg2)
{
    u32 i = arg0 & 0xFF;
    struct Entry *e = &D_003DB410[i];
    *arg1 = e->lo;
    *arg2 = e->hi;
}
