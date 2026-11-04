// range: 0x142A10 0x142B60
#include "common.h"

typedef struct V4A10 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} V4A10;                                       /* 0x10 */

typedef struct PairA10 {
    s32 x;
    s32 y;
} PairA10;                                     /* 0x08 */

typedef struct SlotsA10 {
    PairA10 item[8];                           /* 0x00 */
} SlotsA10;                                    /* 0x40 */

typedef union QuadA10 {
    u128 q;
    f32 v[4];
} QuadA10;                                     /* 0x10 */

typedef struct BonesA10 {
    QuadA10 item[12];                          /* 0x00 */
} BonesA10;                                    /* 0xC0 */

typedef struct RecordA10 {
    s32 field_00;                              /* 0x00 */
    s32 field_04;                              /* 0x04 */
    u8 *field_08[2];                           /* 0x08 (not copied here) */
    V4A10 vec_10;                              /* 0x10 */
    SlotsA10 slots_20;                         /* 0x20 */
    SlotsA10 slots_60;                         /* 0x60 */
    V4A10 vec_A0;                              /* 0xA0 */
    V4A10 vec_B0;                              /* 0xB0 */
    V4A10 vec_C0;                              /* 0xC0 */
    V4A10 vec_D0;                              /* 0xD0 */
    BonesA10 bones_E0;                         /* 0xE0 */
} RecordA10;                                   /* 0x1A0 */

void func_00142A10(void *arg0, RecordA10 *arg1) {
    RecordA10 *src;

    if (M2C_FIELD(arg0, s32 *, 0xF20) == 0) {
        return;
    }
    src = M2C_FIELD(arg0, RecordA10 **, 0x36B0);
    arg1->field_00 = src->field_00;
    arg1->field_04 = src->field_04;
    arg1->vec_10 = src->vec_10;
    arg1->slots_20 = src->slots_20;
    arg1->slots_60 = src->slots_60;
    arg1->vec_A0 = src->vec_A0;
    arg1->vec_B0 = src->vec_B0;
    arg1->vec_C0 = src->vec_C0;
    arg1->vec_D0 = src->vec_D0;
    arg1->bones_E0 = src->bones_E0;
    arg1->field_04 = 0;
}
