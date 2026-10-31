// range: 0x159FA0 0x15A050
#include "common.h"

extern s32 func_00130F38(void *a, void *b, s32 n);
extern char D_003C20A8[];
extern char D_003C20B0[];
extern char D_003C20B8[];
extern char D_003C20C0[];

/* Maps an object's leading tag bytes onto a tag number: 1, 2 or 3;
 * anything else (including a null object) gives 0. */
s32 func_00159FA0(s32 *obj) {
    if (obj == 0) {
        return 0;
    }
    if (func_00130F38(obj, D_003C20B0, 2) != 0) {
        return 0;
    }
    if (func_00130F38(obj, D_003C20B8, 3) == 0) {
        return 1;
    }
    if (func_00130F38(obj, D_003C20C0, 3) == 0) {
        return 2;
    }
    return func_00130F38(obj, D_003C20A8, 3) == 0 ? 3 : 0;
}
