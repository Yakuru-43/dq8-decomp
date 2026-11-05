/* Best of 2 attempts, 2026-11-05, factory-2 (branch factory-2), Qwen.
 * tools/try_match.py: CLASS structural score=47 (38 words differ, 184 vs 220 bytes).
 * NOT committed under src/: it does not match.
 */
// range: 0x239180 0x239260
#include "common.h"

extern s32 D_003E0B24;

s32 func_00239180(char *data, s32 nfields) {
    s32 start;
    s32 value;
    s32 count;
    s32 limit;
    s32 i;
    s32 obj;
    s32 entry;

    if (*(s32 *)data == 1) {
        start = (s32)*(float *)(data + 4);
    } else {
        start = *(s32 *)(data + 4);
    }
    if (*(s32 *)(data + 8) == 1) {
        value = (s32)*(float *)(data + 0xC);
    } else {
        value = *(s32 *)(data + 0xC);
    }
    count = 1;
    if (nfields >= 3) {
        if (*(s32 *)(data + 0x10) == 1) {
            count = (s32)*(float *)(data + 0x14);
        } else {
            count = *(s32 *)(data + 0x14);
        }
    }
    limit = start + count;
    for (i = start; i < limit; i++) {
        obj = D_003E0B24;
        entry = 0;
        if (obj != 0) {
            if (i < *(s32 *)(obj + 0x2C)) {
                entry = *(s32 *)(obj + 0x28) + i * 272;
            }
        }
        if (entry == 0) {
            return 0;
        }
        *(s32 *)(entry + 8) = value;
    }
    return 1;
}
