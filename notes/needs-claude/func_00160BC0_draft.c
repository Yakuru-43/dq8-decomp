// range: 0x160BC0 0x160D50
#include "common.h"

typedef struct {
    u8 field_00;
    u8 field_01;
    u8 pad02[2];
    s32 field_04;
    s32 field_08;
    u8 pad0C[8];
    s32 field_14;
    s32 field_18;
    u8 pad1C[0x50];
    s32 field_6C;
    u8 pad70[8];
    u8 field_78;
    u8 pad79[3];
} Slot;

typedef struct {
    u8 field_00;
    u8 pad01[123];
} SlotFlag;

extern Slot D_003F7900[];
extern SlotFlag D_003F7978[];
extern s32 D_003DFBA8;
extern s32 D_003E02E0;
M2C_UNK WaitSema(s32);
M2C_UNK SignalSema(s32);
extern s32 func_0011BFB0(s32, s32, s32);

s32 func_00160BC0(s32 idx, s32 *out, s32 *out2) {
    s32 ret;
    Slot *p;
    u8 type;

    if (idx < 0 || idx >= 16) {
        p = 0;
    } else {
        p = &D_003F7900[idx];
        if (p->field_00 == 0) {
            p = 0;
        } else if (D_003F7978[idx].field_00 != 0) {
            p = 0;
        }
    }
    if (p == 0) {
        return -1;
    }
    if (out2 != 0) {
        *out2 = 0;
    }
    type = p->field_01;
    if (type == 1 || type == 4) {
        *out = p->field_18;
        ret = p->field_08;
        if (out2 != 0) {
            *out2 = p->field_14;
        }
        if (p->field_14 == 0) {
            *out = p->field_08;
        }
    } else if (type == 2) {
        ret = p->field_08;
        *out = ret;
    } else if (type == 0) {
        if (D_003DFBA8 >= 0) {
            WaitSema(D_003DFBA8);
        }
        D_003E02E0++;
        ret = func_0011BFB0(p->field_04, 0, 2);
        func_0011BFB0(p->field_04, p->field_6C, 0);
        if (D_003DFBA8 >= 0) {
            SignalSema(D_003DFBA8);
        }
        D_003E02E0--;
        *out = ret;
    } else {
        ret = -1;
    }
    return ret;
}
