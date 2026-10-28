// range: 0x1BA5E0 0x1BA630
#include "common.h"

void func_0016FBA0(s32, f32);
s32 func_001A2160(void);

s32 func_001BA5E0(char *arg0) {
    f32 f20;
    s32 v0;

    v0 = *(s32 *)arg0;
    if (v0 == 0) {
        f20 = (f32)*(s32 *)(arg0 + 4);
    } else {
        f20 = *(f32 *)(arg0 + 4);
    }

    v0 = func_001A2160();
    func_0016FBA0(v0, f20);

    return 1;
}
