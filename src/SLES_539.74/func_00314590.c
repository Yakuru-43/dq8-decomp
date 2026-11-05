// range: 0x314590 0x314620
// auto: hand, verified byte-exact
#include "common.h"

struct Entry {
    u8 pad[0x19C];
};

extern void func_0014E750(char *, char *, s32);
extern char *func_0014E130(void *, s32);
extern void func_00314360(struct Entry *);

extern struct Entry *D_003E11A0 __attribute__((section(".sdata")));
extern s16 D_003E11A4 __attribute__((section(".sdata")));
extern char *D_003E11B0 __attribute__((section(".sdata")));
extern s32 D_003E11B4 __attribute__((section(".sdata")));
extern char D_00452DE0[] __attribute__((section(".data")));

void func_00314590(void *arg0, s32 arg1) {
    struct Entry *e;
    s32 i;

    D_003E11B0 = 0;
    D_003E11B4 = 0;
    if (arg0 != 0) {
        D_003E11B0 = func_0014E130(arg0, arg1);
        D_003E11B4 = arg1;
    }
    func_0014E750(D_00452DE0, D_003E11B0, D_003E11B4);
    for (i = 0, e = D_003E11A0; i < D_003E11A4; i++, e++) {
        func_00314360(e);
    }
}
