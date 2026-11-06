// range: 0x0036F6A0 0x0036F6D0
#include "common.h"

extern s16 D_00458814 __attribute__((section(".data")));
extern s32 *func_0036FC40(s32 index);

s32 func_0036F6A0(s32 arg0) {
    s32 *entry = func_0036FC40(D_00458814 + arg0);
    if (entry != 0) {
        return entry[0];
    }
    return 0;
}
