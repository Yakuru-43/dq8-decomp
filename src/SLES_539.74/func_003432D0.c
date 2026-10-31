// range: 0x3432D0 0x343380
#include "common.h"

extern void func_001341D8(void);
extern void func_00134750(char *, s32, s32);
extern void func_001339E0(char *, char *, char *, s32);
extern s32 func_00133F78(s32, char *);
extern M2C_UNK *func_001814D0(void);
extern s16 func_00308490(M2C_UNK *, s32, s16);
extern char D_003D30D8[];

void func_003432D0(s32 arg0) {
    char name[0x20];
    char buf[0x20];
    s32 found;
    s32 i;

    found = 0;
    func_001341D8();
    func_00134750(name, arg0, 12);
    for (i = 1; i < 9; i++) {
        func_001339E0(buf, D_003D30D8, name, i);
        if (func_00133F78(arg0, buf) == 0) {
            found = i;
            break;
        }
    }
    func_00308490(func_001814D0(), 0x57, found);
}
