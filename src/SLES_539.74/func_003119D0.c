// range: 0x3119D0 0x311A00
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_0022B630(s32);                             /* extern */

typedef struct {
    char pad0[0x58];
    s32 unk58;
} S_arg0;

s32 func_003119D0(S_arg0 *arg0) {
    arg0->unk58 = func_0022B630(arg0->unk58);
    return 1;
}
