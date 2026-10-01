// range: 0x361330 0x361360
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x44];
    s16 unk44;
} S_arg1;

void func_00361330(s32 arg0, S_arg1 *arg1) {
    s16 temp_v1;

    if (arg1 != NULL) {
        temp_v1 = arg1->unk44;
        if (temp_v1 > 0) {
            arg1->unk44 = (s16) (temp_v1 - 1);
        }
    }
}
