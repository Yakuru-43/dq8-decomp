// best attempt for func_001618F0 (NOT matched — keep out of src/ and the yaml)
// range: 0x1618F0 0x1619F0
#include "common.h"

M2C_UNK func_00133CB8(M2C_UNK *, void *);
M2C_UNK func_001340C0(M2C_UNK *, void *);
extern s32 D_003DFB94;
extern char *D_003A1360[];
extern M2C_UNK D_003C24D0 __attribute__((section(".data")));
extern M2C_UNK D_003F26B0 __attribute__((section(".data")));

void func_001618F0(char *arg0, M2C_UNK *arg1) {
    char *p;
    s32 n;
    s32 one;
    s8 c;
    s32 idx;

    p = arg0;
    n = 0;
    while ((c = *p) != 0) {
        if (c == ':') {
            break;
        }
        p++;
        n++;
    }
    one = (n == 1);
    if (c != 0 && one == 0) {
        func_001340C0(arg1, arg0);
        return;
    }
    idx = D_003DFB94;
    if (idx >= 0 && idx < 5) {
        func_001340C0(arg1, D_003A1360[idx]);
        func_00133CB8(arg1, &D_003C24D0);
    }
    if (one == 0) {
        func_00133CB8(arg1, &D_003F26B0);
    }
    func_00133CB8(arg1, arg0);
}
