// range: 0x256AA0 0x256B50
// BEST DRAFT (score 1, not a match) — see notes/needs-claude/func_00256AA0.md
#include "common.h"

typedef struct NameEntry {
    s32 pad00;
    char *name;               /* 0x04 */
    char pad08[0x18];
} NameEntry;

extern NameEntry *D_003E0BD0;
extern u16 D_003E0BD4;

s32 func_00133F78(char *, char *);

NameEntry *func_00256AA0(char *name) {
    NameEntry *entry;
    s32 i;

    if (name == 0) {
        return 0;
    }
    entry = D_003E0BD0;
    if (entry != 0) {
        i = 0;
        while (i < (s32)D_003E0BD4) {
            if (entry->name[0] == name[0] && entry->name[2] == name[2] &&
                func_00133F78(entry->name, name) == 0) {
                return entry;
            }
            i++;
            entry++;
        }
    }
    return 0;
}
