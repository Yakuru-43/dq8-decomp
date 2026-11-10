// Best attempt for func_00271090 (score 7, NOT matched — do not move to src/)
// range: 0x271090 0x2710B0
#include "common.h"

struct EntryKey {
    u16 index;
    u16 key;
};

extern s32 func_00271000(void *obj, struct EntryKey id, s32 flags, s32 arg3,
                         struct EntryKey extra);

s32 func_00271090(void *obj, struct EntryKey id, s32 flags, s32 arg3) {
    return func_00271000(obj, id, 0x14, arg3, id);
}
