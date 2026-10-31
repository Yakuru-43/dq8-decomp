// range: 0x13FD20 0x13FF70
// best attempt (3 reloads + mask right, 628 B; MWCC tail-duplicated a push block)
#include "common.h"

typedef union Rec {
    u128 q;
    u32 w[4];
} Rec;

extern Rec D_003A0C40;

static inline void push_rec(char *obj, u32 v)
{
    *(u128 *)(*(u32 *)(obj + 4)) = D_003A0C40.q;
    *(u32 *)(*(u32 *)(obj + 4) + 4) = v & 0x0FFFFFFF;
    *(u32 *)(obj + 4) += 0x10;
}

void func_0013FD20(char *obj, u32 *arg, s32 count)
{
    u32 *src;
    u32 *slot;
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;
    u32 v5;
    s32 i;

    v0 = arg[0];
    if (count == 6) {
        v1 = arg[1];
        v2 = arg[2];
        v3 = arg[3];
        v4 = arg[4];
        v5 = arg[5];
        if (M2C_FIELD(obj, u32 *, 0x3C38) != v0) {
            push_rec(obj, v0);
            M2C_FIELD(obj, u32 *, 0x3C38) = v0;
        }
        if (M2C_FIELD(obj, u32 *, 0x3C3C) != v1) {
            push_rec(obj, v1);
            M2C_FIELD(obj, u32 *, 0x3C3C) = v1;
        }
        if (M2C_FIELD(obj, u32 *, 0x3C40) != v2) {
            push_rec(obj, v2);
            M2C_FIELD(obj, u32 *, 0x3C40) = v2;
        }
        if (M2C_FIELD(obj, u32 *, 0x3C44) != v3) {
            push_rec(obj, v3);
            M2C_FIELD(obj, u32 *, 0x3C44) = v3;
        }
        if (M2C_FIELD(obj, u32 *, 0x3C48) != v4) {
            push_rec(obj, v4);
            M2C_FIELD(obj, u32 *, 0x3C48) = v4;
        }
        if (M2C_FIELD(obj, u32 *, 0x3C4C) != v5) {
            push_rec(obj, v5);
            M2C_FIELD(obj, u32 *, 0x3C4C) = v5;
        }
    } else {
        src = arg;
        slot = (u32 *)(obj + 0x3C38);
        if (M2C_FIELD(obj, s32 *, 0x3C34) != count) {
            for (i = count; i > 0; i--) {
                u32 v = *src;
                push_rec(obj, v);
                *slot = v;
                src++;
                slot++;
            }
            M2C_FIELD(obj, s32 *, 0x3C34) = count;
        } else {
            for (i = count; i > 0; i--) {
                u32 v = *src;
                if (*slot != v) {
                    push_rec(obj, v);
                    *slot = v;
                }
                src++;
                slot++;
            }
        }
    }
}
