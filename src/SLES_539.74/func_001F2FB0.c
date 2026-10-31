// range: 0x1F2FB0 0x1F2FF0
#include "common.h"

typedef struct {
    s32 field_00;
    s32 *field_04;
    s32 field_08;
} Struct_1F2FB0;

void func_001F2FB0(Struct_1F2FB0 *arg0, s32 arg1) {
    arg0->field_08 = 0;
    if (arg0->field_04 != 0 && arg1 >= 0 && arg1 < 0xB) {
        arg0->field_08 = arg0->field_04[arg1];
    }
}
