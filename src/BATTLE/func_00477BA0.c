// range: 0x477BA0 0x477C40
#include "common.h"

extern s32 func_305520(M2C_UNK *, M2C_UNK);
extern M2C_UNK D_00402010 __attribute__((section(".data")));
extern void func_0046EBA0(void *);

extern s32 D_004219F0 __attribute__((section(".data")));

#define timer_f (((f32 *)&D_004219F0)[-0x1B])

typedef struct {
    char pad0[0xBC];
    s32 count;
    char padC0[0x34];
    f32 field_F4;
    f32 field_F8;
} S_actor;

s32 func_00477BA0(s32 arg0, S_actor *actor) {
    s32 r;

    r = func_305520(&D_00402010, 0x10);
    if (r == 1) {
        timer_f = timer_f + actor->field_F8;
    }
    actor->count = actor->count - 1;
    if (actor->count <= 0) {
        if (r == 1) {
            timer_f = actor->field_F4;
        }
        func_0046EBA0(actor);
    }
    return 0;
}
