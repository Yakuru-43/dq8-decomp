// range: 0x2957C0 0x295830
#include "common.h"

M2C_UNK func_00292960();                            /* extern */
M2C_UNK func_00291820();                            /* extern */
s32 func_002915F0();                                /* extern */
s32 func_00296510();                                /* extern */

typedef struct {
    char pad0[0x58C];
} S_arg0;

s32 func_002957C0(S_arg0 *arg0) {
    s32 first;
    s32 second;

    func_00292960(arg0);
    func_00291820(arg0);
    first = func_002915F0(arg0, 0);
    second = func_002915F0(arg0, 2);
    if (first * 3 >= second * 2) {
        return func_00296510(arg0);
    }
    return 0;
}
