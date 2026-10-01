// range: 0x2DE4A0 0x2DE510
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK DebugPrintf(M2C_UNK *, s32, s32);           /* extern */
void *func_002D7F40(void *);                        /* extern */
extern M2C_UNK D_003CD948 __attribute__((section(".data")));
extern s32 D_003E1090;

s32 func_002DE4A0(void *arg0) {
    void *temp_v0;

    if (!(M2C_FIELD(arg0, u16 *, 0x28) & 1)) {
        if (D_003E1090 != 0) {
            DebugPrintf(&D_003CD948, M2C_FIELD(arg0, s32 *, 0), M2C_FIELD(arg0, s32 *, 4));
        }
        temp_v0 = func_002D7F40(arg0);
        if (temp_v0 == NULL) {
            return 1;
        }
        return func_002DE4A0(temp_v0);
    }
    return 0;
}
