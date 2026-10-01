// range: 0x361300 0x361330
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x4C];
    s16 unk4C;
} S_arg1;

void func_00361300(s32 arg0, S_arg1 *arg1) {
    s16 temp_v1;

    if (arg1 != NULL) {
        temp_v1 = arg1->unk4C;
        if (temp_v1 > 0) {
            arg1->unk4C = (s16) (temp_v1 - 1);
        }
    }
}
