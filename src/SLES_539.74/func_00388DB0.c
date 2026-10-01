// range: 0x388DB0 0x388E00
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00388D10(M2C_UNK);                     /* extern */

void func_00388DB0(s64 arg0) {
    s64 temp_v1;

    temp_v1 = (s64) (arg0 << 0x38) >> 0x38;
    switch (temp_v1) {                              /* irregular */
    case 0:
        func_00388D10(0);
        return;
    case 1:
        func_00388D10(1);
        return;
    }
}
