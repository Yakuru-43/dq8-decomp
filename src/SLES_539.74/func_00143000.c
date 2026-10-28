// range: 0x143000 0x143030
#include "common.h"

typedef struct {
    s32 field_0;
    s32 pad_4;
    s32 field_8;
    s32 field_C;
} Struct_00143000;

void func_00143000(char *arg0, s32 arg1, s32 arg2) {
    Struct_00143000 *obj = *(Struct_00143000 **)(arg0 + 0xF20);
    s32 sel = arg1 & 0xFF;

    switch (sel) {
    case 0:
        obj->field_0 = arg2;
        break;
    case 1:
        obj->field_8 = arg2;
        break;
    case 2:
        obj->field_C = arg2;
        break;
    }
}
