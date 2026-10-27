// range: 0x353500 0x3535B0
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

char * func_0016D5B0(char *, s32);
M2C_UNK func_00151A20(s8 *, M2C_UNK *);             /* extern */
M2C_UNK func_00151AB0(s8 *, M2C_UNK *);             /* extern */
M2C_UNK func_00353170(char *, M2C_UNK);             /* extern */
extern s8 D_00453CA1 __attribute__((section(".data")));
extern s8 D_00453CB0 __attribute__((section(".data")));
extern M2C_UNK D_00453CC0 __attribute__((section(".data")));
extern M2C_UNK D_00453CD0 __attribute__((section(".data")));

void func_00353500(char *arg0) {
    s8 *temp_s0;

    if (D_00453CA1 == 0) {

    } else {
        temp_s0= (signed char *) ( func_0016D5B0(arg0, 0x20));
        if (D_00453CB0 == 0) {
            if (temp_s0 != NULL) {
                func_00151AB0(temp_s0, &D_00453CC0);
                func_00151A20(temp_s0, &D_00453CD0);
                M2C_FIELD(temp_s0, s32 *, 0x464) = 1;
            }
        } else {
            func_00353170(arg0, 1);
        }
        if (temp_s0 != NULL) {
            M2C_FIELD(temp_s0, s32 *, 0x464) = 1;
        }
    }
}
