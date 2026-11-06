// range: 0x47D3D0 0x47D480
#include "common.h"

extern char *func_2CDAF0(s32, s32);
extern char *func_16D5B0(void *, s32);
extern char *func_288AB0(char *);
extern s32 func_133F78(char *, char *);
extern int func_00461210(char *);

typedef struct {
    char pad0[0x4];
    s32 field_4;
} S_actor;

s32 func_0047D3D0(void *arg0, S_actor *actor) {
    char *h;
    char *r;
    char *t;

    h = func_2CDAF0(actor->field_4, 1);
    if (h == 0) {
        return 0;
    }
    r = func_16D5B0(arg0, actor->field_4);
    if (r == 0) {
        return 0;
    }
    t = func_288AB0(r);
    if (t == 0) {
        return 0;
    }
    if (func_133F78(h, t) == 0) {
        return func_00461210(r) != 0 ? 0 : 2;
    }
    return 0;
}
