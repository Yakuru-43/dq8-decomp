// range: 0x460A30 0x460A70
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00460AB0();                            /* extern */
extern M2C_UNK D_3DF000 __attribute__((section(".data")));

M2C_UNK **func_00460A30(M2C_UNK **arg0) {
    func_00460AB0();
    *arg0 = &D_3DF000;
    return arg0;
}
