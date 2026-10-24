// range: 0x296590 0x296640
#include "common.h"

typedef struct {
    char pad0[0x590];
    s32 unk590[6];
    s32 unk5A8[6];
    s32 unk5C0[6];
} S_arg0;

M2C_UNK func_00292960(S_arg0 *);                    /* extern */
M2C_UNK func_00292460(S_arg0 *, s32);               /* extern */
M2C_UNK func_00292610(S_arg0 *, s32);               /* extern */
M2C_UNK func_00291520(S_arg0 *, s32);               /* extern */
M2C_UNK func_00291400(S_arg0 *);                    /* extern */

s32 func_00296590(S_arg0 *arg0) {
    s32 i;
    s32 result;

    func_00292960(arg0);
    func_00292460(arg0, 0x800);
    for (i = 0; i < 6; i++) {
        if (3 * arg0->unk590[i] <= 2 * arg0->unk5C0[i]) {
            func_00292610(arg0, i);
        }
    }
    result = func_00291520(arg0, 0);
    if (result > 0) {
        func_00291400(arg0);
        return 1;
    }
    return 0;
}
