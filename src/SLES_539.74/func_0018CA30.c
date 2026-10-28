// range: 0x18CA30 0x18CA60
#include "common.h"

typedef struct {
    u8 pad_0[0x6B1C];
    s32 count;
    s32 data[1];
} Struct_0018CA30;

void func_0018CA30(Struct_0018CA30 *arg0, s32 arg1) {
    s32 temp_v1;

    temp_v1 = arg0->count;
    if (temp_v1 > 0) {
        return;
    }
    arg0->data[temp_v1] = arg1;
    arg0->count = arg0->count + 1;
}
