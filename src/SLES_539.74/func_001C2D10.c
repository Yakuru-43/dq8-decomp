// range: 0x1C2D10 0x1C2D50
#include "common.h"

M2C_UNK func_001746D0(s32);

s32 func_001C2D10(char *arg0) {
    s32 val;
    if (*(s32 *)(arg0 + 0) == 1) {
        f32 f = *(f32 *)(arg0 + 4);
        val = (s32)f;
    } else {
        val = *(s32 *)(arg0 + 4);
    }
    func_001746D0(val);
    return 1;
}
