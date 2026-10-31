// range: 0x165B20 0x165B60
#include "common.h"

typedef struct {
    s32 field_00;
    s32 field_04;
    s32 field_08;
} Struct_165B20;

s32 func_00165B20(Struct_165B20 *arg0, s32 *arg1) {
    s32 base = arg0->field_00;
    s32 offset = arg0->field_08;
    *arg1 = (s32)*(u8 *)(base + offset);
    arg0->field_08 = arg0->field_08 + 1;
    return arg0->field_04 >= arg0->field_08;
}
