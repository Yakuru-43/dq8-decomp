// range: 0x20D670 0x20D6D0
#include "common.h"

typedef struct {
    s32 id;
    f32 time;
    s8 kind;
} RecordInfo;

typedef struct {
    char pad0[0xC];
    s32 id;    /* +0x0C */
    f32 time;  /* +0x10 */
    char pad14[2];
    s8 kind;   /* +0x16 */
} Record;

extern void *D_003E08D0;
extern Record *func_0020D6D0(void *pool);

s32 func_0020D670(RecordInfo *out) {
    void *pool;
    Record *rec;

    if (out == 0) {
        return 0;
    }
    pool = D_003E08D0;
    if (pool == 0) {
        return 0;
    }
    rec = func_0020D6D0(pool);
    if (rec == 0) {
        return 0;
    }
    out->id = rec->id;
    out->time = rec->time;
    out->kind = rec->kind;
    return 1;
}
