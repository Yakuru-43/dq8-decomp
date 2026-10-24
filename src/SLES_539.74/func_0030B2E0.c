// range: 0x30B2E0 0x30B320
#include "common.h"

char *func_00356910(char *, s32);                        /* extern */

typedef struct {
    char pad0[0x12C];
    s32 unk12C;
} S_arg1;

void func_0030B2E0(char *arg0, S_arg1 *arg1) {
    s32 v;

    v = arg1->unk12C;
    if (v != 0) {
        func_00356910(arg0, 1);
    } else {
        func_00356910(arg0, 0);
    }
}
