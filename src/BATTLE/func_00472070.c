// range: 0x472070 0x472130
#include "common.h"

extern s32 func_1341D8(char *);
extern s32 func_133F78(s32, char *);
extern void func_1340C0(char *, char *);
extern s32 func_370500(void);
extern s32 func_1339E0(s32, char *, ...);
extern void func_133CB8(s32, char *);

extern char D_00484710[];
extern char D_00484718[];

s32 func_00472070(char *arg0, char *arg1) {
    char buf[0x10];
    s32 len;
    s32 n;

    if (arg0 == 0 || arg1 == 0) {
        return 0;
    }
    len = func_1341D8(arg0);
    if (len < 4) {
        return 0;
    }
    if (func_133F78((s32)arg0 + (len - 4), D_00484710) != 0) {
        return 0;
    }
    func_1340C0(arg1, arg0);
    arg1[len - 3] = 0;
    n = func_370500();
    func_1339E0((s32)buf, D_00484718, n);
    func_133CB8((s32)arg1, buf);
    return 1;
}
