// range: 0x2CB310 0x2CB3B0
// Best attempt 2026-11-03 factory-2: CLASS structural score=34 (172 vs 160),
// byte-identical to the if/else spellings. One f32 join via goto; the wall is
// CW's CSE/scheduling of the lui constants, not the control flow.
#include "common.h"

extern M2C_UNK D_00421AD0 __attribute__((section(".data")));
extern M2C_UNK D_0042EA80 __attribute__((section(".data")));

u32 func_00359CF0(M2C_UNK *);
s32 func_002B09C0(M2C_UNK *, s32);
u32 func_0016D5B0(void *, s32);

f32 func_002CB310(void *obj, s32 key)
{
    s32 *table;
    f32 *scale_p;
    s32 r;
    f32 scale;

    table = (s32 *)0x41000000;
    r = func_00359CF0(&D_00421AD0);
    if (r == 0) {
        return 8.0f;
    }
    if (table[8] == 0) {
        goto miss;
    }
    r = func_002B09C0(&D_0042EA80, table[0]);
    scale = (f32)r;
    goto done;
miss:
    r = func_0016D5B0(obj, key);
    if (r == 0) {
        return 10.0f;
    }
    scale_p = (f32 *)0x412004CC;
    scale = *scale_p;
done:
    return 2.0f * scale;
}
