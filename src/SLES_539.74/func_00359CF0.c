// range: 0x359CF0 0x359D50
#include "common.h"

struct Entry {
    s32 id;
    char pad[0xC];
    s16 x;
    char pad2[0x590 - 0xE];
};

s32 *func_00359CF0(s8 *arg0, s32 arg1) {
    s32 i;
    s32 *temp_v0;

    i = 0;
    while (i < 0x20) {
        temp_v0 = (s32 *)(arg0 + (i * 0x590));
        if (temp_v0[0] >= 0 && arg1 == *(s16 *)((char *)temp_v0 + 0xC)) {
            return temp_v0;
        }
        i++;
    }
    return 0;
}
