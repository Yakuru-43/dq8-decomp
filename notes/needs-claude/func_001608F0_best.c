// range: 0x1608F0 0x160BC0
// flags: -flag divbyzerocheck
#include "common.h"

typedef struct {
    u8 field_00;
    u8 field_01;
    u8 pad02[2];
    s32 field_04;
    u8 pad08[4];
    s32 field_0C;
    s32 field_10;
    u8 pad14[0x58];
    s32 field_6C;
    s32 field_70;
    u32 field_74;
    u8 field_78;
    u8 pad79[3];
} Slot;

extern Slot D_003F7900[];
extern Slot D_003F7978[];
extern s32 D_003DFBA8;
extern s32 D_003E02E0;
extern char D_003C2430[]; /* "tray open(read file)!!!!\n" */
extern char D_003C2450[]; /* "tray close(read file)!!!!\n" */

M2C_UNK WaitSema(s32);   /* extern */
M2C_UNK SignalSema(s32); /* extern */
extern s32 func_0011C1F0(s32, char *, s32);
extern s32 func_001652B0(void *, char *, s32, s32);
extern s32 func_0012B5B8(s32, s32, char *, u8 *);
extern void func_0012AB80(s32);
extern s32 func_0012B928(void);
extern void DebugPrintf(char *);
extern s32 func_00160120(void);
extern void func_00117898(s32);

s32 func_001608F0(s32 index, char *buffer, s32 size) {
    Slot *slot;
    u8 status[3];
    s32 base;
    s32 ret;
    s32 r;
    u32 unit;

    if (index >= 0 && index < 0x10) {
        slot = &D_003F7900[index];
        if (slot->field_00 == 0 || D_003F7978[index].field_00 != 0) {
            slot = 0;
        }
    } else {
        slot = 0;
    }
    if (slot == 0) {
        return -1;
    }
    if (D_003DFBA8 >= 0) {
        WaitSema(D_003DFBA8);
    }
    D_003E02E0++;
    switch (slot->field_01) {
    case 0:
        ret = func_0011C1F0(slot->field_04, buffer, size);
        if (ret < 0) {
            break;
        }
        slot->field_6C += ret;
        break;
    case 2:
        ret = func_001652B0(&slot->field_0C, buffer, slot->field_6C, size);
        if (ret < 0) {
            break;
        }
        slot->field_6C += ret;
        break;
    case 4:
    case 1:
        unit = (u32)slot->field_70;
        base = (s32)((u32)slot->field_6C / unit);
        ret = (s32)((u32)size / unit);
        if ((u32)size % unit != 0) {
            ret = ret + 1;
        }
        if (slot->field_10 < base + ret) {
            ret = slot->field_10 - base;
        }
        status[0] = 0;
        status[1] = 1;
        if (slot->field_74 & 1) {
            status[1] = 0;
        }
        status[2] = 0;
        while (ret != 0) {
            r = func_0012B5B8(slot->field_0C + base, ret, buffer, status);
            if (r != 0) {
                func_0012AB80(0);
                r = func_0012B928();
            } else {
                r = -1;
            }
            if (r == 0) {
                break;
            }
            if (r != 0x31) {
                DebugPrintf(D_003C2430);
                func_00160120();
                DebugPrintf(D_003C2450);
            }
            func_00117898(100);
        }
        if (ret < 0) {
            break;
        }
        slot->field_6C += ret * slot->field_70;
        break;
    default:
        ret = -1;
        break;
    }
    if (D_003DFBA8 >= 0) {
        SignalSema(D_003DFBA8);
    }
    D_003E02E0--;
    return ret;
}
