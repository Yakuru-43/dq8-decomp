// range: 0x1EE530 0x1EE570
#include "common.h"

M2C_UNK func_001340C0(M2C_UNK *, char *);            /* extern */
char *func_00166760();                                /* extern */
extern M2C_UNK D_00414EB0 __attribute__((section(".data")));

s32 func_001EE530(void) {
    char *r;

    r = func_00166760();
    if (r == 0) {
        return 0;
    }
    func_001340C0(&D_00414EB0, r);
    return 1;
}
