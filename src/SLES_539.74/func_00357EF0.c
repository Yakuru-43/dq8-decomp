// range: 0x357EF0 0x358050
// rodata: 0x3D3A00 0x3D3A3C
#include "common.h"

typedef struct {
    s32 unk0;
    char pad4[0x12];
    s16 unk16;
    char pad18[0xC];
    s32 unk24;
} Unk357EF0;

extern s32 func_002CDDD0(s32, s32);

s32 func_00357EF0(Unk357EF0 *arg0) {
    if (arg0->unk24 == 0) {
        return 0;
    }
    if (arg0->unk16 < 0 || arg0->unk16 >= 15) {
        return 0;
    }
    switch (arg0->unk16) {
    case 2:
        return func_002CDDD0(arg0->unk0, 9);
    case 3:
        return func_002CDDD0(arg0->unk0, 11);
    case 4:
        return func_002CDDD0(arg0->unk0, 8);
    case 5:
        return func_002CDDD0(arg0->unk0, 7);
    case 9:
        return func_002CDDD0(arg0->unk0, 3);
    case 10:
        return func_002CDDD0(arg0->unk0, 6);
    case 6:
        return func_002CDDD0(arg0->unk0, 9);
    case 7:
        return func_002CDDD0(arg0->unk0, 9);
    case 11:
        return func_002CDDD0(arg0->unk0, 15);
    case 12:
        return func_002CDDD0(arg0->unk0, 16);
    case 14:
        return func_002CDDD0(arg0->unk0, 17);
    default:
        return func_002CDDD0(arg0->unk0, 0);
    }
}
