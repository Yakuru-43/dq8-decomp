// range: 0x294EC0 0x294F40
#include "common.h"

M2C_UNK func_00292960();                            /* extern */
M2C_UNK func_00291820();                            /* extern */
M2C_UNK func_002915F0();                            /* extern */
M2C_UNK func_002914D0();                            /* extern */

s32 func_00294EC0(void *arg0) {
    s32 first;
    s32 second;

    func_00292960(arg0);
    func_00291820(arg0);
    first = func_002915F0(arg0, 0);
    second = func_002915F0(arg0, 2);
    if (first * 3 >= second * 2) {
        func_002914D0(arg0);
        return 1;
    }
    return 0;
}
