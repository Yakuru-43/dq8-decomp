// range: 0x1419A0 0x141B00
#include "common.h"

s32 func_0014E130(s32, s32);                        /* extern */
s32 func_00158980(void *, s32, s32);                 /* extern */
void *func_0015AEB0(void *, s32);                    /* extern */
void func_001FD7E0(s32, f32);                        /* extern */
void func_001FC930(s32, void *, s32);                /* extern */
extern u128 D_003A0C40;                              /* packet template */

typedef struct MgDraw {
    s32 n;                  /* 0x00 */
    char *buf;              /* 0x04 write cursor */
    void *items[1];         /* 0x08 */
    char pad0C[0x3B90 - 0x0C];
    void *texman;           /* 0x3B90 */
} MgDraw;

typedef struct Writer {
    char pad0[0x28];
    s32 base;               /* 0x28 record base */
    s32 count;              /* 0x2C */
} Writer;

typedef struct Entry {
    char pad0[0xC];
    s32 sub;                /* 0x0C */
} Entry;

s32 func_001419A0(MgDraw *obj, s32 key, f32 amount) {
    Writer *writer;
    void *texman;
    void *node;
    s32 rec_addr;
    s32 idx;
    Entry *entry;
    s32 sub;

    node = obj->items[obj->n];
    texman = obj->texman;
    writer = node != NULL ? (Writer *)((char *)node + 8) : NULL;
    if (texman == NULL || writer == NULL) {
        return 0;
    }
    rec_addr = writer->base + (writer->count << 4);
    idx = func_00158980(texman, key, rec_addr);
    if (idx <= 0) {
        return 0;
    }
    *(u128 *)(rec_addr + (idx << 4)) = 0;
    *(s32 *)(rec_addr + (idx << 4)) = 0x60000000;
    func_0014E130((s32)writer, idx + 1);
    if (0 != rec_addr) {
        *(u128 *)obj->buf = D_003A0C40;
        *(s32 *)(obj->buf + 4) = rec_addr & 0x0FFFFFFF;
        obj->buf = obj->buf + 0x10;
    }
    entry = func_0015AEB0(texman, key);
    if (entry != NULL) {
        sub = entry->sub;
        if (sub != 0) {
            if (0.0f >= amount) {
            } else {
                func_001FD7E0(sub, amount);
            }
            func_001FC930(sub, obj, key);
        }
    }
    return 1;
}
