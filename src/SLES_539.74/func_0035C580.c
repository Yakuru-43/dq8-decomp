// range: 0x0035C580 0x0035C5F0
#include "common.h"

extern s8 func_0035DE00(void *arg0);
extern char *func_00181420(void);
extern char *func_00205010(char *rec, s32 key);
extern s32 func_002016D0(void *arg0);

s32 func_0035C580(void *arg0) {
    s8 type;
    char *rec;

    type = func_0035DE00(arg0);
    if (type == 5) {
        rec = func_00181420();
        if (!rec) {
            rec = 0;
        } else {
            rec = func_00205010(rec, *(s16 *)((char *)arg0 + 0xC));
        }
        return (s32)rec;
    }
    return func_002016D0(arg0);
}
