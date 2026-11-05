// range: 0x476CF0 0x476DE0
#include "common.h"

typedef struct {
    u8 pad0[4];
    s32 count;
    s32 ids[3];
} S_361260;

extern S_361260 *func_361260(void);
extern s32 func_2B0AC0(M2C_UNK *, s32);
extern s32 func_133F78(s32, char *);
extern M2C_UNK D_42EA80 __attribute__((section(".data")));

s32 func_00476CF0(s32 *arr) {
    S_361260 *pool;
    s32 count;
    s32 name1;
    s32 name2;
    s32 name3;
    s32 i;

    pool = func_361260();
    count = pool->count;
    for (i = 0; i < count; i++) {
        arr[i] = i;
    }
    if (count == 3) {
        name1 = func_2B0AC0(&D_42EA80, pool->ids[0]);
        name2 = func_2B0AC0(&D_42EA80, pool->ids[1]);
        name3 = func_2B0AC0(&D_42EA80, pool->ids[2]);
        if (func_133F78(name1 + 0x20, (char *)(name3 + 0x20)) == 0) {
            if (func_133F78(name1 + 0x20, (char *)(name2 + 0x20)) != 0) {
                arr[0] = 0;
                arr[1] = 2;
                arr[2] = 1;
            }
        }
    }
    return count;
}
