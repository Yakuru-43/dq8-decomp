// range: 0x23A590 0x23A5E0
#include "common.h"

void func_001735C0(s32, s32, s32);
extern char *D_003E0B1C;

s32 func_0023A590(char *arg0) {
    s32 val;
    s32 base;

    base = *(s32 *)(D_003E0B1C + 0x6410);
    if (*(s32 *)arg0 == 1) {
        val = (s32)*(float *)(arg0 + 4);
    } else {
        val = *(s32 *)(arg0 + 4);
    }
    func_001735C0(base, val, 0);
    return 1;
}
