// range: 0x15BF80 0x15C030
#include "common.h"

union Byte48 {
    u64 q;
    u8 flags;
};

struct Obj_15BF80 {
    s16 f_00;
    s16 f_02;
    s16 f_04;
    s16 f_06;
    u8 f_08;
    u8 pad_09[0x1F];
    s16 f_28;
    u8 f_2A;
    u8 f_2B;
    s32 f_2C;
    s16 f_30;
    u8 f_32;
    u8 f_33;
    s16 f_34;
    s16 f_36;
    s64 f_38;
    s64 f_40;
    union Byte48 f_48;
    s32 f_50[4];
    s32 f_60;
    s32 f_64;
};

void func_0015BF80(struct Obj_15BF80 *o) {
    s32 i;
    u8 set1;
    u8 set2;
    set1 = 1;
    set2 = 4;
    o->f_08 = 0;
    o->f_00 = -1;
    i = 0;
    do {
        o->f_50[i] = 0;
        i++;
    } while (i < 4);
    o->f_60 = 0;
    o->f_48.q = 0;
    o->f_40 = 0;
    o->f_38 = 0;
    o->f_48.flags = (o->f_48.flags & ~0x04) | set1;
    o->f_48.flags = (o->f_48.flags & ~0x0C) | set2;
    o->f_06 = 0;
    o->f_04 = 0;
    o->f_02 = 0;
    o->f_36 = 0;
    o->f_28 = 0;
    o->f_2C = 0;
    o->f_30 = 0;
    o->f_32 = 0;
    o->f_33 = 0;
    o->f_34 = 0;
    o->f_64 = 0;
    o->f_2A = 0;
    o->f_2B = 0;
}
