// range: 0x265450 0x265490
#include "common.h"

extern M2C_UNK D_0041EC20 __attribute__((section(".data")));

void *func_00265450(s32 arg0) {
    if (arg0 < 0 || arg0 >= 4) {
        return 0;
    }
    return (char *)&D_0041EC20 + arg0 * 0xC0 + 0x20;
}
