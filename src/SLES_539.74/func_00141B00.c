// range: 0x141B00 0x141BF0
#include "common.h"

void *func_0013F720(void *);                           /* extern */
s32 func_00157E90(void *, void *);                     /* extern */
s32 func_0014E130(s32, s32);                           /* extern */
extern u128 D_003A0C40;                                /* packet template */

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

void func_00141B00(MgDraw *obj) {
    void *value;
    void *node;
    void *src;
    Writer *writer;
    s32 addr;

    value = func_0013F720((char *)obj + 0x130);
    if (value != 0) {
        *(u128 *)obj->buf = D_003A0C40;
        *(s32 *)(obj->buf + 4) = (u32)value & 0x0FFFFFFF;
        obj->buf = obj->buf + 0x10;
    }
    node = obj->items[obj->n];
    src = obj->src;
    writer = node != NULL ? (Writer *)((char *)node + 8) : NULL;
    if (writer != NULL) {
        addr = writer->base + (writer->count << 4);
        func_0014E130((s32)writer, func_00157E90(src, (void *)addr));
        *(u128 *)obj->buf = D_003A0C40;
        *(s32 *)(obj->buf + 4) = addr & 0x0FFFFFFF;
        obj->buf = obj->buf + 0x10;
    }
}
