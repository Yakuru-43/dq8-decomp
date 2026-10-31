// range: 0x45F5E0 0x45F630
#include "common.h"

extern void func_131188(void *, s32, s32); /* memset */

typedef struct {
    char pad_00[0x2C];
    void *buf_2C; /* -> self + 0x40 */
    s32 cap_30;   /* 8 */
    s32 unk_34;
    void *buf_38; /* -> self + 0x60 */
    s32 cap_3C;   /* 8 */
    char pad_40[0x48];
} S_queue;

S_queue *func_0045F5E0(S_queue *self) {
    func_131188(self, 0, 0x88);
    self->cap_30 = 8;
    self->buf_2C = (void *)((char *)self + 0x40);
    self->cap_3C = 8;
    self->buf_38 = (void *)((char *)self + 0x60);
    return self;
}
