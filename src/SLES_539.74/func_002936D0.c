// range: 0x2936D0 0x2937C0
#include "common.h"

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

M2C_UNK func_00292960(S_arg0 *);                     /* extern */
u8 func_002946D0(S_arg0 *);                          /* extern */

s32 func_002936D0(S_arg0 *arg0) {
    s32 temp;
    s32 idx2;
    s32 idx1;
    s16 kind;
    s32 a;
    s32 b;

    temp = arg0->unk58C->unkE8;
    arg0->unk58C->unkE8 = 2;
    func_00292960(arg0);
    arg0->unk58C->unkE8 = temp;
    kind = arg0->unk58C->unk10;
    if (kind == 2) {
        idx1 = 3;
        idx2 = 4;
    } else if (kind == 4) {
        idx1 = 2;
        idx2 = 3;
    } else {
        idx1 = kind - 1;
        idx2 = kind + 1;
    }
    a = arg0->unk590[idx1];
    b = arg0->unk590[idx2];
    if ((a != 0) && (b != 0)) {
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
