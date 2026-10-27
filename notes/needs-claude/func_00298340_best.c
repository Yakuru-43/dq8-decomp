// Best attempt for func_00298340 (needs-claude) — see func_00298340.md
// range: 0x298340 0x298380
#include "common.h"

void *func_00298340(char *base, s32 key)
{
    void *result = 0;
    s32 i;

    for (i = 0; i < 32; i++) {
        char *entry = base + (i * 32);
        void *found = entry + 0x48;
        if (key == *(s32 *)(entry + 0x64)) {
            result = found;
        }
    }
    return result;
}
