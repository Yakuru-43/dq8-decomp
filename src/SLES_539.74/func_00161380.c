// range: 0x161380 0x161450
#include "common.h"

typedef struct {
    u8 field_00;
    u8 field_01;
    u8 field_02;
    u8 field_03;
    u8 pad04[0x68];
    s32 field_6C;
    s32 field_70;
    u8 pad74[4];
    u8 field_78;
    u8 pad79[3];
} Slot;

extern s32 D_003DFBAC;
extern Slot D_003F7900[];
M2C_UNK WaitSema(s32);
M2C_UNK SignalSema(s32);

s32 func_00161380(void) {
    Slot *p;
    s32 i;

    if (D_003DFBAC >= 0) {
        WaitSema(D_003DFBAC);
    }
    p = D_003F7900;
    i = 0;
    while (i < 16) {
        if (p->field_00 == 0) {
            break;
        }
        i++;
        p++;
    }
    if (i == 16) {
        p = 0;
        i = -1;
    }
    if (p != 0) {
        p->field_03 = 0;
        p->field_02 = 0;
        p->field_01 = 0;
        p->field_00 = 0;
        p->field_6C = 0;
        p->field_70 = 1;
        p->field_78 = 0;
        p->field_00 = 1;
    }
    if (D_003DFBAC >= 0) {
        SignalSema(D_003DFBAC);
    }
    return i;
}
