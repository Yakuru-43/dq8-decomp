// best attempt: try_match CLASS structural score=48 (46 words differ, 236 vs 244 bytes)
// range: 0x253980 0x253A80
#include "common.h"

extern s32 func_0016B7E0(char *, s32, s32);
extern s32 func_00133F78(s32, s32);
extern char *D_003E0C14;
extern s8 D_003E0C18;

static inline s32 pool_count(void) {
    if (D_003E0C14 == NULL) {
        return 0;
    }
    return D_003E0C18;
}

char *func_00253980(char *arg0, s32 arg1) {
    s32 i;
    char *entry;
    char *node;
    char *hit;

    for (i = 0; i < pool_count(); i++) {
        entry = NULL;
        if (D_003E0C14 != NULL) {
            if (i >= 0) {
                if (i < pool_count()) {
                    entry = (char *)D_003E0C14 + i * 0xE0;
                }
            }
        }
        if (entry != NULL) {
            if (func_0016B7E0(arg0, 2, *(s32 *)(entry + 0x58)) != 0) {
                node = *(char **)(entry + 0xAC);
                while (node != NULL) {
                    hit = node + 0x10;
                    if (func_00133F78(*(s32 *)(node + 0x7A0), arg1) == 0) {
                        return hit;
                    }
                    node = *(char **)node;
                }
            }
        }
    }
    return NULL;
}
