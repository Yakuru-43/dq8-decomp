// range: 0x189E60 0x189E90
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_001DF2A0(char *);                      /* extern */

void func_00189E60(char *arg0) {

    if (!(M2C_FIELD(arg0, s8 *, 0x69E0) != 0)) {
        return;
    }

    func_001DF2A0(arg0 + 0x6968);
}
