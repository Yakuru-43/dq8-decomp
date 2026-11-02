// range: 0x23D9F0 0x23DB90
#include "common.h"

typedef union Value {
    s32 i;
    f32 f;
} Value;

typedef struct {
    s32 tag;
    Value value;
} Arg;

typedef struct {
    /* 0x00 */ s32 field_00;
    /* 0x04 */ s32 field_04;
    /* 0x08 */ s32 field_08;
    /* 0x0C */ u8 pad0C[4];
    /* 0x10 */ f32 field_10;
    /* 0x14 */ f32 field_14;
    /* 0x18 */ f32 field_18;
    /* 0x1C */ f32 field_1C;
    /* 0x20 */ f32 field_20;
    /* 0x24 */ f32 field_24;
    /* 0x28 */ f32 field_28;
    /* 0x2C */ f32 field_2C;
    /* 0x30 */ f32 field_30;
    /* 0x34 */ f32 field_34;
    /* 0x38 */ f32 field_38;
    /* 0x3C */ f32 field_3C;
    /* 0x40 */ f32 field_40;
    /* 0x44 */ f32 field_44;
    /* 0x48 */ f32 field_48;
    /* 0x4C */ f32 field_4C;
    /* 0x50 */ f32 field_50;
    /* 0x54 */ u8 pad54[0xC];
    /* 0x60 */ s32 field_60[16];
    /* 0xA0 */ s32 field_A0[8];
    /* 0xC0 */ f32 field_C0;
    /* 0xC4 */ u8 padC4[0xC];
    /* 0xD0 */ s32 field_D0[4];
    /* 0xE0 */ f32 field_E0;
    /* 0xE4 */ u8 padE4[0xC];
    /* 0xF0 */ s32 field_F0[6];
    /* 0x108 */ u8 pad108[8];
} Slot; /* 0x110 */

typedef struct {
    /* 0x00 */ u8 pad0[0x28];
    /* 0x28 */ Slot *slots;
    /* 0x2C */ s32 count;
} SlotList;

extern SlotList *D_003E0B24;

s32 func_0023D9F0(Arg *args, s32 kind) {
    s32 n = 1;
    s32 i;
    s32 end;
    SlotList *list;
    Slot *slot;

    if (args[0].tag == 1) {
        i = (s32)args[0].value.f;
    } else {
        i = args[0].value.i;
    }
    if (kind >= 2) {
        n = (args[1].tag == 1) ? (s32)args[1].value.f : args[1].value.i;
    }
    end = n + i;
    for (; i < end; i++) {
        list = D_003E0B24;
        if (list != 0 && i < list->count) {
            slot = &list->slots[i];
        } else {
            slot = 0;
        }
        if (slot == 0) {
            return 0;
        }
        slot->field_00 = 0;
        slot->field_04 = 1;
        slot->field_08 = 0;
        slot->field_10 = 0.0f;
        slot->field_14 = 0.0f;
        slot->field_18 = 0.0f;
        slot->field_1C = 1.0f;
        slot->field_20 = 0.0f;
        slot->field_24 = 0.0f;
        slot->field_28 = 0.0f;
        slot->field_2C = 0.0f;
        slot->field_30 = 128.0f;
        slot->field_34 = 128.0f;
        slot->field_38 = 128.0f;
        slot->field_3C = 128.0f;
        slot->field_44 = 1.0f;
        slot->field_40 = 1.0f;
        slot->field_4C = 0.0f;
        slot->field_48 = 0.0f;
        slot->field_50 = 0.0f;
        slot->field_60[0] = 0;
        slot->field_60[1] = 0;
        slot->field_60[2] = 0;
        slot->field_60[3] = 0;
        slot->field_60[4] = 0;
        slot->field_60[5] = 0;
        slot->field_60[6] = 0;
        slot->field_60[7] = 0;
        slot->field_60[8] = 0;
        slot->field_60[9] = 0;
        slot->field_60[10] = 0;
        slot->field_60[11] = 0;
        slot->field_60[12] = 0;
        slot->field_60[13] = 0;
        slot->field_60[14] = 0;
        slot->field_60[15] = 0;
        slot->field_D0[0] = 0;
        slot->field_D0[1] = 0;
        slot->field_D0[2] = 0;
        slot->field_D0[3] = 0;
        slot->field_E0 = -1.0f;
        slot->field_A0[1] = 0;
        slot->field_A0[0] = 0;
        slot->field_A0[3] = 0;
        slot->field_A0[2] = 0;
        slot->field_A0[5] = 0;
        slot->field_A0[4] = 0;
        slot->field_A0[7] = 0;
        slot->field_A0[6] = 0;
        slot->field_C0 = -1.0f;
        slot->field_F0[0] = 0;
        slot->field_F0[1] = 0;
        slot->field_F0[2] = 0;
        slot->field_F0[3] = 0;
        slot->field_F0[4] = 0;
        slot->field_F0[5] = 0;
    }
    return 1;
}
