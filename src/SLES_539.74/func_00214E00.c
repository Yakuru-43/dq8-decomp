// range: 0x214E00 0x214E40
#include "common.h"

void func_00168150(void);
u32 func_002205C0(s32, s32, s32);
extern void *D_003E0868;

s32 func_00214E00(void) {
    func_00168150();
    return func_002205C0((s32)((char *)D_003E0868 + 0x11A28), 0, 0xFFFF) > 0;
}
