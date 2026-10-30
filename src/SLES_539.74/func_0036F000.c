// range: 0x36F000 0x36F0B0
#include "common.h"

s32 func_00370500(void);                             /* extern */
void func_001340C0(void *, void *);                   /* extern */
void func_0036F130(void *, s32);                      /* extern */
s32 func_001629F0(void *, s32, s32);                  /* extern */

void func_0036F000(void *arg0, s32 arg1, s32 arg2) {
    char buf[0x100];
    s32 level;

    level = func_00370500();
    func_001340C0(buf, arg0);
    func_0036F130(buf, level);
    if (func_001629F0(buf, arg1, arg2) == 0 && level >= 2) {
        func_001340C0(buf, arg0);
        func_0036F130(buf, 1);
        func_001629F0(buf, arg1, arg2);
    }
}
