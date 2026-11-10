// best C for func_00211880 (score=104, CLASS structural) — NOT committed to src/
// Keep this shape: separate entry0..entry4 variables defeat CW's cursor fold
// (single `cursor += 8` variable always folds to addiu $a0, $base, k*8).
// range: 0x211880 0x211A44
#include "common.h"

M2C_UNK func_001339E0(char *, char *, s32, s32);      /* extern */
s32 func_00133F78(s32, s32);                           /* extern */
s32 func_0014D700(s32, s32);                           /* extern */
s32 func_00166760(s32);                                /* extern */
s32 func_001667C0(s32);                                /* extern */
extern s8 D_003E08F4;
extern char *D_003E0908;
extern s32 D_003E0954;
extern s16 D_003E0920;
extern s16 D_003E0922;
extern s32 D_003E0924;
extern char D_003C7C98[];                              /* format */
extern char D_003C7CA8[];                              /* format */

s32 func_00211880(s32 arg0, s32 arg1) {
    s32 entry0;
    s32 entry1;
    s32 entry2;
    s32 entry3;
    s32 entry4;
    s32 obj0;
    s32 num0;
    s32 obj1;
    s32 val0;
    s32 val1;
    s32 ok;
    char buf80[0x40];
    char bufC0[0x40];

    entry0 = arg0;
    if (D_003E08F4 != 1) {
        return 0;
    }
    obj0 = func_00166760(entry0);
    entry1 = entry0 + 8;
    num0 = func_001667C0(entry1);
    entry2 = entry1 + 8;
    obj1 = func_00166760(entry2);
    entry3 = entry2 + 8;
    if (obj0 == 0 || obj1 == 0) {
        return 0;
    }
    if (arg1 < 4) {
        func_001667C0(entry3);
        entry4 = entry3 + 8;
        val0 = func_001667C0(entry4);
        val1 = val0;
    } else {
        val0 = 0x10;
        val1 = 0x12;
    }
    if (*(D_003E0908 + 0x3F4) == 0) {
        return 0;
    }
    ok = 0;
    func_001339E0(buf80, D_003C7C98, obj0, num0);
    func_001339E0(bufC0, D_003C7C98, (s32)(D_003E0908 + 0x3F4), num0);
    if (func_00133F78((s32)buf80, D_003E0954 + 4) == 0) {
        ok = 1;
    } else if (num0 == 0) {
        func_001339E0(buf80, D_003C7CA8, obj0, num0);
        func_001339E0(bufC0, D_003C7CA8, (s32)(D_003E0908 + 0x3F4), num0);
        if (func_00133F78((s32)buf80, D_003E0954 + 4) == 0) {
            ok = 1;
        }
    }
    if (ok != 0) {
        D_003E0924 = func_0014D700(obj1, *(s32 *)(D_003E0908 + 0x5EC));
        D_003E0920 = val0;
        D_003E0922 = val1;
    }
    return 1;
}
