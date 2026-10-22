// range: 0x302F40 0x302F70
#include "common.h"

s32 func_00302F40(M2C_UNK *arg0) {
    if (arg0 == NULL) {
        return 0;
    }
    if (M2C_FIELD(arg0, s16 *, 0x44) == 2) {
        return 0xB;
    }
    return 0;
}
