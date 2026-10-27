// range: 0x357380 0x357490
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

M2C_UNK func_002CA490();  /* extern */
s32 func_0035E590();                          /* extern */
extern char *D_003E1B8C;
extern s32 D_00421A0C __attribute__((section(".data")));
extern char *D_00421A10 __attribute__((section(".data")));
extern char *D_00421A44 __attribute__((section(".data")));

void func_00357380(s32 arg0, M2C_UNK arg1, s32 arg2, s32 arg3) {
    s32 var_s1;
    char *temp_s0;

    var_s1 = 0;
    do {
        temp_s0= (char *) ( arg0 + (var_s1 * 0x590));
        if (arg2 == func_0035E590(temp_s0)) {
            func_002CA490(arg1, M2C_FIELD(temp_s0, s16 *, 0xC), arg3, 0);
        }
        var_s1 += 1;
    } while (var_s1 < 0x20);
    if ((arg2 == 0) && (D_00421A0C != 0)) {
        M2C_FIELD(D_00421A10, s16 *, 0x32)= (s16) (arg3 != 0);
    }
    if ((arg2 == 0) && (D_00421A44 != NULL)) {
        M2C_FIELD(D_00421A44, s16 *, 0x32)= (s16) (arg3 != 0);
        if (D_003E1B8C != NULL) {
            M2C_FIELD(D_003E1B8C, s16 *, 0x246) = 1;
        }
    }
}
