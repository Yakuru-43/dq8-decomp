// range: 0x153AA0 0x153AE0
#include "common.h"

s32 func_00153AA0(char *arg0, s32 arg1) {
    if ((arg1 >= 0) && (arg1 < M2C_FIELD(arg0, s32 *, 0))) {
        return *(s32 *) (M2C_FIELD(arg0, s32 *, 4) + (arg1 * 4));
    }
    return 0;
}
