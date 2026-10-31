// range: 0x299F60 0x299FB0
#include "common.h"

typedef struct {
    u8 pad[0x1C];
    u8 *base;
    u8 pad2[0x18];
    s32 count;
} SearchStruct;

u8 *func_00299F60(SearchStruct *arg0, s32 arg1) {
    s32 i;

    for (i = 0; i < arg0->count; i++) {
        if (arg1 == arg0->base[i * 12]) {
            return &arg0->base[i * 12];
        }
    }

    return NULL;
}
