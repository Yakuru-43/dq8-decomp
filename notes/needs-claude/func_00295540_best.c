// best attempt for func_00295540 (not matched; see func_00295540.md)
// range: 0x295540 0x295680
#include "common.h"

M2C_UNK func_00292830(s32);                          /* extern */
M2C_UNK func_002915F0(s32, s32);                     /* extern */
M2C_UNK func_002914D0(s32);                          /* extern */
s32 func_0035E590(s32);                              /* extern */
s32 func_00359620(s32, s32, s32 **, s32, s32, s32, s32, s32, s64); /* extern */
s64 func_0035DE00(void *);                           /* extern */
M2C_UNK func_0028F4F0(void *, void *, s32);          /* extern */
extern M2C_UNK D_00421AD0 __attribute__((section(".data")));
extern M2C_UNK D_00420C30 __attribute__((section(".data")));

/* when the group has no more than twice as many running as queued entries,
   refresh its arm state and hand the owner's live nodes (skipping the ones
   the model marks busy, code 5) to the sound check; ok when all were taken */
s32 func_00295540(s32 arg0) {
    s32 *result[32];
    s32 keys[12];
    s32 running;
    s32 over;
    s32 count;
    s32 n;
    s32 taken;
    s32 i;
    s32 *node;

    func_00292830(arg0);
    running = func_002915F0(arg0, 0);
    over = func_002915F0(arg0, 1) > running * 2;
    if (over != 0) {
        return 0;
    }
    func_002914D0(arg0);
    if (func_0035E590(*(s32 *)(arg0 + 0x58C)) <= 0) {
        return 1;
    }
    count = func_00359620((s32)&D_00421AD0,
        func_0035E590(*(s32 *)(arg0 + 0x58C)), result, 0x20,
        0, 1, 0, -1, 0);
    if (count <= 0) {
        return 0;
    }
    n = 0;
    for (i = 0; i < count; i++) {
        node = result[i];
        if ((s8)func_0035DE00(node) != 5) {
            keys[n] = *node;
            n++;
        }
    }
    taken = func_0028F4F0(&D_00420C30, keys, n);
    return taken == n;
}
