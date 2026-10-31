// range: 0x2DD0C0 0x2DD150
#include "common.h"

struct ChunkEntry {
    s16 tag;
    s16 data[13];
}; /* 0x1C bytes */

void func_002DD150(s32, s32, struct ChunkEntry *, s32, f32, f32); /* extern */

s32 func_002DD0C0(s32 arg0, s32 arg1, void *arg2, s32 arg3, f32 arg4,
                  f32 arg5) {
    struct ChunkEntry *entry = M2C_FIELD(arg2, struct ChunkEntry **, 0x2C);

    while (entry->tag != -0x270F) {
        func_002DD150(arg0, arg1, entry, arg3, arg4, arg5);
        entry++;
    }
    return 0;
}
