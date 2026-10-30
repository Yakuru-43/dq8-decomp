// range: 0x35C190 0x35C220
#include "common.h"

extern s32 func_0035DE00(char *);
extern char *func_00181420(void);
extern void func_002044F0(char *, s16, s32 *);
extern void func_0035CF60(char *);

s32 func_0035C190(char *arg0, s32 *arg1) {
    char *temp_v0;

    if ((s8)func_0035DE00(arg0) == 5) {
        temp_v0 = func_00181420();
        if (temp_v0 == NULL) {
            return 0;
        }
        func_002044F0(temp_v0, *(s16 *)(arg0 + 0xC), arg1);
    } else {
        *(s32 *)(arg0 + 0x70) += *arg1;
    }
    func_0035CF60(arg0);
    return *(s32 *)(arg0 + 0x70);
}
