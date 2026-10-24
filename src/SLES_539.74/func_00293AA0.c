// range: 0x293AA0 0x293B20
#include "common.h"

M2C_UNK func_00292960();                            /* extern */
M2C_UNK func_00294840();                            /* extern */

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
} S_arg0;

s32 func_00293AA0(S_arg0 *arg0) {
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
    if (sum == 1) {
        return func_00294840(arg0);
    }
    return 0;
}
