// range: 0x1A4FB0 0x1A5030
#include "common.h"

extern void func_001AC880(f32, s32, s32, char *, s32);

s32 func_001A4FB0(char *arg0, char *arg1) {
    s32 *temp_v0;
    s32 temp_v1;

    if (*(s32 *)(arg0 + 0x28) != 0) {
        return 0;
    }

    func_001AC880(*(f32 *)(arg0 + 0x24), *(s32 *)(arg1 + 0x40),
                  *(s32 *)(arg1 + 0x68), arg0 + 0x2C,
                  *(s32 *)(arg0 + 0x20));

    temp_v0 = *(s32 **)(arg0 + 0x4C);
    if (temp_v0 != NULL) {
        temp_v1 = *temp_v0;
        if (temp_v1 == 0x19 || temp_v1 == 0x1D) {
            return 0;
        }
    }

    *(s32 *)(arg0 + 0x28) = 1;
    return 1;
}
