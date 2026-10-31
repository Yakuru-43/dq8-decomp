// range: 0x460BF0 0x460C60
#include "common.h"

extern void func_131188(void *, s32, s32); /* memset */

typedef struct {
    s32 sel_00;  /* -1 */
    s32 num_04;
    s32 cnt_08;  /* 1 */
    s32 sel_0C;  /* -1 */
    s32 num_10;  /* -1 */
    s32 cnt_14;  /* 1 */
    f32 f_18;    /* 1.0f */
    s32 num_1C;
    s32 sel_20;  /* -1 */
    s32 num_24;
    s32 num_28;
} S_shop;

S_shop *func_00460BF0(S_shop *self) {
    func_131188(self, 0, 0x2C);
    self->sel_00 = -1;
    self->sel_0C = -1;
    self->num_10 = -1;
    self->cnt_08 = 1;
    self->cnt_14 = 1;
    self->f_18 = 1.0f;
    self->num_1C = 0;
    self->sel_20 = -1;
    self->num_24 = 0;
    self->num_28 = 0;
    return self;
}
