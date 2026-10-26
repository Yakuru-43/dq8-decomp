// range: 0x29CB00 0x29CB80
#include "common.h"

typedef struct Entry0029CB00 {
    s32 id;
    char pad[0xC];
    s16 kind;
} Entry0029CB00;

typedef struct Obj0029CB00 {
    u8 b0;
    u8 b1;
    char pad[0x1A];
    Entry0029CB00 *entry;
} Obj0029CB00;

extern s32 func_00297090(void *arg0, void *arg1);

s32 func_0029CB00(void *arg0, Obj0029CB00 *obj)
{
    Entry0029CB00 *e;
    s32 kind;

    e = obj->entry;
    if (e == 0) {
        return 0;
    }
    if (e->id < 0) {
        return 0;
    }
    kind = e->kind;
    if (kind < 0) {
        return 0;
    }
    if (kind >= 2) {
        return 0;
    }
    if (obj->b0 != 0) {
        if (obj->b1 != 0) {
            return 1;
        }
        return !(func_00297090(e, obj) > 0);
    }
    return 1;
}
