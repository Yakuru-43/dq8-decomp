// range: 0x293A30 0x293AA0
#include "common.h"

M2C_UNK func_00292960();                            /* extern */
M2C_UNK func_002946D0();                            /* extern */

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

s32 func_00293A30(S_arg0 *arg0) {
    s32 temp;

    temp = arg0->unk58C->unkE8;
    arg0->unk58C->unkE8 = 2;
    func_00292960(arg0);
    arg0->unk58C->unkE8 = temp;
    if (arg0->unk590[arg0->unk58C->unk10] == 8) {
        return func_002946D0(arg0);
    }
    return 0;
}
