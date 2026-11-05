// range: 0x477480 0x477530
#include "common.h"

extern char *func_16D5B0(void *, s16);
extern void func_00460BB0(char *, s128 *);
extern void func_13B7B0(void *, void *, void *);
extern void func_151AB0(void *, void *);
extern void func_0046EBA0(void *);

typedef struct {
    char pad0[0xBC];
    s32 count;     /* 0xBC */
    char padC0[4];
    s16 kind;      /* 0xC4 */
    char padC6[0x3A];
    char field_100[0x10];
    char field_110[0x10];
} S_actor;

s32 func_00477480(void *arg0, S_actor *actor) {
    s128 buf;
    char *r;
    s32 n;

    r = func_16D5B0(arg0, actor->kind);
    if (r == 0) {
        func_0046EBA0(actor);
        return 1;
    }
    n = actor->count - 1;
    actor->count = n;
    if (n <= 0) {
        func_151AB0(r, actor->field_100);
        func_0046EBA0(actor);
        return 0;
    }
    func_00460BB0(r, &buf);
    func_13B7B0(&buf, &buf, actor->field_110);
    func_151AB0(r, &buf);
    return 0;
}
