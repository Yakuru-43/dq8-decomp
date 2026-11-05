// range: 0x4773C0 0x477480
#include "common.h"

extern char *func_16D5B0(void *, s16);
extern void func_0045EFF0(char *, s128 *);
extern void func_151A20(void *, void *);
extern void func_0046EBA0(void *);

typedef struct {
    char pad0[0xBC];
    s32 count;     /* 0xBC */
    char padC0[4];
    s16 kind;      /* 0xC4 */
    char padC6[0x2E];
    f32 field_F4;  /* 0xF4 */
    f32 field_F8;  /* 0xF8 */
} S_actor;

s32 func_004773C0(void *arg0, S_actor *actor) {
    f32 buf[4];
    char *r;
    s32 n;

    r = func_16D5B0(arg0, actor->kind);
    if (r == 0) {
        func_0046EBA0(actor);
        return 1;
    }
    func_0045EFF0(r, (s128 *)buf);
    buf[1] += actor->field_F4;
    func_151A20(r, buf);
    n = actor->count - 1;
    actor->count = n;
    if (n <= 0) {
        buf[1] = actor->field_F8;
        func_151A20(r, buf);
        func_0046EBA0(actor);
    }
    return 0;
}
