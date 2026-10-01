// range: 0x469010 0x469060
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_168090();                                  /* extern */

typedef struct {
    s32 unk0;
} S_arg0;

s32 func_00469010(S_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = func_168090();
    if (arg0->unk0 == 3) {
        M2C_FIELD(M2C_FIELD(arg0, char **, 4), s32 *, 4) = temp_v0;
    }
    return 1;
}
