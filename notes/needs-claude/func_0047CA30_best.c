// range: 0x47CA30 0x47CAE0
#include "common.h"

typedef struct {
    char pad0[0x18];
    s32 unk18;
    char pad1C[0xA0 - 0x1C];
} S_member;

typedef struct {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x4C - 0x8];
    s16 count;
    char pad4E[2];
    S_member *members;
} S_pool;

extern M2C_UNK D_421AD0 __attribute__((section(".data")));
extern M2C_UNK D_42EA80 __attribute__((section(".data")));
u32 func_359CF0(M2C_UNK *, s32);
s32 func_2B0AC0(M2C_UNK *, s32);

s32 func_0047CA30(s32 arg0, S_pool *pool) {
    u32 obj;
    s32 val;
    s32 r;
    s32 i;
    s32 off;
    S_member *elem;

    obj = func_359CF0(&D_421AD0, pool->unk4);
    if (obj == 0) {
        return 1;
    }
    for (i = 0; i < pool->count; i++) {
        elem = pool->members + i;
        val = elem->unk18;
        if (val >= 0) {
            *(s32 *)obj = val;
            r = func_2B0AC0(&D_42EA80, *(s32 *)obj);
            if (r != 0) {
                *(s32 *)(obj + 0x20) = r;
            }
        }
    }
    return 1;
}
