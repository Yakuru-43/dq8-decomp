// range: 0x2F4240 0x2F42B0
#include "common.h"

struct Entry {
    u8 pad0[4];
    u8 field_04;
    u8 pad1[7];
    u8 field_0C;
    u8 pad2[3];
};

extern struct Entry D_003AC950[];

s32 func_002F4240(s32 arg0) {
    s32 temp_v0;
    struct Entry *var_a2;
    u8 temp_v0_2;

    temp_v0 = (s8)arg0;
    if (temp_v0 >= 0x61) {
        if (temp_v0 < 0x7B) {
            return (s8)(temp_v0 - 0x20);
        }
    }
    var_a2 = &D_003AC950[0];
    while (var_a2->field_04 != 0) {
        if ((arg0 & 0xFF) == var_a2->field_0C) {
            return (s8)var_a2->field_04;
        }
        var_a2++;
    }
    return arg0;
}
