// range: 0x46BEC0 0x46C010
#include "common.h"

typedef struct {
    s8 unk0;
    u8 pad1[3];
    s16 unk4;
    s8 unk6;
    u8 pad7;
} S_Entry;

typedef struct {
    s16 unk0;
    u16 pad2;
    void *unk4;
    s16 unk8;
    u8 padA;
    s8 unkB;
} S_Record;

void *func_2AEB40(s32);
void func_0046C010(void *, void *, s32);
s32 func_2E6770(void *, s32);

s32 func_0046BEC0(S_Record *out, S_Entry **entries, s32 count, void *ctx) {
    s32 n;
    s32 j;
    void *found;
    s32 good;
    s32 i;

    n = 0;
    for (j = 0; j < count; j++) {
        found = func_2AEB40(entries[j]->unk4);
        if (entries[j]->unk6 == 8) {
            found = func_2AEB40(0x827);
        }
        if (found != 0) {
            func_0046C010(ctx, found, 1);
            good = 0;
            for (i = 0; i < 5; i++) {
                if (0 < func_2E6770(ctx, i)) {
                    good++;
                }
            }
            out[n].unk0 = entries[j]->unk4;
            out[n].unkB = entries[j]->unk0;
            out[n].unk4 = found;
            out[n].unk8 = good;
            n++;
        }
    }
    return n;
}
