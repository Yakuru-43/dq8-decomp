// range: 0x141CA0 0x141CE0
#include "common.h"

extern u128 D_003A0C40;                                /* packet template */

typedef struct MgDraw {
    s32 n;                  /* 0x00 */
    char *buf;              /* 0x04 write cursor */
} MgDraw;

char *func_00141CA0(MgDraw *obj, void *value) {
    if (value == 0) {
        return 0;
    }
    *(u128 *)obj->buf = D_003A0C40;
    *(s32 *)(obj->buf + 4) = (u32)value & 0x0FFFFFFF;
    obj->buf = obj->buf + 0x10;
    return obj->buf;
}
