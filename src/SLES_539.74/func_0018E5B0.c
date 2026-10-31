// range: 0x18E5B0 0x18E640
#include "common.h"

extern s32 func_0018EA50(void);
extern void func_001F0A10(f32, f32, f32, f32, f32);

void func_0018E5B0(void)
{
    s32 v0;

    v0 = func_0018EA50();
    if (v0 != 0) {
        func_001F0A10(6.0f, 8.0f, 17.0f, 19.0f, 1.0f);
    } else {
        func_001F0A10(6.0f, 9.0f, 17.0f, 19.0f, 1.0f);
    }
}
