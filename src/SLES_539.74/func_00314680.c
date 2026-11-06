// range: 0x314680 0x314710
#include "common.h"

struct Entry {
    u8 pad[0x19C];
};

struct Entry *func_0014EA80(s32, void *);
struct Entry *func_00100630(struct Entry *, s32, s32, s32, s32);
s32 func_00314710(s32);

extern struct Entry *D_003E11A0 __attribute__((section(".sdata")));
extern s16 D_003E11A4 __attribute__((section(".sdata")));
extern s16 D_003E11A8 __attribute__((section(".sdata")));
extern s16 D_003E11AC __attribute__((section(".sdata")));

void func_00314680(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg0 == 0) {
        D_003E11A0 = 0;
        D_003E11A4 = 0;
    } else {
        D_003E11A0 = func_00100630(func_0014EA80(arg1 * 0x19C + 0x10, arg0),
                                   (s32)func_00314710, 0, 0x19C, arg1);
        D_003E11A4 = arg1;
        D_003E11A8 = arg2;
        D_003E11AC = arg3;
    }
}
