// range: 0x160120 0x160210
#include "common.h"

extern s32 D_003E0320;
extern s8 D_003F80C0 __attribute__((section(".data")));
extern char D_003C23E8[];
extern char D_003C23F8[];
extern char D_003C2408[];
extern char D_003C2418[];

extern void DebugPrintf(char *);
void func_0012B398(s32);
u32 func_0012A970(void *, s8 *);
s32 func_0012B928(void);
void func_0012BB80(s32, s32 *);
void func_00117898(s32);

s32 func_00160120(void) {
    s32 out;
    u8 buf[0x2C];
    u32 r;
    s32 i;

    DebugPrintf(D_003C23E8);
    D_003E0320 = 1;
    func_0012B398(0);
    DebugPrintf(D_003C23F8);
    for (;;) {
        if (D_003F80C0 == 0) {
            break;
        }
        i = 0;
        while (!(0 < (r = func_0012A970(buf, &D_003F80C0)))) {
            if (i % 100 == 0) {
                DebugPrintf(D_003C2408);
            }
            func_00117898(10000);
            i++;
        }
        if (func_0012B928() == 0) {
            break;
        }
        func_00117898(10000);
        D_003E0320 = 2;
    }
    out = 0;
    func_0012BB80(2, &out);
    DebugPrintf(D_003C2418);
    D_003E0320 = 0;
    return 0;
}
