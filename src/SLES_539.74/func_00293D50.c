// range: 0x293D50 0x293DCC
#include "common.h"

M2C_UNK func_00292960();                            /* extern */
M2C_UNK func_00290EA0();                            /* extern */
u64 func_0035E320();                                /* extern */
M2C_UNK func_002915F0();                            /* extern */
M2C_UNK func_002914D0();                            /* extern */

typedef struct {
    char pad0[0x58C];
    void *unk58C;
} S_arg0;

s32 func_00293D50(S_arg0 *arg0) {
    func_00292960(arg0);
    func_00290EA0(arg0);
    if ((func_0035E320(arg0->unk58C) & 0x800004000ULL) != 0) {
        return 0;
    }
    if (func_002915F0(arg0, 0) <= 0) {
        return 0;
    }
    func_002914D0(arg0);
    return 1;
}
