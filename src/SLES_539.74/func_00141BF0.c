// range: 0x141BF0 0x141C50
#include "common.h"

void func_0013F780(void *, void *, void *);            /* extern */
void func_0013F770(void *);                            /* extern */

typedef struct MgDraw {
    s32 n;                  /* 0x00 */
    char *buf;              /* 0x04 write cursor */
    void *items[1];         /* 0x08 */
    char pad0C[0x130 - 0x0C];
    char sub[0x100];        /* 0x130 stream state */
    char pad230[0x270 - 0x230];
    void *src;              /* 0x270 */
} MgDraw;

char *func_00141BF0(MgDraw *obj) {
    void *node;
    void *src;
    void *writer;

    node = obj->items[obj->n];
    src = obj->src;
    writer = node != NULL ? (char *)node + 8 : NULL;
    func_0013F780(obj->sub, writer, src);
    func_0013F770(obj->sub);
    return obj->sub;
}
