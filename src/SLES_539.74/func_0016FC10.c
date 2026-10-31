// range: 0x16FC10 0x16FC50
#include "common.h"

extern void func_00170180(void);
extern void func_00167590(f32, void *);

void func_0016FC10(void *arg0) {
    func_00170180();
    func_00167590(1.0f, arg0);
    *(s32 *)((char *)arg0 + 0x1FC) = 1;
}
