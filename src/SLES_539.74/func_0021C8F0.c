// range: 0x21C8F0 0x21C970
#include "common.h"

typedef struct {
    u8 pad0[0xF4];
    char *field_F4;
    u8 pad_F8[0x100 - 0xF8];
    s32 field_100;
    s32 *field_104;
    s32 *field_108;
    s32 *field_10C;
} Struct21C8F0;

void func_0021C8F0(Struct21C8F0 *arg0) {
    s32 count;
    u32 diff;
    s32 result;

    count = arg0->field_100;
    if (count > 0) {
        *arg0->field_108 = count;
        *arg0->field_10C = arg0->field_100 | 0x8000;
        *(s128 *)arg0->field_F4 = 0;
        *(s32 *)arg0->field_F4 = 0x17000000;
        arg0->field_F4 += 0x10;
    }
    diff = (u32)arg0->field_F4 - (u32)arg0->field_104;
    result = (s32)diff / 16;
    *arg0->field_104 = (result - 1) | 0x10000000;
}
