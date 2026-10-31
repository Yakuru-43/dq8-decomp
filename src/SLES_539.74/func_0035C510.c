// range: 0x35C510 0x35C580
#include "common.h"

extern s8 func_0035DE00(void *arg0);
extern char *func_00181420(void);
extern char *func_00204E70(char *rec, s32 key);
extern s32 func_002016A0(void *arg0);

s32 func_0035C510(void *arg0) {
    s8 type;
    char *rec;

    type = func_0035DE00(arg0);
    if (type == 5) {
        rec = func_00181420();
        if (!rec) {
            rec = 0;
        } else {
            rec = func_00204E70(rec, *(s16 *)((char *)arg0 + 0xC));
        }
        return (s32)rec;
    }
    return func_002016A0(arg0);
}
