// range: 0x181F20 0x181F60
#include "common.h"

extern void func_00131188(char *, s32, s32);
extern void func_002C27D0(char *);

void func_00181F20(char *arg0) {
    func_00131188(arg0, 0, 0x380);
    func_002C27D0(arg0 + 0x320);
}
