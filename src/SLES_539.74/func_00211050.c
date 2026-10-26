// range: 0x211050 0x211130
#include "common.h"

struct KeyEntry {
    /* 0x00 */ s16 val;
    /* 0x02 */ s16 key;
};

struct KeyTable {
    /* 0x00 */ s16 count;
    /* 0x02 */ s16 pad2;
    /* 0x04 */ struct KeyEntry entries[1];
};

s32 func_00134598(void *, void *, s32);
void *func_0018F230(s32, s32);
s32 func_001814D0(void);
s32 func_00308070(s32, s32);
extern struct KeyTable *D_003E0960;
extern u8 D_003C7C30[] __attribute__((section(".data")));

s32 func_00211050(s32 key) {
    struct KeyTable *tbl;
    struct KeyEntry *e;
    s32 n;
    s32 i;
    s32 val;
    s32 result;
    void *obj;

    tbl = D_003E0960;
    if (tbl == 0) {
        return 0;
    }
    n = tbl->count;
    e = tbl->entries;
    for (i = 0; i <= n; i++, e++) {
        if (e->key == key) {
            val = e->val;
            if (val < 0) {
                result = 1;
            } else {
                result = func_00308070(func_001814D0(), (s16)val);
            }
            obj = func_0018F230(key, 0);
            if (obj != 0 && func_00134598(obj, D_003C7C30, 3) == 0) {
                return 1;
            }
            return result;
        }
    }
    return 0;
}
