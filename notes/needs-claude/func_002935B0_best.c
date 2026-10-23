// range: 0x2935B0 0x293610
#include "common.h"

s32 func_00293560();                             /* extern */
s32 func_00297090();                             /* extern */
s32 func_002970A0();                             /* extern */

typedef struct {
    char pad0[0x58C];
    s32 unk58C;
} S_arg0;

s32 func_002935B0(S_arg0 *arg0) {
    if (func_00297090(arg0) * 3 > func_002970A0(arg0->unk58C)) {
        return 0;
    }
    return func_00293560(arg0);
}
