// range: 0x18E220 0x18E250
#include "common.h"

extern s32 func_001340C0(char *);

void func_0018E220(char *arg0, char *arg1) {
    if (arg1 != 0) {
        func_001340C0(arg0 + 0x1E4);
        return;
    }
    *(s8 *)(arg0 + 0x1E4) = 0;
}
