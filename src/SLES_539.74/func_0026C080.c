// range: 0x26C080 0x26C0D0
#include "common.h"

struct S {
    char pad[0x2C];
    s32 field_2C;
};

s32 func_00166760(char *);
M2C_UNK func_00277FD0(s32, s32);

s32 func_0026C080(char *arg0, s32 arg1, struct S **arg2) {
    struct S *temp_s0;

    temp_s0 = *arg2;
    if (!(temp_s0->field_2C != 0)) {
        return 0;
    }
    func_00277FD0(temp_s0->field_2C, func_00166760(arg0));
    return 1;
}
