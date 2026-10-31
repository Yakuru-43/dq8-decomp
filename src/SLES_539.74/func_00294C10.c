// range: 0x294C10 0x294CF0
#include "common.h"

M2C_UNK func_002914D0(s32);                          /* extern */
s32 func_002915F0(s32, M2C_UNK);                     /* extern */
M2C_UNK func_00292020(s32);                          /* extern */
M2C_UNK func_00292130(s32);                          /* extern */
M2C_UNK func_00292370(s32, M2C_UNK);                  /* extern */
M2C_UNK func_00292960(s32);                          /* extern */
M2C_UNK func_00292A90(s32);                          /* extern */

/* three attempts: each prepares the object, then starts it when it is free */
s32 func_00294C10(s32 arg0) {
    func_00292960(arg0);
    func_00292370(arg0, 0xC131E04);
    if (func_002915F0(arg0, 0) > 0) {
        func_002914D0(arg0);
        return 1;
    }
    func_00292A90(arg0);
    func_00292960(arg0);
    func_00292130(arg0);
    if (func_002915F0(arg0, 0) > 0) {
        func_002914D0(arg0);
        return 1;
    }
    func_00292A90(arg0);
    func_00292960(arg0);
    func_00292020(arg0);
    if (func_002915F0(arg0, 0) > 0) {
        func_002914D0(arg0);
        return 1;
    }
    return 0;
}
