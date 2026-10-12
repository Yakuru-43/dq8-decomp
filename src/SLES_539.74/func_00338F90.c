// range: 0x338F90 0x338FD0
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

s32 func_001667C0();                                /* extern */
extern s32 D_003E124C;
extern s32 *D_003E1250;
extern s32 D_003E1254;

s32 func_00338F90(void) {
    D_003E1250= (int *) ( D_003E124C + (D_003E1254 << 5));
    *D_003E1250 = func_001667C0();
    return 1;
}
