// range: 0x38A780 0x38A7B0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_0037B8D0(M2C_UNK *);                   /* extern */
extern M2C_UNK D_004593D0 __attribute__((section(".data")));

void func_0038A780(void) {
    if (&D_004593D0 != NULL) {
        func_0037B8D0(&D_004593D0);
    }
}
