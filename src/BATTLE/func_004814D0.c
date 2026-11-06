// range: 0x4814D0 0x4814F0
#include "common.h"

extern s32 *D_003E1BD0 __attribute__((section(".sdata")));
extern void func_0046DB30(s32 *);

s32 func_004814D0(void) {
    func_0046DB30(D_003E1BD0);
    return 0;
}
