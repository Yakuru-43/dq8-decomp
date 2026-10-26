// range: 0x2E1950 0x2E1980
#include "common.h"

extern void func_002DF630(s32, s32, s32 *, s32 *);

s32 func_002E1950(s32 arg0) {
    s32 sp1C;
    s32 sp18;

    func_002DF630(arg0, arg0, &sp1C, &sp18);
    return sp1C;
}
