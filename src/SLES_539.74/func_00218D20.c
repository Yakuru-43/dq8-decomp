// range: 0x218D20 0x218E00
#include "common.h"

M2C_UNK func_001340C0(char *, char *);
M2C_UNK func_00218E00(char *, s32, s32);
M2C_UNK func_001339E0(char *, char *, char *, char *);
M2C_UNK func_00305320(s32, u64 *, u64 *);
extern char D_003C8010[];
extern char D_003C8018[];
extern char D_003C8020[];

void func_00218D20(s32 secs, char *dst) {
    u64 quot;
    u64 rem;
    char buf60[0x40];
    char buf20[0x40];

    func_00305320(secs, &quot, &rem);
    if (quot < 100) {
        if (10 <= quot) {
            func_001340C0(buf20, D_003C8010);
            func_00218E00(buf20 + 1, (s32)quot, 0);
        } else {
            func_001340C0(buf20, D_003C8018);
            func_00218E00(buf20 + 2, (s32)quot, 0);
        }
    } else {
        func_00218E00(buf20, (s32)quot, 0);
    }
    func_00218E00(buf60, (s32)rem, 2);
    func_001339E0(dst, D_003C8020, buf20, buf60);
}
