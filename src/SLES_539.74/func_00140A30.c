// range: 0x140A30 0x140B00
#include "common.h"

typedef struct { /* 0000 */ s16 id; } Key;

typedef union {
    u128 q;
    struct { s32 w0; s32 w1; s32 w2; s32 w3; } v;
    struct { Key *key; s32 id; s32 w2; s32 w3; } kv;
} Quad;

typedef struct Thing { Quad q0, q1, q2; } Thing;

typedef struct { /* 0000 */ char pad_0[0x28]; char *data; s32 cursor; } Pool;

typedef struct {
    char pad_0[0x3B94];
    Pool *pool;           /* 3B94 */
    char pad_1[8];
    s32 *def;       /* 3BA0 */
    s32 count;      /* 3BA4 */
    s32 *ids;       /* 3BA8 */
    char pad_2[0x3BB8 - 0x3BAC];
    s32 *counters;  /* 3BB8 */
    Thing **links;  /* 3BBC */
} Obj;

void func_00140A30(Obj *obj, Thing *th, s32 idx) {
    Key *key; s32 id, *ids; Pool *pool; Thing *slot;

    key = th->q0.kv.key;
    if (key != 0) {
        id = key->id;
        if (obj->count <= id) {
            return;
        }
        if (id < 0) {
            return;
        }
        ids = obj->ids;
        if (ids != 0) {
            id = ids[id];
        }
        if (id < 0) {
            return;
        }
    } else {
        id = *obj->def;
    }
    pool = obj->pool;
    slot = (Thing *)(pool->data + pool->cursor * 0x10);
    pool->cursor = pool->cursor + 3;
    slot->q0 = th->q0;
    slot->q1 = th->q1;
    slot->q2 = th->q2;
    slot->q2.v.w1 = (s32)obj->links[idx];
    obj->links[idx] = slot;
    slot->q0.kv.id = id;
    obj->counters[id] = obj->counters[id] + 1;
}
