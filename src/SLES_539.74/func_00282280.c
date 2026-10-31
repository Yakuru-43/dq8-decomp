// range: 0x282280 0x2822D0
#include "common.h"

s32 func_001340C0(s32, void *);
u32 func_001341D8(void *);

void func_00282280(s32 arg0, void *arg1) {
    if (arg1 != NULL) {
        if (func_001341D8(arg1) < 8U) {
            func_001340C0(arg0 + 0x30, arg1);
        }
    }
}
