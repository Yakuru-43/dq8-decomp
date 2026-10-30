// range: 0x35C450 0x35C4B0
#include "common.h"

extern s8 func_0035DE00(void *arg0);
extern char *func_00181420(void);
extern s32 func_00205390(char *, s16, s32, s32, s32);

s32 func_0035C450(void *arg0) {
    s8 type;
    char *rec;

    type = func_0035DE00(arg0);
    if (type == 5) {
        rec = func_00181420();
        if (!rec) {
            return 0;
        }
        return func_00205390(rec, *(s16 *)((char *)arg0 + 0xC), 2, 0, -1);
    }
    return *(s32 *)((char *)arg0 + 0x7C);
}
