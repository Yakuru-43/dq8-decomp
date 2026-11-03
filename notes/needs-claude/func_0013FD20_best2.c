// range: 0x13FD20 0x13FF70
// factory-1 2026-11-03 variant, NOT matched (620 B; loop A byte-exact, +0x18..+0x5C;
// the 8 compare bodies land cold — see the Addendum in func_0013FD20.md)
#include "common.h"

extern u128 D_003A0C40;                                /* packet template */

typedef struct MgDraw {
    s32 n;                  /* 0x00 */
    char *buf;              /* 0x04 write cursor */
    char pad08[0x3C34 - 0x08];
    s32 cached;             /* 0x3C34 cached count */
    s32 slots[0x20];        /* 0x3C38 selected ids */
} MgDraw;

static __inline void PushPacket(MgDraw *obj, u32 id) {
    *(u128 *)obj->buf = D_003A0C40;
    *(u32 *)(obj->buf + 4) = id & 0x0FFFFFFF;
    obj->buf = obj->buf + 0x10;
}

void func_0013FD20(MgDraw *obj, u32 *ids, s32 count) {
    u32 id;
    s32 n;
    s32 *slot;

    if (count == 6) {
        u32 a = ids[0];
        u32 b = ids[1];
        u32 c = ids[2];
        u32 d = ids[3];
        u32 e = ids[4];
        u32 f = ids[5];

        if (obj->slots[0] != a) {
            PushPacket(obj, a);
            obj->slots[0] = a;
        }
        if (obj->slots[1] != b) {
            PushPacket(obj, b);
            obj->slots[1] = b;
        }
        if (obj->slots[2] != c) {
            PushPacket(obj, c);
            obj->slots[2] = c;
        }
        if (obj->slots[3] != d) {
            PushPacket(obj, d);
            obj->slots[3] = d;
        }
        if (obj->slots[4] != e) {
            PushPacket(obj, e);
            obj->slots[4] = e;
        }
        if (obj->slots[5] != f) {
            PushPacket(obj, f);
            obj->slots[5] = f;
        }
        return;
    }
    slot = obj->slots;
    if (obj->cached != count) {
        n = count;
        while (n > 0) {
            id = *ids;
            n--;
            PushPacket(obj, id);
            *slot = id;
            ids++;
            slot++;
        }
        obj->cached = count;
    } else {
        while (count > 0) {
            id = *ids;
            if (*slot != id) {
                PushPacket(obj, id);
                *slot = id;
            }
            count--;
            ids++;
            slot++;
        }
    }
}
