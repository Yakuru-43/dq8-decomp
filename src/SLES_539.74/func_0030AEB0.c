// range: 0x30AEB0 0x30AF00
#include "common.h"

s32 func_0030AF00(s32);                                  /* extern */
char *func_00356910(char *, s32);                        /* extern */

typedef struct {
    char pad0[0x128];
    s32 unk128;
} S_arg1;

void func_0030AEB0(char *arg0, S_arg1 *arg1) {
    s32 v;

    v = arg1->unk128;
    if (v == 0) {
        func_00356910(arg0, 0);
        return;
    }
    func_00356910(arg0, func_0030AF00(v));
}
