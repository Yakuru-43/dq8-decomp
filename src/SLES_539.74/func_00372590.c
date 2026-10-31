// range: 0x372590 0x3725D0
#include "common.h"

s32 func_0025B760(s32);

s32 func_00372590(char *arg0) {
    if (*(u8 *)(arg0 + 0) == 0) {
        return -2;
    }
    if (*(s16 *)(arg0 + 0x64) >= 0) {
        return -1;
    }
    return func_0025B760(*(s16 *)(arg0 + 2));
}
