// range: 0x256A30 0x256AA0
#include "common.h"

extern s32 func_0019A150(s8 *);
extern void func_00253180(s32);
extern void *func_00256B50(s32, s32);
extern s32 func_002581E0(s32, s32);

s32 func_00256A30(s8 *arg0) {
    s32 id;
    void *node;
    s32 field;
    s32 sum;

    id = func_0019A150(arg0);
    node = func_00256B50(id, 0);
    if (node == NULL) {
        return 0;
    }
    field = *(u16 *)((char *)node + 0xA);
    func_00253180(id);
    sum = field + func_002581E0(1, id);
    return sum / 32 + 1;
}
