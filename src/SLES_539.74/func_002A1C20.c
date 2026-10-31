// range: 0x2A1C20 0x2A1C70
#include "common.h"

typedef struct {
    u8 field_00;
    u8 pad_01[0x1F];
    s16 field_20;
    s32 field_24;
    s16 field_28;
    u8 pad_2A[0x12];
} Entry;

extern Entry D_00421260;

void func_002A1C20(void) {
    s32 i;
    s32 off;
    Entry *e;

    i = 0;
    do {
        off = i * 44;
        i++;
        e = (Entry *)((u8 *)&D_00421260 + off);
        e->field_00 = 0;
        e->field_24 = -1;
        e->field_28 = -1;
        e->field_20 = 4;
    } while (i < 4);
}
