// range: 0x36D4B0 0x36D530
#include "common.h"

extern char *func_00168150(void);
extern s32 func_0016E2E0(s32, s32);

void func_0036D4B0(char *arg0) {
    char *temp_v0;
    char *temp_a0;

    temp_v0 = func_00168150();
    if (temp_v0 != 0) {
        *(s8 *)(arg0 + 0x564) = (s8)func_0016E2E0((s32)temp_v0, 0x10);
    } else {
        *(s8 *)(arg0 + 0x564) = 1;
    }
    temp_a0 = *(char **)(arg0 + 0x578);
    if (temp_a0 != 0) {
        if (*(u8 *)(temp_a0 + 0x11) != 0) {
            if (*(s32 *)(temp_a0 + 0x24) != 0) {
                *(s8 *)(arg0 + 0x564) = 1;
            }
        }
    }
}
