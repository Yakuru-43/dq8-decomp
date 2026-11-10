// BEST DRAFT, did NOT match (best score=16, 112 vs 120 bytes) — see .md
// range: 0x271C00 0x271C80
#include "common.h"

extern "C" {

typedef struct {
    /* +0x00 */ s32 unk0;
    /* +0x04 */ u32 count;
    /* +0x08 */ char *items; /* 16-byte records */
    /* +0x0C */ char padC[0x8];
    /* +0x14 */ u32 *tags;
} S_records;

typedef union {
    f32 f;
    u32 u;
    u16 h[2];
} Key;

void *func_00271C00(S_records *rec, u32 key) {
    Key k;
    u16 index;
    bool used;

    k.f = *(f32 *) &key;
    used = (0 < k.u) != false;   // best: gives sltu; then used == false folds
                                // to beql — orig has xori $v0,$v0,1 + bnel
    if (used == false) {
        return NULL;
    }
    index = k.h[0];
    if (index < rec->count) {
        if (rec->tags[index] == k.h[1]) {
            return rec->items + index * 16;
        }
    }
    return NULL;
}

}
