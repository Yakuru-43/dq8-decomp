// range: 0x1B9E60 0x1B9EB0
#include "common.h"

s32 func_001D7AB0(s32);

s32 func_001B9E60(char *arg0, s32 arg1) {
    s32 val;
    if (arg1 != 1) {
        return 0;
    }
    if (*(s32 *)(arg0 + 0) == 1) {
        f32 f = *(f32 *)(arg0 + 4);
        val = (s32)f;
    } else {
        val = *(s32 *)(arg0 + 4);
    }
    func_001D7AB0(val);
    return 1;
}
