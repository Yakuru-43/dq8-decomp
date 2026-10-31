// range: 0x20B260 0x20B280
#include "common.h"

s32 func_0020B260(char *arg0, s32 arg1) {
    if (arg1 < 0) {
        return 0;
    }
    return *(s32 *)(arg0 + 0x6414) != arg1;
}
