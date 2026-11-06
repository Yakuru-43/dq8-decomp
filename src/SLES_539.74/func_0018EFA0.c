// range: 0x18EFA0 0x18F030
#include "common.h"

typedef struct Entry {
    u8 pad[0x19];
    s8 mode : 1;
} Entry;

extern Entry *func_0018F3F0(s32);
extern s32 func_0018F310(s32);

s32 func_0018EFA0(s32 arg0) {
    Entry *entry;
    s32 ret;
    s32 state;

    entry = func_0018F3F0(arg0);
    if (entry == 0) {
        return 0;
    }
    ret = entry->mode;
    state = func_0018F310(arg0);
    switch (state) {
    case 1:
    case 2:
    case 3:
    case 6:
        ret = 1;
        break;
    case 7:
        ret = 0;
        break;
    default:
        break;
    }
    return ret;
}
