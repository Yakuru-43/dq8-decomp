// range: 0x141C70 0x141CA0
#include "common.h"

extern u128 D_003A0C40;                                /* packet template */

typedef struct MgDraw {
    s32 n;                  /* 0x00 */
    char *buf;              /* 0x04 write cursor */
} MgDraw;

void func_00141C70(MgDraw *obj, s32 value) {
    *(u128 *)obj->buf = D_003A0C40;
    *(s32 *)(obj->buf + 4) = value & 0x0FFFFFFF;
    obj->buf = obj->buf + 0x10;
}
