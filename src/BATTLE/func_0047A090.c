// range: 0x47A090 0x47A0B0
#include "common.h"

extern void *D_003E1B8C __attribute__((section(".sdata")));
extern void func_0046B950(void *);

s32 func_0047A090(void) {
    func_0046B950(D_003E1B8C);
    return 0;
}
