// range: 0x20BB90 0x20BBC0
#include "common.h"

void func_0020BB90(char *arg0, f32 val) {
    s32 idx;
    char *slot;

    idx = *(s32 *)(arg0 + 0x5874);
    if (idx < 0) {
        slot = 0;
    } else {
        slot = arg0 + idx * 0xC0 + 0x5610;
    }
    *(f32 *)(slot + 0x30) = val;
}
