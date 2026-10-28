// range: 0x208220 0x208270
#include "common.h"

s32 func_003724B0(char *);

s32 func_00208220(char *arg0) {
    s32 idx;
    char *entry;

    idx = *(s32 *)(arg0 + 0x5874);
    if (idx < 0) {
        entry = 0;
    } else {
        entry = arg0 + idx * 0x6C + 0x5790;
    }
    if (entry == 0) {
        return 0;
    }
    return func_003724B0(entry);
}
