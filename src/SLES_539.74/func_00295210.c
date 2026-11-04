// range: 0x295210 0x295480
// rodata: 0x3CB120 0x3CB150
#include "common.h"

f32 func_0013BC60(void);                             /* extern */
s32 func_00292C60(void *);                           /* extern */
s32 func_002933A0(void *, s32);                      /* extern */
s32 func_002933C0(void *, s32);                      /* extern */
s32 func_002933E0(void *, s32);                      /* extern */
s32 func_00293400(void *);                           /* extern */

typedef struct {
    char pad0[0xE0];
    s32 unkE0;
    char pad1[4];
    s32 unkE8;
} S_slot;

typedef struct {
    char pad0[0x58C];
    S_slot *table;
} S_owner;

s32 func_00295210(S_owner *arg0) {
    s32 ret;
    S_slot *slot;
    f32 mult;
    s32 sel;

    if (func_00292C60(arg0) == 0) {
        mult = 12.0f;
    } else {
        mult = 9.0f;
    }
    ret = 0;
    sel = (s32)(mult * func_0013BC60());
    switch (sel) {
    case 0:
        slot = arg0->table;
        slot->unkE0 = 0x1D4;
        arg0->table->unkE8 = 4;
        ret = func_002933E0(arg0, 0x1D4) & 0xFF;
        break;
    case 1:
        slot = arg0->table;
        slot->unkE0 = 0x1D7;
        arg0->table->unkE8 = 4;
        ret = func_002933E0(arg0, 0x1D7) & 0xFF;
        break;
    case 2:
        slot = arg0->table;
        slot->unkE0 = 0x1D8;
        arg0->table->unkE8 = 4;
        ret = func_002933E0(arg0, 0x1D8) & 0xFF;
        break;
    case 3:
        arg0->table->unkE0 = 0x1D9;
        arg0->table->unkE8 = 0;
        ret = func_00293400(arg0) & 0xFF;
        break;
    case 4:
        slot = arg0->table;
        slot->unkE0 = 0x1DB;
        arg0->table->unkE8 = 4;
        ret = func_002933E0(arg0, 0x1DB) & 0xFF;
        break;
    case 5:
        slot = arg0->table;
        slot->unkE0 = 0x1DC;
        arg0->table->unkE8 = 2;
        ret = func_002933C0(arg0, 0x1DC) & 0xFF;
        break;
    case 6:
        slot = arg0->table;
        slot->unkE0 = 0x1DD;
        arg0->table->unkE8 = 4;
        ret = func_002933E0(arg0, 0x1DD) & 0xFF;
        break;
    case 7:
        slot = arg0->table;
        slot->unkE0 = 0x1DE;
        arg0->table->unkE8 = 4;
        ret = func_002933E0(arg0, 0x1DE) & 0xFF;
        break;
    case 8:
        slot = arg0->table;
        slot->unkE0 = 0x1DF;
        arg0->table->unkE8 = 4;
        ret = func_002933E0(arg0, 0x1DF) & 0xFF;
        break;
    case 9:
        slot = arg0->table;
        slot->unkE0 = 0x1D5;
        arg0->table->unkE8 = 3;
        ret = func_002933A0(arg0, 0x1D5) & 0xFF;
        break;
    case 10:
        slot = arg0->table;
        slot->unkE0 = 0x1D6;
        arg0->table->unkE8 = 2;
        ret = func_002933C0(arg0, 0x1D6) & 0xFF;
        break;
    case 11:
        slot = arg0->table;
        slot->unkE0 = 0x1DA;
        arg0->table->unkE8 = 2;
        ret = func_002933C0(arg0, 0x1DA) & 0xFF;
        break;
    }
    return ret;
}
