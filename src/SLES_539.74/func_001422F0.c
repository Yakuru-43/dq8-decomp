// range: 0x1422F0 0x1423A0
#include "common.h"

s32 func_00157E90(void *, void *);                     /* extern */
s32 func_0014E130(s32, s32);                            /* extern */
extern u128 D_003A0C40;                                 /* packet template */

typedef struct MgDraw {
    s32 n;                  /* 0x00 */
    char *buf;              /* 0x04 write cursor */
    void *items[1];         /* 0x08 */
    char pad0C[0x270 - 0x0C];
    void *src;              /* 0x270 */
} MgDraw;

typedef struct Writer {
    char pad0[0x28];
    s32 base;               /* 0x28 record base */
    s32 count;              /* 0x2C */
} Writer;

void func_001422F0(MgDraw *obj) {
    void *node;
    void *src;
    Writer *writer;
    s32 addr;

    src = obj->src;
    node = obj->items[obj->n];
    writer = node != NULL ? (Writer *)((char *)node + 8) : NULL;
    if (writer != NULL) {
        addr = writer->base + (writer->count << 4);
        func_0014E130((s32)writer, func_00157E90(src, (void *)addr));
        *(u128 *)obj->buf = D_003A0C40;
        *(s32 *)(obj->buf + 4) = addr & 0x0FFFFFFF;
        obj->buf = obj->buf + 0x10;
    }
}
