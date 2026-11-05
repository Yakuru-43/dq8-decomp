// range: 0x350430 0x3504E0
#include "common.h"

void *func_003501B0(void *);
void func_00350560(s32, s32, char *);
s32 func_003504E0(s32, s32);
void *func_00130FD0(void *, const void *, u32);

s32 func_00350430(s32 arg0, void *arg1) {
    char buf[128];
    s32 i;
    char *p;

    func_003501B0(buf);
    func_003501B0(buf + 64);
    func_00350560(*(s32 *)(arg0 + 4), *(s32 *)(arg0 + 0x18), buf);
    for (i = 0; i < 2; i++) {
        p = buf + i * 64;
        if (func_003504E0(arg0, (s32)p) == 0) {
            func_00130FD0(arg1, p, 0x40);
            return 1;
        }
    }
    return 0;
}
