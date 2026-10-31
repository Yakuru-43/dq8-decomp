// range: 0x3504E0 0x350560
#include "common.h"

s32 func_00133F78(s32, s32);

s32 func_003504E0(s32 arg0, s32 arg1) {
    s32 i;
    s32 temp_s3;

    for (i = 0; i < 2; i++) {
        temp_s3 = arg0 + (i * 0xA4);
        if (func_00133F78(arg1, temp_s3 + 0x19B0) == 0) {
            return temp_s3 + 0x19A4;
        }
    }
    return 0;
}
