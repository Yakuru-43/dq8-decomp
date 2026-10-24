// range: 0x30AFB0 0x30B000
#include "common.h"

s32 func_0030AFA0(s32);                                  /* extern */
char *func_00356910(char *, s32);                        /* extern */

typedef struct {
    char pad0[0x11C];
    s32 unk11C;
} S_arg1;

void func_0030AFB0(char *arg0, S_arg1 *arg1) {
    s32 v;

    v = arg1->unk11C;
    if (v == 0) {
        func_00356910(arg0, 0);
        return;
    }
    func_00356910(arg0, func_0030AFA0(v));
}
