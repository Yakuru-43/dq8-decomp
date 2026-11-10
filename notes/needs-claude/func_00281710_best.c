// range: 0x281710 0x281760
// BEST attempt, try_match score=6 (80 vs 80 bytes) — NOT matched, do not stage.
#include "common.h"

extern "C" {
M2C_UNK func_00270DC0(void *, u32); /* extern */

struct Big {
    u8 pad0[0x53C];
    s32 *unk53C;
};

struct Owner {
    u8 pad0[0x4];
    Big *unk4;
};

struct Slot {
    u8 pad0[0x30];
    u32 unk30;
};

s32 func_00281710(Owner *arg0, Slot *arg1) {
    if ((0 < arg1->unk30) != false) {
        s32 *p = arg0->unk4->unk53C;
        if (p != 0) {
            func_00270DC0(p, arg1->unk30);
            arg1->unk30 = 0;
        }
    }
    return 1;
}
}
