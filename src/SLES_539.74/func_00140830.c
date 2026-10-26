// range: 0x140830 0x140890
#include "common.h"

typedef struct {
    /* 0000 */ char pad_0[0x3BA4];
    /* 3BA4 */ s32 count;
    /* 3BA8 */ s32 *ids;
} Obj;

s32 func_00140580(Obj *, s32);             /* extern */

s32 func_00140830(Obj *o, s32 idx) {
    s32 id;

    if (idx < 0 || idx >= o->count) {
        return 0;
    }
    id = idx;
    if (o->ids != 0) {
        id = o->ids[idx];
    }
    if (id < 0) {
        return 0;
    }
    return func_00140580(o, id);
}
