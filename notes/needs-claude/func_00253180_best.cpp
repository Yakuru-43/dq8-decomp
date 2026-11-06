// range: 0x253180 0x253240
#include "common.h"

extern "C" {

typedef struct PoolRec {
    /* 0x00 */ u8 pad_00[0x58];
    /* 0x58 */ s32 state;
    /* 0x5C */ s32 id;
    /* 0x60 */ u8 pad_60[0x80];
} PoolRec;

extern PoolRec *D_003E0C14;
extern s8 D_003E0C18;

static inline bool SameId(s32 a, s32 b) {
    return a == b;
}

PoolRec *func_00253180(s32 arg0) {
    PoolRec *pool = D_003E0C14;
    PoolRec *rec;
    s32 i;
    s8 count;

    if (pool == 0) {
        return 0;
    }
    if (0 < arg0) {
        count = D_003E0C18;
        rec = pool;
        for (i = 0; i < (pool == 0 ? 0 : count); rec++) {
            if (SameId(rec->id, arg0) != false) {
                return rec;
            }
            i++;
        }
    } else {
        count = D_003E0C18;
        rec = pool;
        for (i = 0; i < (pool == 0 ? 0 : count); rec++) {
            if (rec->state < 0) {
                return rec;
            }
            i++;
        }
    }
    return 0;
}

}
