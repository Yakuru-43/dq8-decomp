// range: 0x00176A00 0x00176D70
// rodata: 0x003C2BA0 0x003C2BB8
#include "common.h"

typedef struct PartySlot {
    /* 0x00 */ u8 f00;
    /* 0x04 */ s32 f04;
    /* 0x08 */ s32 f08;
    /* 0x0C */ s32 f0C;
    /* 0x10 */ s32 f10;
    /* 0x14 */ u8 f14;
    /* 0x15 */ u8 f15;
    /* 0x16 */ u8 f16;
    /* 0x17 */ u8 f17;
    /* 0x18 */ s32 f18;
    /* 0x1C */ u8 f1C;
    /* 0x1D */ u8 f1D;
    /* 0x1E */ u8 f1E;
    /* 0x1F */ u8 f1F;
    /* 0x20 */ s32 f20;
    /* 0x24 */ s32 f24;
    /* 0x28 */ s32 f28;
} PartySlot;

#define DATA __attribute__((section(".data")))

extern s32 D_00405360 DATA;
extern s8 D_00405364 DATA;
extern PartySlot D_00405368 DATA;
extern s32 D_0040536C DATA;
extern s32 D_00405370 DATA;
extern PartySlot D_0040538C DATA;
extern s32 D_00405390 DATA;
extern PartySlot D_004053B0 DATA;
extern s32 D_004053B4 DATA;
extern PartySlot D_004053D4 DATA;
extern PartySlot D_004053F8 DATA;
extern s32 D_004053FC DATA;
extern PartySlot D_0040541C DATA;
extern PartySlot D_00405440 DATA;
extern s32 D_00405444 DATA;
extern s32 D_00405448 DATA;
extern PartySlot D_00405464 DATA;
extern s32 D_00405468 DATA;
extern s8 D_00405488 DATA;
extern PartySlot D_004054AC DATA;
extern PartySlot D_004054D0 DATA;
extern s32 D_004054D4 DATA;
extern s8 D_004054F4 DATA;
extern s32 D_004054F8 DATA;
extern s32 D_00405504 DATA;
extern PartySlot D_00405518 DATA;
extern s32 D_004055A8 DATA;
extern s32 D_004055AC DATA;
extern s32 D_004055B0 DATA;
extern s32 D_004055B4 DATA;
extern s32 D_004055B8 DATA;
extern s32 D_004055BC DATA;
extern s32 D_004055C0 DATA;
extern s32 D_004055C4 DATA;
extern s32 D_004055C8 DATA;
extern s32 D_004055CC DATA;
extern s32 D_004055D0 DATA;
extern s32 D_004055D4 DATA;
extern s32 D_004055D8 DATA;

void func_00176A00(s32 arg0) {
    PartySlot *table;
    PartySlot *slot;
    s32 *order;
    s32 i;
    s32 kind;

    i = 0;
    D_00405360 = 0x40;
    D_00405364 = 0;
    table = (PartySlot *)&D_00405360;
    do {
        slot = &table[i];
        *(u8 *)&slot->f08 = 0;
        slot->f0C = 0;
        slot->f10 = 0;
        slot->f20 = 0;
        *(s32 *)&slot->f14 = 0;
        slot->f18 = -1;
        slot->f1C = 0;
        slot->f1D = 0;
        slot->f1E = 0;
        slot->f1F = 0;
        slot->f24 = -1;
        slot->f28 = -1;
        order = (s32 *)((char *)&D_00405360 + i * 4);
        order[0x92] = i;
        i++;
    } while (i < 0x10);

    kind = arg0 & 0xFF;
    switch (kind) {
    case 2:
    case 3:
        i = 0;
        D_00405360 = 0x2800;
        do {
            slot = (PartySlot *)((char *)&D_00405360 + i * 0x24);
            i++;
            slot->f0C = 1;
        } while (i < 0x10);
        D_004053B4 = -1;
        D_00405390 = -1;
        D_00405468 = -1;
        D_00405444 = -1;
        D_004053FC = -1;
        D_004054D4 = 0;
        if (kind != 3) {
            D_00405370 = 0x87000;
        }
        D_00405448 = 0x19000;
        D_00405504 = 0;
        return;
    case 4:
    case 5:
        D_00405360 = 0x400;
        D_00405364 = 1;
        D_00405488 = 1;
        D_004054F4 = 1;
        D_004053D4.f04 = 1;
        D_004053D4.f14 = 1;
        D_0040541C.f04 = 1;
        D_0040541C.f14 = 1;
        D_004054AC.f04 = 1;
        D_004054AC.f14 = 1;
        D_004054D0.f04 = 0;
        D_004054D0.f16 = 1;
        D_004054D0.f17 = 1;
        D_00405440.f08 = 0x19000;
        D_00405464.f08 = 0x16000 * 3;
        D_00405368.f00 = 1;
        D_0040538C.f04 = -1;
        D_0040538C.f14 = 1;
        D_004053B0.f04 = -1;
        D_00405464.f0C = 0x16000;
        D_00405518.f04 = -1;
        D_004053F8.f04 = -1;
        D_00405464.f04 = -1;
        D_00405440.f04 = -1;
        D_00405464.f14 = 1;
        D_00405440.f14 = 1;
        D_004053B0.f15 = 1;
        D_004053B0.f08 = 0x18800;
        D_00405518.f08 = 0x18800;
        D_00405518.f15 = 1;
        D_004053F8.f15 = 1;
        D_004053F8.f14 = 1;
        if (kind == 5) {
            D_00405368.f00 = 0;
            D_00405368.f04 = 1;
            D_00405368.f15 = 1;
            D_00405368.f14 = 0;
        }
        D_004055A8 = 6;
        D_004055AC = 9;
        D_004055B0 = 7;
        D_004055B4 = 3;
        D_004055B8 = 2;
        D_004055BC = 0xC;
        D_004055C0 = 5;
        D_004055C4 = 1;
        D_004055C8 = 4;
        D_004055CC = 0xA;
        D_004055D0 = 0;
        D_004055D4 = 8;
        D_004055D8 = 0xB;
        return;
    default:
        i = 0;
        D_00405360 = 0x40;
        do {
            slot = (PartySlot *)((char *)&D_00405360 + i * 0x24);
            i++;
            slot->f0C = -1;
        } while (i < 0x10);
        D_0040536C = 1;
        D_004054F8 = 1;
        D_004054D4 = 0;
        return;
    }
}
