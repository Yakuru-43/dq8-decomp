// range: 0x1ECA60 0x1ECAC0
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_001ECAC0(char *);
M2C_UNK func_001F2560(s32);                         /* extern */
extern s32 D_003E0764;
extern char *D_003E0768;
extern s32 D_003E079C;

s32 func_001ECA60(void) {
    s32 temp_v0;
    s32 var_a0;

    if (D_003E079C == 0) {
        var_a0 = D_003E0764 + 0x1624;
        goto block_10;
    }
    if (D_003E0768 == NULL) {
        return 0;
    }
    temp_v0 = func_001ECAC0(D_003E0768);
    if (temp_v0 == 0) {
        return 0;
    }
    var_a0 = temp_v0 + 0x114;
block_10:
    func_001F2560(var_a0);
    return 1;
}
