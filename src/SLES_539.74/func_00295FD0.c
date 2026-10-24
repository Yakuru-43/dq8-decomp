// range: 0x295FD0 0x296050
#include "common.h"

M2C_UNK func_00292960();                            /* extern */
M2C_UNK func_00292460();                            /* extern */
M2C_UNK func_00291F40();                            /* extern */
M2C_UNK func_002915F0();                            /* extern */
M2C_UNK func_00296050();                            /* extern */

typedef struct {
    char pad0[0xE8];
    s32 unkE8;
} S_58C;

typedef struct {
    char pad0[0x58C];
    S_58C *unk58C;
} S_arg0;

s32 func_00295FD0(S_arg0 *arg0) {
    s32 result;

    arg0->unk58C->unkE8 = 3;
    func_00292960(arg0);
    func_00292460(arg0, 0x8000);
    func_00291F40(arg0);
    result = func_002915F0(arg0, 0);
    if (result > 0) {
        arg0->unk58C->unkE8 = 1;
        return func_00296050(arg0);
    }
    arg0->unk58C->unkE8 = 1;
    return 0;
}
