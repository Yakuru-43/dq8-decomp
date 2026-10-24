// range: 0x294CF0 0x294D70
#include "common.h"

M2C_UNK func_00292960();                            /* extern */
M2C_UNK func_00292460();                            /* extern */
M2C_UNK func_002915F0();                            /* extern */
M2C_UNK func_002914D0();                            /* extern */

s32 func_00294CF0(void *arg0) {
    s32 first;
    s32 second;

    func_00292960(arg0);
    func_00292460(arg0, 0x1C0);
    first = func_002915F0(arg0, 0);
    second = func_002915F0(arg0, 2);
    if (first * 2 >= second) {
        func_002914D0(arg0);
        return 1;
    }
    return 0;
}
