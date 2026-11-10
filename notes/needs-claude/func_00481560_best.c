// range: 0x481560 0x4815F0
// flags: -flag divbyzerocheck
// try_match: -O3 -flag divbyzerocheck   (CLI flags override the // flags: line)
// best score 7: only the last 7 words differ (beql-inverted final if/else)
#include "common.h"

typedef struct {
    u8 pad0[0xA0];
    /* 0xA0 */ s32 field_A0;
    u8 padA4[0x10];
    /* 0xB4 */ char *field_B4;
} S_btl_481560;

s32 func_00481560(void *arg0, S_btl_481560 *arg1) {
    char *q;
    s32 n;
    s32 c;

    if (arg1 == 0) {
        return 1;
    }
    if (arg1->field_B4 == 0) {
        return 1;
    }
    q = arg1->field_B4 + 8;
    if (q == 0) {
        return 1;
    }
    n = *(s32 *)(q + 4) * 25 * 2 / 60;
    if (!(0 < n)) {
        n = 1;
    }
    c = arg1->field_A0;
    if (c < n) {
        arg1->field_A0 = c + 1;
        return 2;
    }
    arg1->field_A0 = 0;
    return 0;
}
