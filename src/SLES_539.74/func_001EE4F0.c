// range: 0x1EE4F0 0x1EE530
#include "common.h"

M2C_UNK func_001340C0(M2C_UNK *, char *);            /* extern */
char *func_00166760();                                /* extern */
extern M2C_UNK D_00414E30 __attribute__((section(".data")));

s32 func_001EE4F0(void) {
    char *r;

    r = func_00166760();
    if (r == 0) {
        return 0;
    }
    func_001340C0(&D_00414E30, r);
    return 1;
}
