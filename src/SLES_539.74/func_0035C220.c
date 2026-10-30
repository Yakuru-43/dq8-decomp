// range: 0x35C220 0x35C2D0
#include "common.h"

char *func_00181420(void);
s8 func_0035DE00(char *);
M2C_UNK func_00204530(char *, s16, s16 *, s32);
M2C_UNK func_0035D0E0(char *);

s16 func_0035C220(char *arg0, s16 *arg1, s32 arg2) {
    char *temp_v0;
    s16 temp_v1;

    if (func_0035DE00(arg0) != 5) {
        temp_v1 = *arg1;
        *(s16 *)(arg0 + 0x6C) = *(s16 *)(arg0 + 0x6C) + temp_v1;
        if (arg2 != 0) {
            temp_v1 = *arg1;
            *(s16 *)(arg0 + 0x6E) = *(s16 *)(arg0 + 0x6E) + temp_v1;
        }
        goto block_3;
    }
    temp_v0 = func_00181420();
    if (temp_v0 == 0) {
        return 0;
    }
    func_00204530(temp_v0, *(s16 *)(arg0 + 0xC), arg1, arg2);
block_3:
    func_0035D0E0(arg0);
    return *(s16 *)(arg0 + 0x6C);
}
