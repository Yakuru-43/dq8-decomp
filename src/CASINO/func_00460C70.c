// range: 0x460C70 0x460CA0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_2F7440();                              /* extern */

typedef struct {
    char pad0[0x2318];
    s32 unk2318;
} S_arg0;

void func_00460C70(S_arg0 *arg0, s32 arg1) {
    arg0->unk2318 = arg1;
    if (arg1 == 0) {
        func_2F7440();
    }
}
