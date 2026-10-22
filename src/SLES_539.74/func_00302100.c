// range: 0x302100 0x302140
#include "common.h"

s32 func_00302100(s32 *arg0, s32 arg1) {
    s32 table;

    table = arg0[3];
    if (table == 0) {
        return 0;
    }
    if (arg1 >= 0 && arg1 < ((s32 *)arg0[0])[14]) {
        return table + arg1 * 16;
    }
    return 0;
}
