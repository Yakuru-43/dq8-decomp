// range: 0x141C50 0x141C70
#include "common.h"

typedef struct MgDraw {
    s32 n;                  /* 0x00 */
    char *buf;              /* 0x04 write cursor */
} MgDraw;

void func_00141C50(MgDraw *obj, u128 *src) {
    *(u128 *)obj->buf = *src;
    obj->buf = obj->buf + 0x10;
}
