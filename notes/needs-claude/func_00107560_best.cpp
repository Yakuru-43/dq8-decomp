// CLASS structural score=14 (14 words differ, 136 vs 136 bytes)  [best of 2 attempts]
// range: 0x107560 0x1075F0
// Destroys the object at `obj`: swaps in the two vtable addresses around the
// scalar delete of the member at +4, then frees the backing array when the
// 16-bit count is positive. Returns `obj`.
// Open (vs ROM): first guard must branch to the SHARED return stub
// (beqz $s1 -> L5BC at +0x44), not skip only the first block; the member
// test is bnez-forward to an out-of-line delete block that rejoins the
// second-vtable-store label with `b -0x10`, delete's a1=-1 in the jal delay
// slot; the (s16)cnt test is blez->return stub, not bgtzl->call. ROM keeps
// ONE return stub for all paths; mine still emits two.
#include "common.h"

extern "C" {

extern char D_003DD670[];
extern char D_003DD880[];
extern void func_00102B90(void *, s32);
extern void func_001007A0(void *);

void *func_00107560(void *obj, s32 count) {
    void *self = obj;
    s32 cnt = count;
    void *member;

    if (self != 0) {
        *(void **)self = &D_003DD880[0];
        member = (char *)self + 4;
        if (member != 0) {
            func_00102B90(member, -1);
        }
    }
    if (self != 0) {
        *(void **)self = &D_003DD670[0];
    }
    if ((s16)cnt > 0) {
        func_001007A0(self);
    }
    return self;
}

}
