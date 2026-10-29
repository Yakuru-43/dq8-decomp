// best attempt (try 2/3, -O3): CLASS structural score=27 (26 words differ, 164 vs 168 B).
// Store section byte-exact; only the three conversion blocks differ (branch direction,
// base register a1 vs v1, element [1] base materialization).
// range: 0x1BCF90 0x1BD040
#include "common.h"

typedef struct {
    s32 tag;
    f32 val;
} S_tv;

typedef struct {
    s32 field_00;
    char *field_04;
    s32 field_08;
    char *field_0C;
    s32 field_10;
    char *field_14;
    S_tv tv[3];
} S_arg0;

static inline f32 ToFloat(S_tv *t) {
    f32 r;

    if (t->tag != 0) {
        r = t->val;
    } else {
        r = (f32)*(s32 *)&t->val;
    }
    return r;
}

s32 func_001BCF90(S_arg0 *arg0) {
    f32 v2;
    f32 v1;
    f32 v0;
    S_tv *tv;

    tv = arg0->tv;
    v2 = ToFloat(tv);
    v1 = ToFloat(tv + 1);
    v0 = ToFloat(tv + 2);
    if (arg0->field_00 == 3) {
        *(f32 *)(arg0->field_04 + 4) = v2;
    }
    if (arg0->field_08 == 3) {
        *(f32 *)(arg0->field_0C + 4) = v1;
    }
    if (arg0->field_10 == 3) {
        *(f32 *)(arg0->field_14 + 4) = v0;
    }
    return 1;
}
