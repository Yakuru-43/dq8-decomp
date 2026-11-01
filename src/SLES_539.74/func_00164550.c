// range: 0x164550 0x1645C0
// flags: -flag divbyzerocheck
#include "common.h"

typedef struct {
    char pad0[0x14];
    s32 unk14;
} S_arg0;

s32 func_00164550(S_arg0 *arg0) {
    s32 d = arg0->unk14 - 0x80;

    if (d < 0x32 && d > -0x32) {
        return 0;
    }
    if (d > 0) {
        return ((d - 0x31) << 7) / 78;
    }
    return ((d + 0x32) << 7) / 78;
}
