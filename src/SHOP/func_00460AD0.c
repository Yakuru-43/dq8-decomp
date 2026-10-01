// range: 0x460AD0 0x460B10
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00460AB0();                            /* extern */
extern M2C_UNK D_3DEFA0 __attribute__((section(".data")));

M2C_UNK **func_00460AD0(M2C_UNK **arg0) {
    func_00460AB0();
    *arg0 = &D_3DEFA0;
    return arg0;
}
