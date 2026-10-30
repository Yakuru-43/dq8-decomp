// range: 0x2E3340 0x2E3380
#include "common.h"

typedef struct {
    u8 pad0[4];
    u8 field_04;
    u8 pad5;
    u16 field_06;
} Entry;

extern Entry D_003AB8E0[];

s32 func_002E3340(s32 arg0) {
    u16 key = (u16)arg0;
    s32 i;

    for (i = 0; D_003AB8E0[i].field_04 != 0; i++) {
        if (D_003AB8E0[i].field_06 == key) {
            return i;
        }
    }
    return 0xFFFF;
}
