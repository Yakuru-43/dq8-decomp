// range: 0x30AF50 0x30AFA0
#include "common.h"

s32 func_0030AFA0(s32);                                  /* extern */
char *func_00356910(char *, s32);                        /* extern */

typedef struct {
    char pad0[0x120];
    s32 unk120;
} S_arg1;

void func_0030AF50(char *arg0, S_arg1 *arg1) {
    s32 v;

    v = arg1->unk120;
    if (v == 0) {
        func_00356910(arg0, 0);
        return;
    }
    func_00356910(arg0, func_0030AFA0(v));
}
