// range: 0x285670 0x2856B0
#include "common.h"

typedef struct {
    /* 0x0 */ u8 pad[0x28];
    /* 0x28 */ u32 records;
    /* 0x2C */ u32 count;
} RecordSet;

extern RecordSet *D_004209DC __attribute__((section(".data")));
extern u32 D_00420A64 __attribute__((section(".data")));
extern u32 D_00420A68 __attribute__((section(".data")));

s32 func_00285670(void) {
    RecordSet *set = D_004209DC;

    if (set == 0) {
        return 0;
    }
    D_00420A64 = set->records + (set->count << 4);
    D_00420A68 = 0;
    return 1;
}
