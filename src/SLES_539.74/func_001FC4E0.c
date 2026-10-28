// range: 0x1FC4E0 0x1FC510
#include "common.h"

void func_001FC4E0(s32 *arg0, s32 arg1) {
    if ((arg1 >= 0) && (arg1 < *arg0)) {
        arg0[arg1 + 1] = 1;
    }
}
