// best draft for func_00161F70 (NOT matched; do not commit into src/)
// range: 0x161F70 0x162030
#include "common.h"

typedef struct {
    s32 field_00;
    s32 field_04;
    u8 pad08[8];
    char field_10[0x30];
} Entry;

extern s32 func_00133BE0(char *a0, char *a1);
extern s32 D_003E030C;
extern Entry D_003F6D00[];

s32 func_00161F70(char *arg0, s32 *arg1) {
    Entry *p;
    s32 i;

    if (arg1 != 0) {
        *arg1 = 0;
    }
    p = 0;
    if (D_003E030C != 0) {
        p = D_003F6D00;
        i = 0;
        while (i < 0x30) {
            if (p->field_00 != 0) {
                if (func_00133BE0(p->field_10, arg0) == 0) {
                    goto found;
                }
            }
            i++;
            p++;
        }
        p = 0;
    }
found:
    if (p == 0) {
        return 0;
    }
    if (arg1 != 0) {
        *arg1 = p->field_04;
    }
    return p->field_00;
}
