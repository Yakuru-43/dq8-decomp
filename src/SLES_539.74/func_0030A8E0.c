// range: 0x30A8E0 0x30A940
#include "common.h"

s32 func_0030A890(s32);                                /* extern */
char *func_00356910(char *, s32);                       /* extern */
extern s32 D_003E1168;

typedef struct {
    char pad0[0x110];
    s32 unk110;
} S_arg1;

void func_0030A8E0(char *arg0, S_arg1 *arg1) {
    if (D_003E1168 == func_0030A890(arg1->unk110)) {
        func_00356910(arg0, 1);
    } else {
        func_00356910(arg0, 0);
    }
}
