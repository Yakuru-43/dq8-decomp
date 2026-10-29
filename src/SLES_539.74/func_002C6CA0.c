// range: 0x2C6CA0 0x2C6D30
#include "common.h"

typedef struct {
    u8 pad[8];
    s16 field_08;
    u8 pad2[150];
} Entry160;

typedef struct {
    u8 pad[0x44];
    s16 count1;
    u8 pad1[2];
    Entry160 *base1;
    s16 count2;
    u8 pad2[2];
    Entry160 *base2;
} SearchStruct;

s32 func_002C6CA0(SearchStruct *arg0, s32 arg1) {
    s32 i;

    if (arg0 == NULL) {
        return 0;
    }

    for (i = 0; i < arg0->count1; i++) {
        if (arg1 == arg0->base1[i].field_08) {
            return 1;
        }
    }

    for (i = 0; i < arg0->count2; i++) {
        if (arg1 == arg0->base2[i].field_08) {
            return 1;
        }
    }

    return 0;
}
