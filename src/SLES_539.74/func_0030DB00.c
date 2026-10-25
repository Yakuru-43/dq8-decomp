// range: 0x30DB00 0x30DB70
#include "common.h"

extern s32 func_003563E0(void *, f32);
extern void *func_00356920(void *, s32);

void func_0030DB00(char *arg0) {
    if (func_003563E0(arg0 + 0x160, 0.0f) != 0 &&
        func_003563E0(arg0 + 0x168, 0.0f) != 0) {
        func_00356920(arg0 + 0x170, 1);
    } else {
        func_00356920(arg0 + 0x170, 0);
    }
}
