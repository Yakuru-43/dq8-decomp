// range: 0x480450 0x480500
#include "common.h"

extern char *func_00479C50(char *);
extern void func_2CB5F0(void *, void *, void *, s32);
extern char *func_16D5B0(void *, s32);
extern void func_151AB0(void *, void *);
extern void func_151A20(void *, void *);

typedef struct {
    char pad0[0x4];
    s32 field_4;
    char pad8[0xAC];
    char *field_B4;
} S_actor;

s32 func_00480450(void *arg0, S_actor *arg1) {
    u128 buf_50;
    u128 buf_40;
    char *q;
    char *r;
    s32 n;

    if (arg1->field_B4 == 0) {
        return 1;
    }
    q = arg1->field_B4 + 8;
    if (q == 0) {
        return 1;
    }
    n = *(s32 *)(q + 4);
    func_00479C50(q);
    func_2CB5F0(arg0, &buf_50, &buf_40, n);
    if ((r = func_16D5B0(arg0, arg1->field_4)) == 0) {
        return 1;
    }
    func_151AB0(r, &buf_50);
    func_151A20(r, &buf_40);
    return 0;
}
