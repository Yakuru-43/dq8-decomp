// range: 0x335B90 0x335BD0
#include "common.h"

extern char D_0042CDB0[];
extern s32 func_002989C0(void *key);

/* the table entry of obj for the current key */
s32 func_00335B90(s32 *obj) {
    s32 index = func_002989C0(D_0042CDB0);
    return obj[index + 8];
}
