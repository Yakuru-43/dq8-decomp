// range: 0x1B5CF0 0x1B5D50
#include "common.h"

s32 func_00181420(void);
s32 func_002060F0(s32, s32);

s32 func_001B5CF0(char *arg0) {
    s32 temp_v0;
    s32 a1;

    temp_v0 = func_00181420();
    if (temp_v0 == 0) {
        return 0;
    }

    if (*(s32 *)(arg0 + 0) == 1) {
        a1 = (s32)*(f32 *)(arg0 + 4);
    } else {
        a1 = *(s32 *)(arg0 + 4);
    }

    func_002060F0(temp_v0, a1);
    return 1;
}
