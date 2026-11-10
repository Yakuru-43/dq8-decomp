// range: 0x142C60 0x142DE0
#include "common.h"

typedef struct V4C60 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} V4C60;                                       /* 0x10 */

typedef struct PairC60 {
    s32 x;
    s32 y;
} PairC60;                                     /* 0x08 */

typedef struct SlotsC60 {
    PairC60 item[8];                           /* 0x00 */
} SlotsC60;                                    /* 0x40 */

typedef union QuadC60 {
    u128 q;
    f32 v[4];
} QuadC60;                                     /* 0x10 */

typedef struct BonesC60 {
    QuadC60 item[12];                          /* 0x00 */
} BonesC60;                                    /* 0xC0 */

typedef struct RecordC60 {
    s32 field_00;                              /* 0x00 */
    s32 field_04;                              /* 0x04 */
    u8 *field_08[2];                           /* 0x08 (not copied here) */
    V4C60 vec_10;                              /* 0x10 */
    SlotsC60 slots_20;                         /* 0x20 */
    SlotsC60 slots_60;                         /* 0x60 */
    V4C60 vec_A0;                              /* 0xA0 */
    V4C60 vec_B0;                              /* 0xB0 */
    V4C60 vec_C0;                              /* 0xC0 */
    V4C60 vec_D0;                              /* 0xD0 */
    BonesC60 bones_E0;                         /* 0xE0 */
} RecordC60;                                   /* 0x1A0 */

RecordC60 *func_00142C60(void *arg0, RecordC60 *arg1, s32 arg2) {
    s32 counter;
    RecordC60 *old;

    if (arg1 == 0) {
        return 0;
    }
    if (M2C_FIELD(arg0, s32 *, 0xF20) == 0) {
        return 0;
    }
    counter = M2C_FIELD(arg0, s32 *, 0x36BC);
    old = M2C_FIELD(arg0, RecordC60 **, 0x36B0);
    M2C_FIELD(arg0, s32 *, 0x36BC) = counter + 1;
    arg1->field_00 = counter;
    if (arg2 == 0) {
        M2C_FIELD(arg0, s32 *, 0x36B8) = arg1->field_00;
    } else {
        arg1->field_00 = old->field_00;
        arg1->field_04 = old->field_04;
        arg1->vec_10 = old->vec_10;
        arg1->slots_20 = old->slots_20;
        arg1->slots_60 = old->slots_60;
        arg1->vec_A0 = old->vec_A0;
        arg1->vec_B0 = old->vec_B0;
        arg1->vec_C0 = old->vec_C0;
        arg1->vec_D0 = old->vec_D0;
        arg1->bones_E0 = old->bones_E0;
        arg1->field_04 = 0;
    }
    M2C_FIELD(arg0, s32 **, 0x36B0) = (s32 *)arg1;
    return old;
}
