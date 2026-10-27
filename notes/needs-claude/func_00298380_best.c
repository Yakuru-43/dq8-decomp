// Best attempt for func_00298380 (needs-claude) — see func_00298380.md
// range: 0x298380 0x2983C0
#include "common.h"

s32 func_00298380(char *base, s32 key)
{
    s32 result = -1;
    s32 i;

    for (i = 0; i < 32; i++) {
        char *entry = base + (i * 32);
        if (key == *(s32 *)(entry + 0x64)) {
            continue;
        }
        result = i;
    }
    return result;
}
