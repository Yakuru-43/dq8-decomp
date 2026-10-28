// range: 0x14D4B0 0x14D510
#include "common.h"

typedef struct {
    u8 pad_0[0x13];
    u8 field_13;
    u8 field_14;
    u8 pad_15[0x60 - 0x15];
    void *field_60;
} Struct14D4B0;

typedef struct {
    u8 pad_0[0x20];
    s32 field_20;
} Struct14D4B0B;

s32 func_0014D4B0(char **arg0) {
    Struct14D4B0 *temp_a1;
    void *var_v0;

    temp_a1 = (Struct14D4B0 *)(*arg0);
    if (temp_a1 == NULL) {
        return 0;
    }
    if (temp_a1->field_13 != 0x10) {
        return 0;
    }
    if (temp_a1->field_14 != 8 && temp_a1->field_14 != 0x10) {
        return 0;
    }
    if (temp_a1 != NULL) {
        var_v0 = temp_a1->field_60;
    } else {
        var_v0 = NULL;
    }
    if (var_v0 == NULL) {
        return 0;
    }
    return ((Struct14D4B0B *)var_v0)->field_20;
}
