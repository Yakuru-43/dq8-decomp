// range: 0x1431B0 0x1431E0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_001431E0(f32, f32, f32, f32);          /* extern */

void func_001431B0(char *arg0, f32 fparg0) {
    char *temp_v1;

    temp_v1 = M2C_FIELD(arg0, char **, 0xF20);
    if (temp_v1 != NULL) {
        func_001431E0(M2C_FIELD(temp_v1, f32 *, 0x14), M2C_FIELD(temp_v1, f32 *, 0x20), M2C_FIELD(temp_v1, f32 *, 0x24), fparg0);
    }
}
