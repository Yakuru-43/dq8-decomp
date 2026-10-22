// range: 0x2FF0F0 0x2FF110
#include "common.h"

extern s32 D_003E10C4;
extern s32 D_003E10C8;

s32 func_002FF0F0(s32 arg0) {
    switch (arg0) {
        case 0:
            return D_003E10C4;
        case 1:
            return D_003E10C8;
        default:
            return 0;
    }
}
