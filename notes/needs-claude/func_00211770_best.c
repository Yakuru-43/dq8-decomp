// best C for func_00211770 (score=65, CLASS structural) — NOT committed to src/
// range: 0x211770 0x211878
#include "common.h"

s32 func_00133F78(s32, char *);                     /* extern */
s32 func_0014D700(s32, s32);                        /* extern */
s32 func_00166760(char *);                          /* extern */
s32 func_001667C0();                                /* extern */
extern s8 D_003E08F4;
extern char *D_003E0908;
extern s16 D_003E0920;
extern s16 D_003E0922;
extern s32 D_003E0924;

s32 func_00211770(char *arg0, s32 arg1) {
    char *cursor;
    s32 obj0;
    s32 obj1;
    s32 val0;
    s32 val1;

    if (D_003E08F4 != 2) {
        return 0;
    }
    cursor = arg0;
    obj0 = func_00166760(cursor);
    cursor += 8;
    obj1 = func_00166760(cursor);
    cursor += 8;
    if (obj0 == 0 || obj1 == 0) {
        return 0;
    }
    if (arg1 < 3) {
        val0 = 0x1A;
        val1 = 0x1E;
    } else {
        func_001667C0(cursor);
        cursor += 8;
        val0 = func_001667C0(cursor);
        val1 = val0;
    }
    if (*(D_003E0908 + 0x3EC) != 0) {
        if (func_00133F78(obj0, D_003E0908 + 0x3EC) == 0) {
            D_003E0924 = func_0014D700(obj1, *(s32 *)(D_003E0908 + 0x5EC));
            D_003E0920 = val0;
            D_003E0922 = val1;
        }
        return 1;
    }
    return 0;
}
