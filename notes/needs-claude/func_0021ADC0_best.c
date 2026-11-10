// range: 0x21ADC0 0x21AE90
#include "common.h"

struct Obj_0021ADC0 {
    u8 pad_00[8];
    s32 field_08;
    u8 pad_0C[4];
    s32 field_10;
};

struct Slot_0021ADC0 {
    s8 field_00;
    u8 pad_01[0x11];
    u8 field_12;
    u8 pad_13[0x3D];
};

extern s32 func_0020D660(void);
extern struct Obj_0021ADC0 *func_0020D7F0(s32);
extern s32 func_0020D6E0(s32);
extern struct Slot_0021ADC0 *D_003E098C;

void func_0021ADC0(void) {
    struct Obj_0021ADC0 *obj;
    s32 count;
    s32 per;
    s32 i;

    count = 0;
    obj = func_0020D7F0(func_0020D660());
    if (obj != 0) {
        count = obj->field_10;
    }
    per = (func_0020D6E0(0) + 0x3FF) / 0x400;
    for (i = 0; i < 0x1E; i++) {
        struct Slot_0021ADC0 *slot = &D_003E098C[i];
        if (slot->field_00 == 0) {
            if (count < per) {
                slot->field_12 = 1;
                if (obj->field_08 == 0) {
                    slot->field_12 = 0;
                }
            } else {
                slot->field_12 = 0;
                count -= per;
            }
        }
    }
}
