// range: 0x3470E0 0x347150
#include "common.h"

extern s32 func_0018F030(s32);
extern s32 func_0019A250(void);
extern s32 func_00194980(void);
extern void func_001887D0(f32, char *);

void func_003470E0(char *arg0, s32 arg1) {
    *(s32 *)(arg0 + 0x6B18) = func_0018F030(arg1);
    if (func_0019A250() != 0) {
        if (func_00194980() == 0xB) {
            *(s32 *)(arg0 + 0x6B18) = 0;
            func_001887D0(12.0f, arg0);
        }
    }
}
