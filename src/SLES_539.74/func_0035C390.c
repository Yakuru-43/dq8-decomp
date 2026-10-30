// range: 0x35C390 0x35C3F0
#include "common.h"

extern s8 func_0035DE00(void *arg0);
extern char *func_00181420(void);
extern s16 func_00205390(char *rec, s16 key, s32 a2, s32 a3, s32 a4);

s16 func_0035C390(void *arg0) {
    s8 type;
    char *rec;

    type = func_0035DE00(arg0);
    if (type == 5) {
        rec = func_00181420();
        if (!rec) {
            return 0;
        }
        return func_00205390(rec, *(s16 *)((char *)arg0 + 0xC), 1, 0, -1);
    }
    return *(s16 *)((char *)arg0 + 0x88);
}
