// range: 0x4652E0 0x465330
// auto: m2c draft, verified byte-exact
#include "common.h"

int func_0045FDE0(char *, char *, char *);
M2C_UNK func_370C00(s32, M2C_UNK *, M2C_UNK);       /* extern */
extern M2C_UNK D_00473558 __attribute__((section(".data")));

typedef struct {
    char pad0[0x20];
    s32 unk20;
} S_arg0;

s32 func_004652E0(S_arg0 *arg0, s32 arg1, char *arg2) {
    func_0045FDE0(NULL, (char *) M2C_FIELD(M2C_FIELD(arg0, char **, 0x18), s16 *, 0x10), arg2);
    func_370C00(arg0->unk20, &D_00473558, 1);
    return 1;
}
