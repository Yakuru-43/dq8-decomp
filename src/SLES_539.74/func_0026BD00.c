// range: 0x26BD00 0x26BD60
#include "common.h"

void func_002784F0(void *);                          /* extern */

typedef struct UnkObj {                              /* size 0x58 */
    /* 0x00 */ u8 pad_00[0x28];
    /* 0x28 */ void *field_28;
    /* 0x2C */ s32 field_2C;
    /* 0x30 */ s32 field_30;
    /* 0x34 */ s32 field_34;
    /* 0x38 */ s32 field_38;
    /* 0x3C */ u8 pad_3C[0x08];
    /* 0x44 */ s32 field_44;
    /* 0x48 */ s32 field_48;
    /* 0x4C */ s32 field_4C;
    /* 0x50 */ s32 field_50;
    /* 0x54 */ s32 field_54;
} UnkObj;

s32 func_0026BD00(s32 arg0, s32 arg1, UnkObj **arg2) {
    UnkObj *obj;

    obj = *arg2;
    if (obj->field_28 != 0) {
        func_002784F0(obj->field_28);
    }
    obj->field_44 = 0;
    obj->field_28 = 0;
    obj->field_2C = 0;
    obj->field_30 = 0;
    obj->field_48 = 0;
    obj->field_4C = 0;
    obj->field_34 = 0;
    obj->field_38 = 0;
    obj->field_50 = 0;
    obj->field_54 = 0;
    return 1;
}
