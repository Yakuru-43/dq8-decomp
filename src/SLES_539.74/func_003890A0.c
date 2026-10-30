// range: 0x3890A0 0x389100
#include "common.h"

char *func_00201CD0(void);
char *func_00370FD0(char *);
void func_003705E0(char *);
void func_00388E00(void);

s32 func_003890A0(s32 arg0, s32 arg1) {
    char *s0;
    char *v0;

    s0 = func_00201CD0();
    v0 = func_00370FD0(s0);
    if (arg1 != 0) {
        *(s16 *)(v0 + 0x14) = 0;
        return 0;
    } else {
        func_003705E0(s0);
        func_00388E00();
        return 0;
    }
}
