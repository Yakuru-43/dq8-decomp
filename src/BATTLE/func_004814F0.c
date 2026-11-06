// range: 0x4814F0 0x481510
#include "common.h"

extern void *D_003E1B8C __attribute__((section(".sdata")));
extern void func_00478B70(void *);

s32 func_004814F0(void) {
    func_00478B70(D_003E1B8C);
    return 0;
}
