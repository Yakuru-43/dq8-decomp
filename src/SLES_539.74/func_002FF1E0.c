// range: 0x2FF1E0 0x2FF210
#include "common.h"

extern s32 D_003E10CC;
extern s32 D_003E10D0;
extern s32 D_003E10D4;

s32 func_002FF1E0(s32 arg0) {
    if (arg0 == 2) {
        return D_003E10D4;
    }
    if (arg0 == 1) {
        return D_003E10D0;
    }
    return D_003E10CC;
}
