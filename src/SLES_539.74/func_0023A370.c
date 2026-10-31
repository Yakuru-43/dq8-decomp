// range: 0x23A370 0x23A400
#include "common.h"

extern s32 D_003E0B1C;

struct S_0023A370 {
    char pad[0x4FC];
    void *field_4FC;
};

s32 func_0016D5B0(s32, s32);
s32 func_001735C0(void *, s32, s32);

s32 func_0023A370(char *arg0) {
    s32 val;
    s32 a1;
    s32 one;
    void *a0;
    struct S_0023A370 *ret;

    one = 1;
    if (*(s32 *)(arg0 + 0) == one) {
        val = (s32)*(f32 *)(arg0 + 4);
    } else {
        val = *(s32 *)(arg0 + 4);
    }

    ret = (struct S_0023A370 *)func_0016D5B0(D_003E0B1C, val);
    if (ret == 0) {
        return 0;
    }

    a0 = ret->field_4FC;
    if (*(s32 *)(arg0 + 8) == one) {
        a1 = (s32)*(f32 *)(arg0 + 0xC);
    } else {
        a1 = *(s32 *)(arg0 + 0xC);
    }

    func_001735C0(a0, a1, 0);
    return 1;
}
