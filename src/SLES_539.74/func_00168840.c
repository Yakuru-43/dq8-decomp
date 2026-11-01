// range: 0x168840 0x168880
#include "common.h"

s32 func_00168840(s32 n) {
    if (n % 64 != 0) {
        n = (n / 64 + 1) * 64;
    }
    return n;
}
