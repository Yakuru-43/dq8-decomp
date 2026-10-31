// range: 0x2D7560 0x2D75D0
#include "common.h"

struct Struct2D4150 {
    char pad[0x20];
    f32 field_20;
    f32 field_24;
};

extern struct Struct2D4150 *func_002D4150(void);

void func_002D7560(s32 arg0, s32 arg1, s32 *out0, s32 *out1) {
    struct Struct2D4150 *p;

    *out1 = 0;
    *out0 = 0;
    p = func_002D4150();
    if (p != 0) {
        *out0 = (s32)p->field_20;
        *out1 = (s32)p->field_24;
    }
}
