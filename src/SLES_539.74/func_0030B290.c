// range: 0x30B290 0x30B2E0
#include "common.h"

s32 func_0030AFA0(s32);                                  /* extern */
char *func_00356910(char *, s32);                        /* extern */

typedef struct {
    char pad0[0x118];
    s32 unk118;
} S_arg1;

void func_0030B290(char *arg0, S_arg1 *arg1) {
    s32 v;

    v = arg1->unk118;
    if (v == 0) {
        func_00356910(arg0, 0);
        return;
    }
    func_00356910(arg0, func_0030AFA0(v));
}
