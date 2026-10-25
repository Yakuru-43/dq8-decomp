// range: 0x36D030 0x36D0D0
// rodata: 0x3D4EE0 0x3D4EFC
#include "common.h"

typedef struct {
    char pad0[0x8];
    s16 unk8;
    char padA[0x6];
    u8 unk10;
} Unk36D030;

/* every case keeps its own store: probably one named constant per kind,
   all equal to 20 */
void func_0036D030(s32 arg0, Unk36D030 *arg1, u8 arg2, s32 arg3) {
    arg1->unk10 = arg2;
    if (arg3 != 0) {
        switch (arg2) {
        case 0:
            arg1->unk8 = 20;
            break;
        case 1:
            arg1->unk8 = 20;
            break;
        case 2:
            arg1->unk8 = 20;
            break;
        case 3:
            arg1->unk8 = 20;
            break;
        case 4:
            arg1->unk8 = 20;
            break;
        case 5:
            arg1->unk8 = 20;
            break;
        case 6:
            arg1->unk8 = 20;
            break;
        default:
            arg1->unk8 = 0;
            break;
        }
    }
}
