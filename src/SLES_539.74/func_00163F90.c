// range: 0x163F90 0x163FF0
// auto: m2c draft, with the casts CodeWarrior asks for, verified byte-exact
#include "common.h"

M2C_UNK func_00100780();                         /* extern */
M2C_UNK func_001007A0();                      /* extern */

typedef struct {
    char pad0[0x4];
    s32 unk4;
} S_arg0;

char *func_00163F90(S_arg0 *arg0, s64 arg1) {
    if (arg0 != NULL) {
        func_00100780(arg0->unk4);
        arg0->unk4 = 0;
        if (((s64) (arg1 << 0x30) >> 0x30) > 0) {
            func_001007A0(arg0);
        }
    }
    return (char *) (arg0);
}
