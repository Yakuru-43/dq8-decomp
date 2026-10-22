// range: 0x20D750 0x20D7E0
#include "common.h"

extern char *D_003E08D0;
s32 func_00210080(char *);                              /* extern */
s32 func_0020D820(char *);                              /* extern */
s32 func_0020D810(char *);                              /* extern */
char *func_0020D7F0(char *);                            /* extern */
char *func_0020D7E0(char *);                            /* extern */
M2C_UNK func_00130FD0(char *, char *, M2C_UNK);         /* extern */

s32 func_0020D750(void *arg0) {
    char *obj;
    s32 result;

    obj = arg0;
    if (D_003E08D0 == 0) {
        return 1;
    }
    result = func_00210080(D_003E08D0);
    if (obj != 0) {
        M2C_FIELD(obj, s32 *, 0x0) = func_0020D820(D_003E08D0);
        M2C_FIELD(obj, s32 *, 0x4) = func_0020D810(D_003E08D0);
        func_00130FD0(obj + 8, func_0020D7F0(D_003E08D0), 0x1C);
        func_00130FD0(obj + 0x24, func_0020D7E0(D_003E08D0), 0x14);
    }
    return result;
}
