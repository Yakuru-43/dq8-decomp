// range: 0x307220 0x3072A0
#include "common.h"

struct MapEntry {
    /* 0x0 */ s16 from;
    /* 0x2 */ s16 to;
};

extern struct MapEntry D_003AD0A0[];

s32 func_00307220(s32 arg0, s32 arg1) {
    s32 ret;
    s32 i;

    ret = arg0;
    for (i = 0; D_003AD0A0[i].from >= 0; i++) {
        if (arg1 == 0) {
            if (arg0 == D_003AD0A0[i].from) {
                ret = D_003AD0A0[i].to;
                break;
            }
        }
        if (arg1 == 1) {
            if (arg0 == D_003AD0A0[i].to) {
                ret = D_003AD0A0[i].from;
                break;
            }
        }
    }
    return ret;
}
