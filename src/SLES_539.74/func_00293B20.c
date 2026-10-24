// range: 0x293B20 0x293BB0
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
} S_arg0;

M2C_UNK func_00292A90(S_arg0 *);                    /* extern */
M2C_UNK func_002926D0(S_arg0 *);                    /* extern */
M2C_UNK func_002914D0(S_arg0 *);                    /* extern */

s32 func_00293B20(S_arg0 *arg0) {
    s32 temp;

    temp = arg0->unk58C->unkE8;
    arg0->unk58C->unkE8 = 2;
    func_00292960(arg0);
    arg0->unk58C->unkE8 = temp;
    if (arg0->unk590[arg0->unk58C->unk10] != 8) {
        return 0;
    }
    func_00292A90(arg0);
    func_002926D0(arg0);
    func_002914D0(arg0);
    return 1;
}
