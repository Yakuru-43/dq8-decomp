// range: 0x293610 0x2936D0
#include "common.h"

M2C_UNK func_00292960();                            /* extern */

typedef struct {
    char pad0[0x10];
    s16 unk10;
    char pad12[0xD4];
    s32 unkE8;
} S_58C;

typedef struct {
    char pad0[0x58C];
    S_58C *unk58C;
    s32 unk590[6];
    char pad5A8[0x30];
    s32 unk5D8;
    s32 unk5DC;
} S_arg0;

u8 func_002946D0(S_arg0 *);                          /* extern */

s32 func_00293610(S_arg0 *arg0) {
    s32 temp;
    s32 sum;
    s32 i;

    temp = arg0->unk58C->unkE8;
    arg0->unk58C->unkE8 = 2;
    func_00292960(arg0);
    arg0->unk58C->unkE8 = temp;
    sum = 0;
    for (i = 0; i < 6; i++) {
        sum += arg0->unk590[i];
    }
    if (sum != 1) {
        return 0;
    }
    arg0->unk5D8 = 0;
    arg0->unk5DC = 0;
    if ((func_002946D0(arg0) != 0) && (arg0->unk5D8 > 0)
        && (arg0->unk5DC == arg0->unk5D8)) {
        return 1;
    }
    return 0;
}
