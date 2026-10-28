// range: 0x153920 0x153960
#include "common.h"

s32 func_00153920(char *arg0, s32 arg1) {
    if ((arg1 >= 0) && (arg1 < M2C_FIELD(arg0, s32 *, 0))) {
        return *(s32 *) (M2C_FIELD(arg0, s32 *, 4) + (arg1 * 4));
    }
    return 0;
}
