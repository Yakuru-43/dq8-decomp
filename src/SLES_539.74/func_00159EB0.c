// range: 0x159EB0 0x159FA0
#include "common.h"

extern s32 func_00130F38(void *a, void *b, s32 n);
extern char D_003C20A8[];
extern char D_003C20B0[];
extern char D_003C20B8[];
extern char D_003C20C0[];

/* Identifies an object by its leading tag bytes and returns the field that
 * goes with the tag: 1/2 -> the word at +4, 3 -> the word at +8, unknown -> 0. */
s32 func_00159EB0(s32 *obj) {
    s32 kind;

    if (obj == 0) {
        return 0;
    }
    if (obj == 0) {
        kind = 0;
    } else if (func_00130F38(obj, D_003C20B0, 2) != 0) {
        kind = 0;
    } else if (func_00130F38(obj, D_003C20B8, 3) == 0) {
        kind = 1;
    } else if (func_00130F38(obj, D_003C20C0, 3) == 0) {
        kind = 2;
    } else if (func_00130F38(obj, D_003C20A8, 3) == 0) {
        kind = 3;
    } else {
        kind = 0;
    }
    if (kind == 0) {
        return 0;
    }
    if ((u32)(kind - 1) <= 1) {
        return obj[1];
    }
    if (kind == 3) {
        return obj[2];
    }
    return 0;
}
