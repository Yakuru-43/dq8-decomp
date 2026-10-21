// range: 0x460A70 0x460AB0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00460AB0();                            /* extern */
extern M2C_UNK D_3DF000 __attribute__((section(".data")));

M2C_UNK **func_00460A70(M2C_UNK **arg0) {
    func_00460AB0();
    *arg0 = &D_3DF000;
    return arg0;
}
