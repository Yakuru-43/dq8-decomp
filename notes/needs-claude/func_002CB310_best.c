// range: 0x002CB310 0x002CB3B0
// best attempt: CLASS structural score=34 (31 words differ, 172 vs 160 bytes)
#include "common.h"

extern char D_00421AD0[] __attribute__((section(".data")));
extern M2C_UNK D_0042EA80 __attribute__((section(".data")));

u32 func_00359CF0(char *, s32);
s32 func_002B09C0(M2C_UNK *, s32);
s32 func_0016D5B0(void *, s32);

f32 func_002CB310(void *obj, s32 key) {
    f32 scale;
    u32 work;

    work = func_00359CF0(D_00421AD0, key);
    if (work == 0) {
        return 8.0f;
    }
    if (*(s32 *)0x41000020 == 0) {
        if (func_0016D5B0(obj, key) == 0) {
            return 10.0f;
        }
        scale = *(f32 *)0x412004CC;
    } else {
        scale = (f32)func_002B09C0(&D_0042EA80, *(s32 *)0x41000000);
    }
    return 2.0f * scale;
}
