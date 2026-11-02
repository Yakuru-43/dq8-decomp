// range: 0x160350 0x160540
#include "common.h"

typedef struct {
    u8 field_00;
    u8 field_01;
    u8 field_02;
    u8 field_03;
    s32 field_04;
    u8 pad08[0x64];
    s32 field_6C;
    s32 field_70;
    u8 pad74[4];
    u8 field_78;
    u8 pad79[3];
} Slot;

extern s32 D_003DFBA8;
extern s32 D_003DFBAC;
extern s32 D_003E02E0;
extern Slot D_003F7900[];
extern Slot D_003F7978[];
extern s32 func_0011BE38(s32);
M2C_UNK WaitSema(s32);
M2C_UNK SignalSema(s32);

s32 func_00160350(s32 arg0) {
    Slot *p;
    s32 ret;
    u8 type;

    if (arg0 < 0 || arg0 >= 16) {
        p = 0;
    } else {
        p = &D_003F7900[arg0];
        if (p->field_00 == 0) {
            p = 0;
        } else if (D_003F7978[arg0].field_00 != 0) {
            p = 0;
        }
    }
    if (p == 0) {
        ret = -1;
    } else {
        type = p->field_01;
        switch (type) {
        case 0:
            if (D_003DFBA8 >= 0) {
                WaitSema(D_003DFBA8);
            }
            D_003E02E0++;
            ret = func_0011BE38(p->field_04);
            if (D_003DFBA8 >= 0) {
                SignalSema(D_003DFBA8);
            }
            D_003E02E0--;
            break;
        case 2:
        case 4:
        case 1:
            ret = 0;
            break;
        default:
            ret = -1;
            break;
        }
    }
    if (D_003DFBAC >= 0) {
        WaitSema(D_003DFBAC);
    }
    if (arg0 < 0 || arg0 >= 16) {
        p = 0;
    } else {
        p = &D_003F7900[arg0];
        if (p->field_00 == 0) {
            p = 0;
        } else if (D_003F7978[arg0].field_00 != 0) {
            p = 0;
        }
    }
    if (p != 0) {
        p->field_03 = 0;
        p->field_02 = 0;
        p->field_01 = 0;
        p->field_00 = 0;
        p->field_6C = 0;
        p->field_70 = 1;
        p->field_78 = 0;
    }
    if (D_003DFBAC >= 0) {
        SignalSema(D_003DFBAC);
    }
    return ret;
}
