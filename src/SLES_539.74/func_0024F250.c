// range: 0x24F250 0x24F2E0
#include "common.h"

void func_0024F250(u16 *arg0, u8 *arg1) {
    u32 count = *(u32 *)arg1;
    s32 found = -1;
    u32 i;
    u16 counter;
    u8 *entry;

    for (i = 0; i < count; i++) {
        if (*(u16 *)(arg1 + 0x86 + i * 0x84) == 0) {
            found = i;
            break;
        }
    }
    if (found < 0) {
        arg0[0] = 0;
        arg0[1] = 0;
        return;
    }
    counter = *(u16 *)(arg1 + 0x424);
    *(u16 *)(arg1 + 0x424) = counter + 1;
    if (*(u16 *)(arg1 + 0x424) == 0) {
        *(u16 *)(arg1 + 0x424) = 1;
    }
    entry = arg1 + 0x86;
    *(u16 *)(entry + found * 0x84) = counter;
    arg0[0] = found;
    arg0[1] = counter;
}
