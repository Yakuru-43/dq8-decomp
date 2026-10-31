// range: 0x313A70 0x313B30
#include "common.h"

typedef struct Pair8 {
    u8 a;
    u8 b;
} Pair8;                                  /* 0x08 */

typedef struct Pairs8 {
    Pair8 item[8];                        /* 0x00 */
} Pairs8;                                 /* 0x10 */

typedef struct Pair32 {
    s32 a;
    s32 b;
} Pair32;                                 /* 0x08 */

typedef struct Table {
    Pair32 item[57];                      /* 0x00 */
} Table;                                  /* 0x1C8 */

typedef struct Big520 {
    s32 field_00;                         /* 0x00 */
    s32 field_04;                         /* 0x04 */
    s32 field_08;                         /* 0x08 */
    s32 field_0C;                         /* 0x0C */
    s32 field_10;                         /* 0x10 */
    Pairs8 p8;                            /* 0x14 */
    Table table;                          /* 0x24 */
    s32 field_1EC;                        /* 0x1EC */
    s32 field_1F0;                        /* 0x1F0 */
    s32 field_1F4;                        /* 0x1F4 */
    s32 field_1F8;                        /* 0x1F8 */
    s32 field_1FC;                        /* 0x1FC */
    s32 field_200;                        /* 0x200 */
    s32 field_204;                        /* 0x204 */
} Big520;                                 /* 0x208 */

void *func_00313A70(Big520 *dst, Big520 *src) {
    dst->field_00 = src->field_00;
    dst->field_04 = src->field_04;
    dst->field_08 = src->field_08;
    dst->field_0C = src->field_0C;
    dst->field_10 = src->field_10;
    dst->p8 = src->p8;
    dst->table = src->table;
    dst->field_1EC = src->field_1EC;
    dst->field_1F0 = src->field_1F0;
    dst->field_1F4 = src->field_1F4;
    dst->field_1F8 = src->field_1F8;
    dst->field_1FC = src->field_1FC;
    dst->field_200 = src->field_200;
    dst->field_204 = src->field_204;
    return dst;
}
