// range: 0x294E30 0x294EC0
#include "common.h"

M2C_UNK func_00292960();                            /* extern */

typedef struct {
    char pad0[0x358];
    s32 unk358;
} S_58C;

typedef struct {
    char pad0[0x58C];
    S_58C *unk58C;
} S_arg0;

M2C_UNK func_00291400(S_arg0 *);                    /* extern */
s32 func_00291520(S_arg0 *, M2C_UNK);               /* extern */
M2C_UNK func_00292460(S_arg0 *, M2C_UNK64);         /* extern */

s32 func_00294E30(S_arg0 *arg0) {
    if ((arg0->unk58C->unk358 & 2) == 0) {
        return 0;
    }
    func_00292960();
    func_00292460(arg0, 0x4000);
    func_00292460(arg0, (s64)8 << 32);
    if (func_00291520(arg0, 0) > 0) {
        func_00291400(arg0);
        return 1;
    }
    return 0;
}
