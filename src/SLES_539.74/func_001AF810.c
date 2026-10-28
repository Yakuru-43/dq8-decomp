// range: 0x1AF810 0x1AF860
#include "common.h"

typedef struct {
    s32 field_00;
    s32 field_04;
    s32 pad_08[2];
    u8 data_10[12];
    f32 field_1C;
    f32 field_20;
} S1AF810;

s32 func_001AF810(char *arg0, s32 arg1, s128 *arg2, f32 arg3) {
    S1AF810 *obj = (S1AF810 *)arg0;
    if (obj->field_00 >= 0) {
        obj->field_00 = -1;
        obj->field_04 = -1;
        *(s32 *)&obj->data_10[0] = 0;
        *(s32 *)&obj->data_10[4] = 0;
        *(s32 *)&obj->data_10[8] = 0;
        obj->field_1C = 1.0f;
    }
    obj->field_00 = 0;
    obj->field_04 = arg1;
    *(s128 *)&obj->data_10[0] = *arg2;
    obj->field_20 = arg3;
    return 1;
}
