// range: 0x476C40 0x476CB0
#include "common.h"

extern void func_131188(void *, s32, s32); /* memset */

typedef struct {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
    f32 unk_18;
    s32 unk_1C;
    s32 unk_20;
    s32 unk_24;
    s32 unk_28;
} S_slot;

S_slot *func_00476C40(S_slot *self) {
    func_131188(self, 0, 0x2C);
    self->unk_00 = -1;
    self->unk_0C = -1;
    self->unk_10 = -1;
    self->unk_08 = 1;
    self->unk_14 = 1;
    self->unk_18 = 1.0f;
    self->unk_1C = 0;
    self->unk_20 = -1;
    self->unk_24 = 0;
    self->unk_28 = 0;
    return self;
}
