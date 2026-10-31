// range: 0x1AA760 0x1AA7E0
#include "common.h"

extern f32 func_00129E60(f32);
extern f32 func_00129BC0(f32);

typedef struct {
    u8 pad_00[0x30];
    f32 field_30;
} S1;

typedef struct {
    u8 pad_00[0xB0];
    f32 field_B0;
    u8 pad_B4[4];
    f32 field_B8;
    u8 pad_BC[4];
    f32 field_C0;
    u8 pad_C4[4];
    f32 field_C8;
    u8 pad_CC[4];
    f32 field_D0;
    u8 pad_D4[4];
    f32 field_D8;
} S0;

s32 func_001AA760(S1 *s1, S0 *s0) {
    f32 v0;

    v0 = func_00129E60(s1->field_30);
    v0 = s0->field_C0 + s0->field_D8 * v0;
    s0->field_B0 = v0;

    v0 = func_00129BC0(s1->field_30);
    v0 = s0->field_C8 + s0->field_D8 * v0;
    s0->field_B8 = v0;

    s0->field_D0 = s1->field_30;

    return 0;
}
