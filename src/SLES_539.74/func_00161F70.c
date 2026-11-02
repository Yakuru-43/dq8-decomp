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

static inline Entry *find_entry(char *name) {
    Entry *p;
    s32 i;

    if (D_003E030C == 0) {
        return 0;
    }
    p = D_003F6D00;
    i = 0;
    while (i < 0x30) {
        if (p->field_00 != 0) {
            if (func_00133BE0(p->field_10, name) == 0) {
                return p;
            }
        }
        i++;
        p++;
    }
    return 0;
}

s32 func_00161F70(char *arg0, s32 *arg1) {
    Entry *p;

    if (arg1 != 0) {
        *arg1 = 0;
    }
    p = find_entry(arg0);
    if (p == 0) {
        return 0;
    }
    if (arg1 != 0) {
        *arg1 = p->field_04;
    }
    return p->field_00;
}
