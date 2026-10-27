// range: 0x1BE950 0x1BE990
#include "common.h"

extern s32 func_00189DB0(s32, s32);
extern s32 D_003E0664;

s32 func_001BE950(char *arg0) {
    s32 a1;
    if (*(s32 *)arg0 == 1) {
        a1 = (s32)*(f32 *)(arg0 + 4);
    } else {
        a1 = *(s32 *)(arg0 + 4);
    }
    func_00189DB0(D_003E0664, a1);
    return 1;
}
