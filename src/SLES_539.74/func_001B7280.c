// range: 0x1B7280 0x1B72C0
#include "common.h"

M2C_UNK func_001D7030(s32, s32);
extern s32 D_003E0664;

s32 func_001B7280(char *arg0) {
    s32 a1;
    if (*(s32 *)arg0 == 1) {
        a1 = (s32)*(f32 *)(arg0 + 4);
    } else {
        a1 = *(s32 *)(arg0 + 4);
    }
    func_001D7030(D_003E0664, a1);
    return 1;
}
