// range: 0x212080 0x212100
// best attempt (120/124 bytes): daddu s0,a0 placement and the s0/v0 choice
// for func_00308460 arg1 still differ; see func_00212080.md
#include "common.h"

extern char *D_003E0908;
extern char D_003C7CB8[];

s32 func_00166760();
s32 func_00133F78(s32, char *);
s32 func_001814D0();
s32 func_001667C0(s32);
s16 func_00308460(s32, s32);

s32 func_00212080(s32 arg0) {
    s32 r;

    arg0 = arg0 + 8;
    r = func_00166760();
    if (func_00133F78(r, D_003C7CB8) == 0) {
        func_001814D0();
        arg0 = func_001667C0(arg0);
        *(s32 *)(D_003E0908 + 0x4E8) = func_00308460(arg0, arg0);
    }
    return 1;
}
