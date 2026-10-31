// range: 0x340550 0x340580
#include "common.h"

s32 func_00340550(char *arg0, s32 arg1) {
    u8 v;

    if (arg1 != 0) {
        v = *(u8 *)(arg0 + 0x16);
        return (v & 8) != 0;
    }
    v = *(u8 *)(arg0 + 0x16);
    return (v & 4) != 0;
}
