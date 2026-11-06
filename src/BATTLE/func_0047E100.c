// range: 0x47E100 0x47E1D0
#include "common.h"

extern char *func_16D5B0(void *, s32);
extern s32 func_133F78(char *, char *);
extern void func_286A50(char *);
extern void func_286B30(char *, char *);
extern void func_286BE0(char *, char *);

extern char D_00484A00[]; /* "ON" */
extern char D_00484A08[]; /* "OFF" */
extern char D_00484430[]; /* "" */

typedef struct {
    char pad0[0x4];
    s32 field_4;
} S_actor;

typedef struct {
    char pad0[0x50];
    char *field_50;
    char *field_54;
} S_skill;

s32 func_0047E100(void *arg0, S_actor *arg1, S_skill *arg2) {
    char *r;

    r = func_16D5B0(arg0, arg1->field_4);
    if (r == 0) {
        return 1;
    }
    if (arg2->field_50 == 0) {
        return 1;
    }
    if (arg2->field_54 == 0) {
        return 1;
    }
    if (func_133F78(arg2->field_50, D_00484A00) == 0) {
        func_286BE0(r, arg2->field_54);
    } else if (func_133F78(arg2->field_50, D_00484A08) == 0) {
        if (func_133F78(arg2->field_54, D_00484430) == 0) {
            func_286A50(r);
        } else {
            func_286B30(r, arg2->field_54);
        }
    }
    return 0;
}
