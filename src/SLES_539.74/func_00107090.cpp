// range: 0x107090 0x107100
// Splice from `pos` for `count` chars through the big splice worker: the
// worker gets the caller's tail argument plus the guard distance recomputed
// from it.
#include "common.h"

extern "C" {

extern u32 func_001341D8(u32);
extern void func_00107100(void *, u32, u32, u32, u32, s8);

void func_00107090(void *s, u32 pos, u32 count, u32 tail) {
    u8 flag[4];

    func_00107100(s, pos, count, tail, tail + func_001341D8(tail), flag[0]);
}

}
