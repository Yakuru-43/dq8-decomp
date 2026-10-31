// range: 0x35C100 0x35C190
#include "common.h"

extern s8 func_0035DE00(char *);
extern char *func_00181420(void);
extern void func_00204470(char *, s16, s32 *);
extern void func_0035CC80(char *);

s32 func_0035C100(char *arg0, s32 *arg1) {
    char *temp_v0;

    if (func_0035DE00(arg0) != 5) {
        *(s32 *)(arg0 + 0x7C) += *arg1;
    } else {
        temp_v0 = func_00181420();
        if (temp_v0 == NULL) {
            return 0;
        }
        func_00204470(temp_v0, *(s16 *)(arg0 + 0xC), arg1);
    }
    func_0035CC80(arg0);
    return *(s32 *)(arg0 + 0x7C);
}
