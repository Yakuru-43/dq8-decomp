// range: 0x163F70 0x163F90
#include "common.h"

extern int func_00100480();
extern int func_00163F90();
extern u32 D_003F27C0[74];   /* 0x128-byte queue registered here */

void func_00163F70(void) {
    func_00100480(D_003F27C0, func_00163F90, 0x8, 2);
}
