// range: 0x1EE090 0x1EE0F0
#include "common.h"

extern s32 func_001EE0F0(s32);
extern void func_001EC1B0(s32);

s32 func_001EE090(s32 arg0) {
    char *cursor;

    cursor = (char *)arg0 + 0xA8;
    do {
        func_001EE0F0((s32)cursor);
        cursor += 8;
    } while (cursor < (char *)arg0 + 0xC8);
    func_001EC1B0(arg0);
    return arg0;
}
